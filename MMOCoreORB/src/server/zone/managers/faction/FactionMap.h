/*
 * FactionMap.h
 *
 *  Created on: Mar 17, 2011
 *      Author: crush
 */

#pragma once

#include "Faction.h"

namespace server {
namespace zone {
namespace managers {
namespace faction {

class FactionMap : public VectorMap<String, Faction> {
public:
	FactionMap();

	void addFaction(const Faction& faction);

	Faction* getFaction(const String& factionName);
};

} // namespace faction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::faction;
