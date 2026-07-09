//
// Created by g on 1/1/18.
//

#pragma once

#include "engine/service/proto/BaseMessage.h"

class DestroyShipMessage : public BaseMessage {
public:
	DestroyShipMessage(uint64 objectID, float scale);
};
