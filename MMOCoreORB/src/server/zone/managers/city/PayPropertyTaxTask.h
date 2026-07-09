/*
 * PayCityTaxTask.h
 *
 *  Created on: Jul 30, 2013
 *      Author: swgemu
 */

#pragma once

#include "server/zone/objects/region/CityRegion.h"

class PayPropertyTaxTask : public Task {
	ManagedWeakReference<CityRegion*> cityObject;
	float amount;
public:
	PayPropertyTaxTask(CityRegion* city, float tax);

	void run();
};
