/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage3.h"
#include "server/zone/objects/installation/InstallationObject.h"

namespace server {
namespace zone {
namespace packets {
namespace installation {

class InstallationObjectMessage3 : public TangibleObjectMessage3 {
public:
	InstallationObjectMessage3(InstallationObject* inso);
};

} // namespace installation
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::installation;
