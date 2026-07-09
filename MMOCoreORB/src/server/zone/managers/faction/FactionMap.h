/*
 * FactionMap.h
 *
 *  Created on: Mar 17, 2011
 *      Author: crush
 */

#pragma once

#include "Faction.h"

class FactionMap : public VectorMap<String, Faction> {
public:
	FactionMap();

	void addFaction(const Faction& faction);

	Faction* getFaction(const String& factionName);
};
