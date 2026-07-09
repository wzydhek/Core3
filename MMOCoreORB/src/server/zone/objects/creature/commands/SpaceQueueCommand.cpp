#include "SpaceQueueCommand.h"
#include "server/zone/ZoneServer.h"

SpaceQueueCommand::SpaceQueueCommand(const String& skillname, ZoneProcessServer* serv) : QueueCommand(skillname, serv) {
}

ManagedReference<ShipObject*> SpaceQueueCommand::getPlayerShip(CreatureObject* creature) const {
	if (creature == nullptr) {
		return nullptr;
	}

	auto root = creature->getRootParent();

	if (root == nullptr || !root->isShipObject()) {
		return nullptr;
	}

	return root->asShipObject();
}

ManagedReference<ShipObject*> SpaceQueueCommand::getShipTarget(ShipObject* ship) const {
	if (ship == nullptr) {
		return nullptr;
	}

	uint64 targetID = ship->getShipTargetID();

	if (targetID == 0) {
		return nullptr;
	}

	auto zoneServer = ship->getZoneServer();

	if (zoneServer == nullptr) {
		return nullptr;
	}

	auto target = zoneServer->getObject(targetID);

	if (target == nullptr || !target->isShipObject()) {
		return nullptr;
	}

	return target->asShipObject();
}

bool SpaceQueueCommand::isInRange(ShipObject* ship, ShipObject* target, float distance) const {
	if (ship == nullptr || target == nullptr) {
		return false;
	}

	const auto& sPosition = ship->getPosition();
	const auto& tPosition = target->getPosition();

	float sRadius = ship->getBoundingRadius();
	float tRadius = target->getBoundingRadius();

	float distanceSqr = sPosition.squaredDistanceTo(tPosition) - Math::sqr(sRadius + tRadius);
	return distanceSqr <= Math::sqr(distance);
}