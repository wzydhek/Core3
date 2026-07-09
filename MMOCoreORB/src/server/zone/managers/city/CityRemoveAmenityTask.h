
#pragma once

#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/objects/scene/SceneObject.h"

class CityRemoveAmenityTask : public Task {
	ManagedReference<SceneObject*> amenity;
	ManagedReference<CityRegion*> city;

public:
	CityRemoveAmenityTask(SceneObject* sceno, CityRegion* cityRegion);

	void run();
};
