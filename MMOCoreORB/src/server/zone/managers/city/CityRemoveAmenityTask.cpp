#include "CityRemoveAmenityTask.h"

CityRemoveAmenityTask::CityRemoveAmenityTask(SceneObject* sceno, CityRegion* cityRegion) {
	amenity = sceno;
	city = cityRegion;
}

void CityRemoveAmenityTask::run() {
	if (city == nullptr || amenity == nullptr)
		return;

	Locker locker(city);
	Locker clocker(amenity, city);

	if (amenity->isMissionTerminal())
		city->removeMissionTerminal(amenity);
	else
		city->removeSkillTrainers(amenity);

	amenity->destroyObjectFromWorld(true);
	amenity->destroyObjectFromDatabase(true);
}