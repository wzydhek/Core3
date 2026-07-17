/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace resource {

class SurveyMessage : public BaseMessage {
public:
	int listSize;
	
	SurveyMessage();
	
	void add(float loc_x, float loc_y, float percentage);
	
	void updateSize();

};

} // namespace resource
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::resource;
