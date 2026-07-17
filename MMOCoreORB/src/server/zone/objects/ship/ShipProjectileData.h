//
// Created by vagrant on 8/23/17.
//

#pragma once

#include "engine/engine.h"
#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class ShipProjectileData : public Object {
protected:
	String name;
	int index;
	float range;
	float squaredRange;
	float speed;
	bool usesAmmo;
	bool missile;
	bool countermeasure;
	bool mining;
	bool tractor;
public:
	ShipProjectileData();

	void readObject(DataTableRow *row);

	String getName() const;

	int getIndex() const;

	bool isTractorBeam() const;

	bool isMiningLaser() const;

	bool isCountermeasure() const;

	bool isMissile() const;

	bool consumesAmmo() const;

	float getSpeed() const;

	float getRange() const;

	float getSquaredRange() const;
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
