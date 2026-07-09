//
// Created by g on 12/20/17.
//

#pragma once

#include "engine/service/proto/BaseMessage.h"

class HyperspaceMessage : public BaseMessage {
public:
	HyperspaceMessage(uint64 shpid, int operand);
};
