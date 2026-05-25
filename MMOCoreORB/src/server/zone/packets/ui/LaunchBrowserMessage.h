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
   LaunchBrowserMessage(const String& url) : BaseMessage() {
		insertShort(0x02);
		insertInt(0x8DE7E213);  // CRC

		insertAscii(url); //url. minus the http.
   }

};
