#include "ShipProjectileData.h"

ShipProjectileData::ShipProjectileData() {
}

void ShipProjectileData::readObject(DataTableRow *row) {
	int temp;
	row->getCell(0)->getValue(name);
	row->getCell(1)->getValue(index);
	row->getCell(2)->getValue(range);
	squaredRange = range * range;
	row->getCell(3)->getValue(speed);
	row->getCell(4)->getValue(usesAmmo);
	row->getCell(5)->getValue(missile);
	row->getCell(6)->getValue(countermeasure);
	row->getCell(7)->getValue(mining);
	row->getCell(8)->getValue(tractor);
	// StringBuffer buffer;
	// buffer << "Loaded Projectile- Speed: " << speed << endl;
	// static Logger logger;
	// logger.info(buffer.toString(), true);
}

String ShipProjectileData::getName() const {
	return name;
}

int ShipProjectileData::getIndex() const {
	return index;
}

bool ShipProjectileData::isTractorBeam() const {
	return tractor;
}

bool ShipProjectileData::isMiningLaser() const {
	return mining;
}

bool ShipProjectileData::isCountermeasure() const {
	return countermeasure;
}

bool ShipProjectileData::isMissile() const {
	return missile;
}

bool ShipProjectileData::consumesAmmo() const {
	return usesAmmo;
}

float ShipProjectileData::getSpeed() const {
	return speed;
}

float ShipProjectileData::getRange() const {
	return range;
}

float ShipProjectileData::getSquaredRange() const {
	return squaredRange;
}