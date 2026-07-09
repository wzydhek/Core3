/*
 * CreateTicketResponseMessage.h
 *
 *  Created on: Nov 22, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class CreateTicketResponseMessage : public BaseMessage {
public:
	CreateTicketResponseMessage(int unknown = 0);
};
