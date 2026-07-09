/*
 * ExecuteConsoleCommand.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ExecuteConsoleCommand : public BaseMessage {
public:
	ExecuteConsoleCommand(const String& com);

};
