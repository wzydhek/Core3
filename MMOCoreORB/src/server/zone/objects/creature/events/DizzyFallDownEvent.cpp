#include "DizzyFallDownEvent.h"

DizzyFallDownEvent::DizzyFallDownEvent(CreatureObject* creat) : Task(200) {
	creature = creat;
}

void DizzyFallDownEvent::run() {
	Locker locker(creature);

	if (creature->isDead()) {
		creature->clearDizzyEvent();
		return;
	}

	if (creature->isDizzied()) {
		if (creature->isRidingMount()) {
			creature->updateCooldownTimer("mount_dismount", 0);
			creature->dismount();
		}

		if (!creature->isKnockedDown()) {
			creature->setPosture(CreaturePosture::KNOCKEDDOWN, true, true);
			creature->doAnimation("change_posture");
		}

		creature->sendSystemMessage("@cbt_spam:dizzy_fall_down_single");
		creature->sendStateCombatSpam("cbt_spam", "dizzy_fall_down", 11);
	}

	creature->clearDizzyEvent();
}