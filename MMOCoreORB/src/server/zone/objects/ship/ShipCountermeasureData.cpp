#include "ShipCountermeasureData.h"

ShipCountermeasureData::ShipCountermeasureData() : Object() {
	countermeasureType = 0;
	minCount = 0;
	maxCount = 0;
	minSpeed = 0.f;
	maxSpeed = 0.f;
	scatterAngle = 0.f;
}

void ShipCountermeasureData::readObject(DataTableRow* row) {
	if (row == nullptr || row->getCellsSize() < 7) {
		return;
	}

	row->getCell(0)->getValue(countermeasureType);
	row->getCell(1)->getValue(appearance);
	row->getCell(2)->getValue(minCount);
	row->getCell(3)->getValue(maxCount);
	row->getCell(4)->getValue(minSpeed);
	row->getCell(5)->getValue(maxSpeed);
	row->getCell(6)->getValue(scatterAngle);
}

// set
void ShipCountermeasureData::setCountermeasureType(int value) {
	countermeasureType = value;
}

void ShipCountermeasureData::setAppearance(const String& value) {
	appearance = value;
}

void ShipCountermeasureData::setMinCount(int value) {
	minCount = value;
}

void ShipCountermeasureData::setMaxCount(int value) {
	maxCount = value;
}

void ShipCountermeasureData::setMinSpeed(int value) {
	minSpeed = value;
}

void ShipCountermeasureData::setMaxSpeed(int value) {
	maxSpeed = value;
}

void ShipCountermeasureData::setScatterAngle(int value) {
	scatterAngle = value;
}

// get
int ShipCountermeasureData::getCountermeasureType() const {
	return countermeasureType;
}

const String& ShipCountermeasureData::getAppearance() const {
	return appearance;
}

int ShipCountermeasureData::getMinCount() const {
	return minCount;
}

int ShipCountermeasureData::getMaxCount() const {
	return maxCount;
}

int ShipCountermeasureData::getMinSpeed() const {
	return minSpeed;
}

int ShipCountermeasureData::getMaxSpeed() const {
	return maxSpeed;
}

int ShipCountermeasureData::getScatterAngle() const {
	return scatterAngle;
}

int ShipCountermeasureData::getLauncherAmmoType(const String& dataName) {
	switch (dataName.hashCode()) {
		case String::hashCode("countermeasure_chaff_launcher"):
			return CountermeasureType::MK1;
		case String::hashCode("countermeasure_decoy_launcher"):
			return CountermeasureType::MK2;
		case String::hashCode("countermeasure_microchaff_launcher"):
			return CountermeasureType::MK3;
		case String::hashCode("countermeasure_confuser_launcher"):
			return CountermeasureType::MK4;
		case String::hashCode("countermeasure_em_launcher"):
			return CountermeasureType::MK5;
		default:
			return -1;
	}
}

int ShipCountermeasureData::getCountermeasureAmmoType(uint32 objectCRC) {
	switch (objectCRC) {
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/countermeasure_chaff_pack.iff"):
			return CountermeasureType::MK1;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/countermeasure_decoy_pack.iff"):
			return CountermeasureType::MK2;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/countermeasure_microchaff_pack.iff"):
			return CountermeasureType::MK3;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/countermeasure_confuser_pack.iff"):
			return CountermeasureType::MK4;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/countermeasure_em_pack.iff"):
			return CountermeasureType::MK5;
		default:
			return -1;
	}
}