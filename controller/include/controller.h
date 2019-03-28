#pragma once

#include "homehub.h"
#include "pubsub.h"
#include <thread>
#include "discovery_manager.h"
#include "work_manager.h"

using namespace std;

namespace Controller
{

	class Ctrlr : public PubSubCb
	{
	private:
		friend class Worker;

		Ctrlr() {
			m_discovery_manager.addCb(this);
			m_work_manager.addCb(this);
		}

		~Ctrlr() {
			stop();
			m_discovery_manager.removeCb(this);
			m_work_manager.removeCb(this);
		}

	public:
		static Ctrlr* getInstance() {
			static Ctrlr* instance = NULL;

			if (instance == NULL)
				instance = new Ctrlr();

			return instance;
		}

		void start();
		void stop();
		
	private:
		void onMessage(const string& message);
		void* subscribeToEvent(string &event);

	private:
		bool m_started;
		DiscoveryManager m_discovery_manager;
		WorkManager m_work_manager;
	};
}
