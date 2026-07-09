#include "ShipTurretData.h"

ShipTurretData::ShipTurretData() {
	weaponIndex = 0;
	minYaw = 0.f;
	maxYaw = 0.f;
	minPitch = 0.f;
	maxPitch = 0.f;
}

void ShipTurretData::readObject(DataTableRow* row) {
	if (row == nullptr || row->getCellsSize() < 6) {
		return;
	}

	row->getCell(0)->getValue(chassisName);
	row->getCell(1)->getValue(weaponIndex);
	row->getCell(2)->getValue(minYaw);
	row->getCell(3)->getValue(maxYaw);
	row->getCell(4)->getValue(minPitch);
	row->getCell(5)->getValue(maxPitch);
}

void ShipTurretData::readObject(LuaObject* row) {
	if (row == nullptr || row->getTableSize() < 6) {
		Logger log("ShipTurretData");
		log.info(true) << "!row " << row->getTableSize();
	}

	chassisName = row->getStringAt(1);
	weaponIndex = row->getIntAt(2);
	minYaw = row->getFloatAt(3);
	maxYaw = row->getFloatAt(4);
	minPitch = row->getFloatAt(5);
	maxPitch = row->getFloatAt(6);
}

const String& ShipTurretData::getChassisName() const {
	return chassisName;
}

int ShipTurretData::getWeaponIndex() const {
	return weaponIndex;
}

float ShipTurretData::getMinYaw() const {
	return minYaw;
}

float ShipTurretData::getMaxYaw() const {
	return maxYaw;
}

float ShipTurretData::getMinPitch() const {
	return minPitch;
}

float ShipTurretData::getMaxPitch() const {
	return maxPitch;
}

void ShipTurretData::setChassisName(const String& name) {
	chassisName = name;
}

void ShipTurretData::setWeaponIndex(int index) {
	weaponIndex = index;
}

void ShipTurretData::setMinYaw(float minY) {
	minYaw = minY;
}

void ShipTurretData::setMaxYaw(float maxY) {
	maxYaw = maxY;
}

void ShipTurretData::setMinPitch(float minP) {
	minPitch = minP;
}

void ShipTurretData::setMaxPitch(float maxP) {
	maxPitch = maxP;
}