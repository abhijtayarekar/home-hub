/*
 * pubsub_common.h
 *
 *  Created on: Jul 8, 2015
 *      Author: abhijit
 */

#ifndef INCLUDE_PUBSUB_COMMON_H_
#define INCLUDE_PUBSUB_COMMON_H_

#include <json/json.h>

typedef enum {
	PUBSUB_RET_OK,
	PUBSUB_RET_ERR,
}pubsub_ret_t;

typedef enum {
	PUBSUB_IMPL_PUBNUB
}pubsub_impl_t;

typedef struct {
	void (*on_publish)(char* p_channel, json_object *p_msg);
	void (*on_message)(char* p_channel, json_object *p_msg);
}pubsub_callback_t;

#endif /* INCLUDE_PUBSUB_COMMON_H_ */
