#include "MeditateCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/player/events/MeditateTask.h"

MeditateCommand::MeditateCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int MeditateCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature)) {
		creature->sendSystemMessage("@teraskasi:med_fail");
		return INVALIDSTATE;
	}

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	if (creature->isInCombat()) {
		creature->sendSystemMessage("@jedi_spam:not_while_in_combat");
		return GENERALERROR;
	}

	// Meditate
	CreatureObject* player = cast<CreatureObject*>(creature);

	Reference<Task*> task = player->getPendingTask("meditate");

	if (task != nullptr) {
		player->sendSystemMessage("@jedi_spam:already_in_meditative_state");
		return GENERALERROR;
	}

	// Meditate Task
	Reference<MeditateTask*> meditateTask = new MeditateTask(player);
	meditateTask->setMoodString(player->getMoodString());
	player->sendSystemMessage("@teraskasi:med_begin");

	player->setMeditateState();

	player->addPendingTask("meditate", meditateTask, 3500);

	PlayerManager* playermgr = server->getZoneServer()->getPlayerManager();
	player->registerObserver(ObserverEventType::POSTURECHANGED, playermgr);

	return SUCCESS;
}