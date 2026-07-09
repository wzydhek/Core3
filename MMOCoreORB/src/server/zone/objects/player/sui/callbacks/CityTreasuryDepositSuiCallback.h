/*
 * CityTreasuryDepositSuiCallback.h
 *
 *  Created on: Feb 13, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/region/CityRegion.h"

class CityTreasuryDepositSuiCallback : public SuiCallback {
	ManagedWeakReference<CityRegion*> cityRegion;

public:
	CityTreasuryDepositSuiCallback(ZoneServer* server, CityRegion* region);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
