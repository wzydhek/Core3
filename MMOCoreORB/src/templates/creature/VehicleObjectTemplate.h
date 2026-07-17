#pragma once

#include "templates/creature/SharedCreatureObjectTemplate.h"

namespace templates {
namespace creature {

class VehicleObjectTemplate : public SharedCreatureObjectTemplate {
	int decayRate, decayCycle;

public:
	VehicleObjectTemplate();

	~VehicleObjectTemplate();

	void readObject(LuaObject* templateData);

	bool isVehicleObjectTemplate();

	int getDecayRate();

	int getDecayCycle();

};

} // namespace creature
} // namespace templates

using namespace templates::creature;
