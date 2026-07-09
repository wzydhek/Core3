/*
 * LaunchBrowserMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class LaunchBrowserMessage : public BaseMessage {
public:
	LaunchBrowserMessage(const String& url);

};
