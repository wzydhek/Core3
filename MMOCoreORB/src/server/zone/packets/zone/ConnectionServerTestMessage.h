/*
 * ConnectionServerMessage.h
 *
 *  Created on: Nov 25, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ConnectionServerTestMessage : public BaseMessage {
public:
   ConnectionServerTestMessage() : BaseMessage() {
		    insertShort(0x02);
	   		insertInt(0x0E20D7E9);

	   		insertAscii("ConnectionServer:1348");
   }

};
