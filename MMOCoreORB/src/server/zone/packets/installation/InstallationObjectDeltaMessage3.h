/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectDeltaMessage3.h"
#include "server/zone/objects/installation/InstallationObject.h"

namespace server {
namespace zone {
namespace packets {
namespace installation {

class InstallationObjectDeltaMessage3 : public TangibleObjectDeltaMessage3 {
	InstallationObject* inso;

public:
	InstallationObjectDeltaMessage3(InstallationObject* ins);

	void updateOperating(bool value);
};

} // namespace installation
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::installation;
