#pragma once

#include "templates/creature/SharedCreatureObjectTemplate.h"

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
