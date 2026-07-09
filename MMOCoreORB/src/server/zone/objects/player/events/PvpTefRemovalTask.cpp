#include "PvpTefRemovalTask.h"

PvpTefRemovalTask::PvpTefRemovalTask(CreatureObject* creo) {
	creature = creo;
}

void PvpTefRemovalTask::run() {
	ManagedReference<CreatureObject*> player = creature.get();

	if (player == nullptr)
		return;

	ManagedReference<PlayerObject*> ghost = player->getPlayerObject().get();

	if (ghost == nullptr) {
		return;
	}

	Locker locker(player);

	if (ghost->hasTef()) {
		auto gcwCrackdownTefMs = ghost->getLastGcwCrackdownCombatActionTimestamp().miliDifference();
		auto gcwTefMs = ghost->getLastGcwPvpCombatActionTimestamp().miliDifference();
		auto bhTefMs = ghost->getLastBhPvpCombatActionTimestamp().miliDifference();
		auto pvpAreaMs = ghost->getLastPvpAreaCombatActionTimestamp().miliDifference();

		auto rescheduleTime = gcwTefMs < bhTefMs ? gcwTefMs : bhTefMs;
		rescheduleTime = gcwCrackdownTefMs < rescheduleTime ? gcwCrackdownTefMs : rescheduleTime;
		rescheduleTime = pvpAreaMs < rescheduleTime ? pvpAreaMs : rescheduleTime;

		this->reschedule(llabs(rescheduleTime));
	} else {
		ghost->updateInRangeBuildingPermissions();
		ghost->setCrackdownTefTowards(0, false);
		player->clearPvpStatusBit(ObjectFlag::TEF, true);

		if (ConfigManager::instance()->useCovertOvertSystem())
			player->broadcastPvpStatusBitmask();
	}

	if (!ghost->hasBhTef())
		player->notifyObservers(ObserverEventType::BHTEFCHANGED);
}