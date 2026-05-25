/*
 * CloseHolocronMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class CloseHolocronMessage : public BaseMessage {
public:
   CloseHolocronMessage() : BaseMessage() {
		insertShort(0x01);
		insertInt(0xC0938A9D);  // CRC

		//Closes the Holocron Screen.
   }

};
