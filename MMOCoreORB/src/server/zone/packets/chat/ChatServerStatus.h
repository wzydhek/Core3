/*
 * ChatServerStatus.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatServerStatus : public BaseMessage {
public:
	ChatServerStatus(byte flag);

};
