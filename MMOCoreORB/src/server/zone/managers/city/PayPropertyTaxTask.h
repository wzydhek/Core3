/*
 * PayCityTaxTask.h
 *
 *  Created on: Jul 30, 2013
 *      Author: swgemu
 */

#pragma once

#include "server/zone/objects/region/CityRegion.h"

namespace server {
namespace zone {
namespace managers {
namespace city {

class PayPropertyTaxTask : public Task {
	ManagedWeakReference<CityRegion*> cityObject;
	float amount;
public:
	PayPropertyTaxTask(CityRegion* city, float tax);

	void run();
};

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;
