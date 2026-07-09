#include "CreateMissileMessage.h"

CreateMissileMessage::CreateMissileMessage(SceneObject* source, SceneObject* target, int impactTime, int missileId, int missileType, int weaponSlot, int targetSlot) : BaseMessage() {
	insertShort(0x14);
	insertInt(0x721CF08B); // CRC

	insertInt(missileId);
	insertLong(source->getObjectID());
	insertLong(target->getObjectID());

	insertFloat(source->getPositionX());
	insertFloat(source->getPositionZ());
	insertFloat(source->getPositionY());

	insertFloat(target->getPositionX());
	insertFloat(target->getPositionZ());
	insertFloat(target->getPositionY());

	insertInt(impactTime);
	insertInt(missileType);
	insertInt(weaponSlot);
	insertInt(targetSlot);
}

CreateMissileMessage::CreateMissileMessage(SceneObject* source, SceneObject* target, const Vector3& targetPosition, int impactTime, int missileId, int missileType, int weaponSlot, int targetSlot) : BaseMessage() {
	insertShort(0x14);
	insertInt(0x721CF08B); // CRC

	insertInt(missileId);
	insertLong(source->getObjectID());
	insertLong(target->getObjectID());

	insertFloat(source->getPositionX());
	insertFloat(source->getPositionZ());
	insertFloat(source->getPositionY());

	insertFloat(targetPosition.getX());
	insertFloat(targetPosition.getZ());
	insertFloat(targetPosition.getY());

	insertInt(impactTime);
	insertInt(missileType);
	insertInt(weaponSlot);
	insertInt(targetSlot);
}

CreateMissileMessage::CreateMissileMessage(ShipObject* source, ShipObject* target, const ShipMissile* missile) : BaseMessage() {
	insertShort(0x14);
	insertInt(0x721CF08B); // CRC

	insertInt(missile->getUniqueID());
	insertLong(source->getObjectID());
	insertLong(target->getObjectID());

	const Vector3& missilePosition = missile->getThisPosition();

	insertFloat(missilePosition.getX());
	insertFloat(missilePosition.getZ());
	insertFloat(missilePosition.getY());

	int timeToHit = (int)(missile->getTimeToHit() * 0.001f);
	Vector3 targetPosition = missile->getTargetPosition(target, timeToHit);

	insertFloat(targetPosition.getX());
	insertFloat(targetPosition.getZ());
	insertFloat(targetPosition.getY());

	insertInt(timeToHit);
	insertInt(missile->getProjectileType());
	insertInt(missile->getWeaponSlot());
	insertInt(missile->getComponentSlot());
}