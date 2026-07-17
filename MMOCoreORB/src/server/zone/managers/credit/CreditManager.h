//
// Created by vagrant on 9/2/17.
//

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/creature/credits/CreditObject.h"

namespace server {
namespace zone {
namespace managers {
namespace credit {

class CreditManager : public Singleton<CreditManager>, public Logger, public Object {
public:
	CreditManager();
	static void addBankCredits(uint64 creatureID, int amount, bool notifyClient = true);
	static void addCashCredits(uint64 creatureID, int amount, bool notifyClient = true);
	static bool subtractBankCredits(uint64 creatureID, int amount, bool notifyClient = true);
	static bool subtractCashCredits(uint64 creatureID, int amount, bool notifyClient = true);
	static void transferCredits(uint64 creatureID, int cash, int bank, bool notifyClient = true);
	static bool verifyBankCredits(uint64 creatureID, int amount);
	static bool verifyCashCredits(uint64 creatureID, int amount);
	static Reference<CreditObject*> getCreditObject(uint64 creoID);
};

} // namespace credit
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::credit;
