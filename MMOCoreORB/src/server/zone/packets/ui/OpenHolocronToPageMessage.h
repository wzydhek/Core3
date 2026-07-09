/*
 * OpenHolocronToPageMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class OpenHolocronToPageMessage : public BaseMessage {
public:
	OpenHolocronToPageMessage(const String& page);
};
