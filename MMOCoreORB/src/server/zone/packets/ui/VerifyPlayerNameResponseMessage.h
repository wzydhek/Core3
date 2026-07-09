/*
 * VerifyPlayerNameResponseMessage.h
 *
 *  Created on: Nov 25, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class VerifyPlayerNameResponseMessage : public BaseMessage {
public:
	VerifyPlayerNameResponseMessage(bool success);

};
