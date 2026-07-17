
#pragma once

#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace managers {
namespace city {

class CityRemoveAmenityTask : public Task {
	ManagedReference<SceneObject*> amenity;
	ManagedReference<CityRegion*> city;

public:
	CityRemoveAmenityTask(SceneObject* sceno, CityRegion* cityRegion);

	void run();
};

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;
