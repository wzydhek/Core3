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
	IsFlattenedTheaterMessage(uint64 objectID, bool shouldFlatten);

};
