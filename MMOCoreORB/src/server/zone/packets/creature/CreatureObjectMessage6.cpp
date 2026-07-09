#include "CreatureObjectMessage6.h"

CreatureObjectMessage6::CreatureObjectMessage6(const CreatureObject* creo) : TangibleObjectMessage6(creo, 0x4352454F, 0x16) {
	insertShort((uint16)creo->getLevel());
	insertAscii(creo->getPerformanceAnimation());
	insertAscii(creo->getMoodString());
	insertLong(creo->getWeaponID());
	insertLong(creo->getGroupID());
	insertLong(creo->getGroupInviterID());
	insertLong(creo->getGroupInviteCounter());
	insertInt(creo->getGuildID());
	insertLong(creo->getTargetID());
	insertByte(creo->getMoodID());
	insertInt(creo->getPerformanceStartTime()); // Doesn't appear to be used by the client
	insertInt(creo->getPerformanceType());

	const DeltaVector<int>* ham = creo->getHAM();
	ham->insertToMessage(this);

	const DeltaVector<int>* maxHam = creo->getMaxHAM();
	maxHam->insertToMessage(this);

	insertEquipmentList(creo);

	insertAscii(creo->getAlternateAppearance());

	insertByte(creo->getFrozen());

	setSize();
}

void CreatureObjectMessage6::insertEquipmentList(const CreatureObject* creo) {
	const DeltaVector<ManagedReference<TangibleObject*>>* wearables = creo->getWearablesDeltaVector();
	wearables->insertToMessage(this);
}