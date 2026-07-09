#include "BuffDurationEvent.h"

BuffDurationEvent::BuffDurationEvent(CreatureObject* creature, Buff* buff) : Task((int64)buff->getBuffDuration() * 1000) {
	creatureObject = creature;
	buffObject = buff;
}

void BuffDurationEvent::run() {
	ManagedReference<CreatureObject*> creature = creatureObject.get();
	ManagedReference<Buff*> buff = buffObject.get();

	if (creature == nullptr || buff == nullptr)
		return;

	Locker locker(creature);
	Locker clocker(buff, creature);

	if (buff->checkRenew()) {
		creature->renewBuff(buff->getBuffCRC(), buff->getBuffDuration());
	} else {
		creature->removeBuff(buff);
	}
}

void BuffDurationEvent::setBuffObject(Buff* buff) {
	buffObject = buff;
}