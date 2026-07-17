/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage3.h"
#include "server/zone/objects/tangible/LairObject.h"

//class LairObject;

namespace server {
namespace zone {
namespace packets {
namespace lair {

class LairObjectMessage3 : public TangibleObjectMessage3 {
public:
	LairObjectMessage3(LairObject* tano);
};

} // namespace lair
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::lair;
