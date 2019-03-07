/*
 ============================================================================
 Name        : controller.cpp
 Author      : Abhijit Ayarekar
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "platdep.h"
#include <iostream>
#include <chrono>
#include <iomanip>

#include "controller.h"
#include "pubsub.h"

using namespace Controller;

void Ctrlr::start() 
{
	if (!this->m_started) {
		cout<<"Controller : Starting"<<endl;
		this->m_started = true;
		m_discovery_manager.start();
		m_work_manager.start();
		cout<<"Controller Started"<<endl;
	}
}

void Ctrlr::stop() 
{
	if(this->m_started) {
		cout<<"Controller : Stopping"<<endl;
		this->m_started = false;
		m_discovery_manager.stop();
		m_work_manager.stop();
		cout<<"Controller Stopped"<<endl;
	}
}

void Ctrlr::onMessage(void* p_msg)
{

}
