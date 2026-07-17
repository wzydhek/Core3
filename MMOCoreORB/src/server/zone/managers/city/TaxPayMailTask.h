/*
 * TaxNoPayMailTask.h
 *
 *  Created on: 16/11/2012
 *      Author: victor
 */

#pragma once

#include "server/chat/ChatManager.h"
#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/managers/credit/CreditManager.h"
#include "server/zone/objects/transaction/TransactionLog.h"

namespace server {
namespace zone {
namespace managers {
namespace city {

class TaxPayMailTask : public Task {
	Vector<uint64> citizens;
	String mayorName;
	ManagedReference<ChatManager*> chatManager;
	ManagedReference<CityRegion*> city;

	int incomeTax;
public:
	TaxPayMailTask(int tax, const String& mayor, ManagedReference<ChatManager*> chat, ManagedReference<CityRegion*> cityRegion);

	void run();

	void addCitizen(uint64 citizen);

};

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;
