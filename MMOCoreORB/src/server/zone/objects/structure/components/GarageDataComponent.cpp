#include "GarageDataComponent.h"

GarageDataComponent::GarageDataComponent() {
}

GarageDataComponent::~GarageDataComponent() {
}

bool GarageDataComponent::hasNotifiedPlayer(const uint64 oid) {
	return notifiedPlayers.contains(oid);
}

void GarageDataComponent::addNotifiedPlayer(const uint64 oid) {
	notifiedPlayers.put(oid);
}

void GarageDataComponent::removeNotifiedPlayer(const uint64 oid) {
	notifiedPlayers.drop(oid);
}