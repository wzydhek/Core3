/*
 * IsFlattenedTheaterMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class IsFlattenedTheaterMessage : public BaseMessage {
public:
	IsFlattenedTheaterMessage(uint64 objectID, bool shouldFlatten) : BaseMessage() {
		insertShort(0x03);
		insertInt(0x4EB0B06A);  // CRC

		insertLong(objectID); //Object id of the theater
		insertByte(shouldFlatten); // Whether or not to flatten terrain
   }

};
