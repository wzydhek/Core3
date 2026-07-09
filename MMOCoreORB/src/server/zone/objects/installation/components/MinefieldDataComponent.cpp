#include "MinefieldDataComponent.h"

MinefieldDataComponent::MinefieldDataComponent() {
	attackSpeed = 5.f;
	maxRange = 32.f;

	templateData = nullptr;
	explodeDelay.updateToCurrentTime();

	addSerializableVariables();
}

MinefieldDataComponent::~MinefieldDataComponent() {
}

void MinefieldDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(mines);
}

void MinefieldDataComponent::initializeTransientMembers() {
	// Logger::Logger tlog("minefieldata");
	// tlog.info("initializing minefield transients",true);
	if (getParent() != nullptr) {
		templateData = dynamic_cast<SharedInstallationObjectTemplate*>(getParent()->getObjectTemplate());
		attackSpeed = 5;
	}
}

bool MinefieldDataComponent::isMinefieldData() {
	return true;
}

bool MinefieldDataComponent::canExplode() {
	return explodeDelay.isPast();
}

int MinefieldDataComponent::getCapacity() {
	return CAPACITY;
}

void MinefieldDataComponent::updateCooldown(uint64 cooldown) {
	explodeDelay.updateToCurrentTime();
	explodeDelay.addMiliTime(cooldown);
}

void MinefieldDataComponent::addMine(WeaponObject* weapon) {
	if (weapon == nullptr) {
		return;
	}

	mines.add(weapon);
}

WeaponObject* MinefieldDataComponent::getMine(int indx) {
	return mines.get(indx);
}

WeaponObject* MinefieldDataComponent::removeMine(int indx) {
	return mines.remove(indx);
}

int MinefieldDataComponent::getMineCapacity() {
	return CAPACITY;
}

int MinefieldDataComponent::getMineCount() {
	return mines.size();
}

void MinefieldDataComponent::setMaxRange(float val) {
	maxRange = val;
}

float MinefieldDataComponent::getMaxRange() {
	return maxRange;
}

bool MinefieldDataComponent::hasNotifiedPlayer(const uint64 oid) {
	return notifiedPlayers.contains(oid);
}

void MinefieldDataComponent::addNotifiedPlayer(const uint64 oid) {
	notifiedPlayers.put(oid);
}

void MinefieldDataComponent::removeNotifiedPlayer(const uint64 oid) {
	notifiedPlayers.drop(oid);
}

void MinefieldDataComponent::addSerializableVariables() {
	addSerializableVariable("mines", &mines);
}