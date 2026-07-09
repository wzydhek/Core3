#include "PayPropertyTaxTask.h"

PayPropertyTaxTask::PayPropertyTaxTask(CityRegion* city, float tax) {
	cityObject = city;
	amount = tax;
}

void PayPropertyTaxTask::run() {
	ManagedReference<CityRegion*> strongRefCity = cityObject.get();

	if (strongRefCity == nullptr)
		return;

	Locker lock(strongRefCity);
	strongRefCity->addToCityTreasury(amount);
}