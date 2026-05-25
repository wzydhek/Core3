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
   CreateTicketResponseMessage(int unknown = 0) : BaseMessage() {
		insertShort(0x09);
		insertInt(0x550A407A);  // CRC

		insertInt(unknown);
   }
};
