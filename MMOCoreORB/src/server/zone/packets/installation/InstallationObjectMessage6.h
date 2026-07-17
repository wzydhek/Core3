/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage6.h"
#include "server/zone/objects/installation/InstallationObject.h"

namespace server {
namespace zone {
namespace packets {
namespace installation {

class InstallationObjectMessage6 : public TangibleObjectMessage6 {
public:
	InstallationObjectMessage6(InstallationObject* inso);
};

} // namespace installation
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::installation;
