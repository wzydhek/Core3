/*
 * RepairVehicleSuiCallback.h
 *
 *  Created on: Dec 6, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/VehicleObject.h"
#include "server/zone/objects/transaction/TransactionLog.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace sui {

class RepairVehicleSuiCallback : public SuiCallback {
public:
	RepairVehicleSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::sui;
