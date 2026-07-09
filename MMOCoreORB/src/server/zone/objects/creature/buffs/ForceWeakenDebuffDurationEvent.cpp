#include "ForceWeakenDebuffDurationEvent.h"

ForceWeakenDebuffDurationEvent::ForceWeakenDebuffDurationEvent(CreatureObject* creature, Buff* buff) : Task((int64)buff->getBuffDuration() * 1000) {
	creatureObject = creature;
	buffObject = buff;
}

void ForceWeakenDebuffDurationEvent::run() {
	ManagedReference<CreatureObject*> creature = creatureObject.get();
	ManagedReference<Buff*> buff = buffObject.get();

	if (creature == nullptr || buff == nullptr)
		return;

	Locker locker(creature);
	Locker clocker(buff, creature);

	buff->activate(false);
}

void ForceWeakenDebuffDurationEvent::setBuffObject(Buff* buff) {
	buffObject = buff;
}