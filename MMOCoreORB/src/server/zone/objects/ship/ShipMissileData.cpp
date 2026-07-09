#include "ShipMissileData.h"

ShipMissileData::ShipMissileData() : Object() {
	missileType = -1;

	minTime = 0;
	maxTime = 0;

	serverSpeed = 0;
	clientSpeed = 0;
	countermeasureFactor = 0.f;
	targetAquisitionTime = 0;
	targetAquisitionAngle = 0;

	counterDifficulty = 0;
}

void ShipMissileData::readObject(DataTableRow* row) {
	if (row == nullptr || row->getCellsSize() < 15) {
		return;
	}

	row->getCell(0)->getValue(missileType);
	row->getCell(1)->getValue(dataName);
	row->getCell(2)->getValue(maxTime);
	row->getCell(3)->getValue(minTime);
	row->getCell(4)->getValue(serverSpeed);
	row->getCell(5)->getValue(clientSpeed);
	row->getCell(6)->getValue(countermeasureFactor);
	row->getCell(7)->getValue(targetAquisitionTime);
	row->getCell(8)->getValue(targetAquisitionAngle);
	row->getCell(9)->getValue(appearance);
	row->getCell(10)->getValue(trail);
	row->getCell(11)->getValue(fireEffect);
	row->getCell(12)->getValue(hitEffect);
	row->getCell(13)->getValue(counterEffect);
	row->getCell(14)->getValue(counterDifficulty);
}

// set
void ShipMissileData::setMissileType(int value) {
	missileType = value;
}

void ShipMissileData::setDataName(const String& value) {
	dataName = value;
}

void ShipMissileData::setMinTime(int value) {
	minTime = value;
}

void ShipMissileData::setMaxTime(int value) {
	maxTime = value;
}

void ShipMissileData::setServerSpeed(int value) {
	serverSpeed = value;
}

void ShipMissileData::setClientSpeed(int value) {
	clientSpeed = value;
}

void ShipMissileData::setCountermeasureFactor(float value) {
	countermeasureFactor = value;
}

void ShipMissileData::setTargetAquisitionTime(int value) {
	targetAquisitionTime = value;
}

void ShipMissileData::setTargetAquisitionAngle(int value) {
	targetAquisitionAngle = value;
}

void ShipMissileData::setAppearance(const String& value) {
	appearance = value;
}

void ShipMissileData::setTrail(const String& value) {
	trail = value;
}

void ShipMissileData::setFireEffect(const String& value) {
	fireEffect = value;
}

void ShipMissileData::setHitEffect(const String& value) {
	hitEffect = value;
}

void ShipMissileData::setCounterEffect(const String& value) {
	counterEffect = value;
}

void ShipMissileData::setCounterDifficulty(int value) {
	counterDifficulty = value;
}

// get
int ShipMissileData::getMissileType() const {
	return missileType;
}

const String& ShipMissileData::getDataName() const {
	return dataName;
}

float ShipMissileData::getMinTime() const {
	return minTime;
}

float ShipMissileData::getMaxTime() const {
	return maxTime;
}

float ShipMissileData::getServerSpeed() const {
	return serverSpeed;
}

float ShipMissileData::getClientSpeed() const {
	return clientSpeed;
}

float ShipMissileData::getCountermeasureFactor() const {
	return countermeasureFactor;
}

float ShipMissileData::getTargetAquisitionTime() const {
	return targetAquisitionTime;
}

float ShipMissileData::getTargetAquisitionAngle() const {
	return targetAquisitionAngle;
}

const String& ShipMissileData::getAppearance() const {
	return appearance;
}

const String& ShipMissileData::getTrail() const {
	return trail;
}

const String& ShipMissileData::getFireEffect() const {
	return fireEffect;
}

const String& ShipMissileData::getHitEffect() const {
	return hitEffect;
}

const String& ShipMissileData::getCounterEffect() const {
	return counterEffect;
}

int ShipMissileData::getCounterDifficulty() const {
	return counterDifficulty;
}

int ShipMissileData::getLauncherAmmoType(const String& dataName) {
	switch (dataName.hashCode()) {
		case String::hashCode("wpn_launcher_concussion_mk1"):
			return PlayerMissileType::CONCUSSION_MK1;
		case String::hashCode("wpn_launcher_concussion_mk2"):
			return PlayerMissileType::CONCUSSION_MK2;
		case String::hashCode("wpn_launcher_concussion_mk3"):
			return PlayerMissileType::CONCUSSION_MK3;
		case String::hashCode("wpn_launcher_imagerec_mk1"):
			return PlayerMissileType::IMAGEREC_MK1;
		case String::hashCode("wpn_launcher_imagerec_mk2"):
			return PlayerMissileType::IMAGEREC_MK2;
		case String::hashCode("wpn_launcher_proton_mk1"):
			return PlayerMissileType::PROTON_MK1;
		case String::hashCode("wpn_launcher_proton_mk2"):
			return PlayerMissileType::PROTON_MK2;
		case String::hashCode("wpn_launcher_proton_mk3"):
			return PlayerMissileType::PROTON_MK3;
		case String::hashCode("wpn_launcher_proton_mk4"):
			return PlayerMissileType::PROTON_MK4;
		case String::hashCode("wpn_launcher_seismic_mk1"):
			return PlayerMissileType::SEISMIC_MK1;
		case String::hashCode("wpn_launcher_seismic_mk2"):
			return PlayerMissileType::SEISMIC_MK2;
		case String::hashCode("wpn_launcher_seismic_mk3"):
			return PlayerMissileType::SEISMIC_MK3;
		case String::hashCode("wpn_launcher_spacebomb_mk1"):
			return PlayerMissileType::SPACEBOMB_MK1;
		case String::hashCode("wpn_launcher_spacebomb_mk2"):
			return PlayerMissileType::SPACEBOMB_MK2;
		default:
			return -1;
	}
}

int ShipMissileData::getMissileAmmoType(uint32 objectCRC) {
	switch (objectCRC) {
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_concussion_missile_mk1.iff"):
			return PlayerMissileType::CONCUSSION_MK1;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_concussion_missile_mk2.iff"):
			return PlayerMissileType::CONCUSSION_MK2;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_concussion_missile_mk3.iff"):
			return PlayerMissileType::CONCUSSION_MK3;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_imagerec_missile_mk1.iff"):
			return PlayerMissileType::IMAGEREC_MK1;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_imagerec_missile_mk2.iff"):
			return PlayerMissileType::IMAGEREC_MK2;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_proton_missile_mk1.iff"):
			return PlayerMissileType::PROTON_MK1;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_proton_missile_mk2.iff"):
			return PlayerMissileType::PROTON_MK2;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_proton_missile_mk3.iff"):
			return PlayerMissileType::PROTON_MK3;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_proton_missile_mk4.iff"):
			return PlayerMissileType::PROTON_MK4;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_seismic_missile_mk1.iff"):
			return PlayerMissileType::SEISMIC_MK1;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_seismic_missile_mk2.iff"):
			return PlayerMissileType::SEISMIC_MK2;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_seismic_missile_mk3.iff"):
			return PlayerMissileType::SEISMIC_MK3;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_spacebomb_missile_mk1.iff"):
			return PlayerMissileType::SPACEBOMB_MK1;
		case String::hashCode("object/tangible/ship/crafted/weapon/missile/wpn_spacebomb_missile_mk2.iff"):
			return PlayerMissileType::SPACEBOMB_MK2;
		default:
			return -1;
	}
}