#include "CombatAction.h"

CombatAction::CombatAction(CreatureObject* attacker, TangibleObject* defender, uint32 animcrc, uint8 hit, uint8 trails, long weaponID) : StandaloneObjectControllerMessage(attacker->getObjectID(), 0x1B, 0xCC) {
	insertInt(animcrc);

	insertLong(attacker->getObjectID());
	if (weaponID == 0)
		insertLong(attacker->getWeaponID());
	else
		insertLong(weaponID);

	insertByte(attacker->getPosture());
	insertByte(trails);
	insertByte(0x00);

	defenderSize = 1;

	insertShort(1);
	insertLong(defender->getObjectID());
	insertByte((defender->isCreatureObject() ? defender->asCreatureObject()->getPosture() : 0x00));
	insertByte(hit);
	insertByte(0);
}

CombatAction::CombatAction(CreatureObject* attacker, uint32 animcrc) : StandaloneObjectControllerMessage(attacker->getObjectID(), 0x1B, 0xCC) {
	insertInt(animcrc);

	insertLong(attacker->getObjectID());
	insertLong(attacker->getWeaponID());

	insertByte(attacker->getPosture());
	insertByte(0x01);
	insertByte(0x00);

	defenderSize = 0;
	insertShort(0); // number of defenders
}

CombatAction::CombatAction(CreatureObject* attacker, uint32 animcrc, long weaponID) : StandaloneObjectControllerMessage(attacker->getObjectID(), 0x1B, 0xCC) {
	insertInt(animcrc);

	insertLong(attacker->getObjectID());
	insertLong(weaponID);

	insertByte(attacker->getPosture());
	insertByte(0xFF);
	insertByte(0xFF);

	defenderSize = 0;
	insertShort(0); // number of defenders
}

CombatAction::CombatAction(TangibleObject* attacker, CreatureObject* defender, uint32 animcrc, uint8 hit, long wpnID) : StandaloneObjectControllerMessage(attacker->getObjectID(), 0x1B, 0xCC) {
	insertInt(animcrc);

	insertLong(attacker->getObjectID());
	insertLong(wpnID);

	insertByte(0x0);
	insertByte(0xFF);
	insertByte(0xFF);

	defenderSize = 1;

	insertShort(1);
	insertLong(defender->getObjectID());
	insertByte(defender->getPosture());
	insertByte(hit);
	insertByte(0);
}

CombatAction::CombatAction(CreatureObject* attacker, CreatureObject* defender, uint32 animcrc, uint8 hit, long wpnID) : StandaloneObjectControllerMessage(attacker->getObjectID(), 0x1B, 0xCC) {
	insertInt(animcrc);

	insertLong(attacker->getObjectID());
	insertLong(wpnID);

	insertByte(attacker->getPosture());
	insertByte(0xFF);
	insertByte(0xFF);

	defenderSize = 1;

	insertShort(1);
	insertLong(defender->getObjectID());
	insertByte(defender->getPosture());
	insertByte(hit);
	insertByte(0);
}

CombatAction::CombatAction(TangibleObject* attacker, SortedVector<DefenderHitList*> targetDefenders, uint32 animcrc, uint8 trails, long weaponID) : StandaloneObjectControllerMessage(attacker->getObjectID(), 0x1B, 0xCC, true) {
	insertInt(animcrc);
	insertLong(attacker->getObjectID());
	if (weaponID == 0) {
		insertLong((attacker->isCreatureObject() ? attacker->asCreatureObject()->getWeaponID() : 0));
	} else {
		insertLong(weaponID);
	}
	insertByte((attacker->isCreatureObject() ? attacker->asCreatureObject()->getPosture() : 0x00));
	insertByte(trails);
	insertByte(0);

	defenderSize = targetDefenders.size();

	for (int i = 0; i < targetDefenders.size(); i++) {
		DefenderHitList* hitList = targetDefenders.get(i);

		if (hitList == nullptr) {
			continue;
		}

		TangibleObject* defender = hitList->getDefender();

		if (defender == nullptr) {
			continue;
		}

		insertShort(i + 1);
		insertLong(defender->getObjectID());
		insertByte((defender->isCreatureObject() ? defender->asCreatureObject()->getPosture() : 0x00));
		insertByte(hitList->getHit());
		insertByte(0); // clientEffectID
		insertByte(hitList->getHitLocation());
		insertByte(hitList->getInitialDamage());

		if (i == 19) {
			return;
		}
	}
}

void CombatAction::updateDefenderSize() {
	insertShort(53, ++defenderSize);
}

void CombatAction::addDefender(CreatureObject* defender, uint8 hit) {
	insertLong(defender->getObjectID());
	insertByte(defender->getPosture());
	insertByte(hit);
	insertByte(0);

	updateDefenderSize();
}