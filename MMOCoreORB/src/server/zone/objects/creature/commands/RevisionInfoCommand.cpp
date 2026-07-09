#include "RevisionInfoCommand.h"
#include "conf/ConfigManager.h"

int RevisionInfoCommand::executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments) {
	if (!creature->isPlayerCreature())
		return 1;

	ManagedReference<CreatureObject*> player = cast<CreatureObject*>(creature);
	ConfigManager* configManager = ConfigManager::instance();

	player->sendSystemMessage("Server Information");
	player->sendSystemMessage(configManager->getRevision());

	return 0;
}