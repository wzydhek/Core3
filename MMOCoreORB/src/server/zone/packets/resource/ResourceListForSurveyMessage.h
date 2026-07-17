/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace resource {

class ResourceListForSurveyMessage : public BaseMessage {
public:
	int listSize;

	ResourceListForSurveyMessage();

	void addResource(String resourceName, String resourceType, uint64 objectID);

	void finish(String resourceType, long playerID);

};

} // namespace resource
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::resource;
