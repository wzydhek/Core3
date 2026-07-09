#include "FieldFactionChangeSuiCallback.h"

FieldFactionChangeSuiCallback::FieldFactionChangeSuiCallback(ZoneServer* server, int status) : SuiCallback(server) {
	newStatus = status;
}

void FieldFactionChangeSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	StringTokenizer tokenizer(args->get(0).toString());

	if (cancelPressed || args->size() < 1 || !tokenizer.hasMoreTokens()) {
		player->sendSystemMessage("@gcw:abort_field_change"); // You cancel your factional change.
		return;
	}

	if (tokenizer.getStringToken().toLowerCase() != "yes") {
		player->sendSystemMessage("@gcw:abort_field_change"); // You cancel your factional change.
		return;
	}

	if (player->getFutureFactionStatus() != -1)
		return;

	int curStatus = player->getFactionStatus();

	if (curStatus == newStatus)
		return;

	if (newStatus == FactionStatus::COVERT) {
		if (curStatus == FactionStatus::OVERT) {
			player->sendSystemMessage("@gcw:cannot_change_from_combatant_in_field"); // You cannot change you status to combatant in the field. Go talk to a faction recruiter.
			return;
		}

		player->sendSystemMessage("@gcw:handle_go_covert"); // You will be flagged as a Combatant in 30 seconds.
		player->setFutureFactionStatus(FactionStatus::COVERT);

		ManagedReference<CreatureObject*> creo = player->asCreatureObject();

		Core::getTaskManager()->scheduleTask(
			[creo] {
				if (creo != nullptr) {
					Locker locker(creo);

					creo->setFactionStatus(FactionStatus::COVERT);
				}
			},
			"UpdateFactionStatusTask", 30000);
	} else if (newStatus == FactionStatus::OVERT) {
		player->sendSystemMessage("You will be flagged as Special Forces in 5 minutes."); // No string available for overt.
		player->setFutureFactionStatus(FactionStatus::OVERT);

		ManagedReference<CreatureObject*> creo = player->asCreatureObject();

		Core::getTaskManager()->scheduleTask(
			[creo] {
				if (creo != nullptr) {
					Locker locker(creo);

					creo->setFactionStatus(FactionStatus::OVERT);
				}
			},
			"UpdateFactionStatusTask", 300000);
	}
}