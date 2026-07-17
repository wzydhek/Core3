#pragma once

#include "engine/engine.h"
#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class ShipTurretData: public Object {
protected:
	String chassisName;
	int weaponIndex;
	float minYaw;
	float maxYaw;
	float minPitch;
	float maxPitch;

public:
	ShipTurretData();

	void readObject(DataTableRow* row);

	void readObject(LuaObject* row);

	const String& getChassisName() const;

	int getWeaponIndex() const;

	float getMinYaw() const;

	float getMaxYaw() const;

	float getMinPitch() const;

	float getMaxPitch() const;

	void setChassisName(const String& name);

	void setWeaponIndex(int index);

	void setMinYaw(float minY);

	void setMaxYaw(float maxY);

	void setMinPitch(float minP);

	void setMaxPitch(float maxP);
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
