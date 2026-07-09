#include "DroidProgrammingChipSuiCallback.h"
#include "server/zone/managers/skill/SkillManager.h"
#include "server/zone/objects/tangible/misc/DroidProgrammingChip.h"
#include "server/zone/objects/player/PlayerObject.h"

DroidProgrammingChipSuiCallback::DroidProgrammingChipSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void DroidProgrammingChipSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isListBox() || args->size() <= 0 || cancelPressed)
		return;

	if (creature == nullptr)
		return;

	ZoneServer* server = creature->getZoneServer();

	if (server == nullptr)
		return;

	SkillManager* skillManager = server->getSkillManager();

	if (skillManager == nullptr) {
		return;
	}

	ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

	if (ghost == nullptr) {
		return;
	}

	// Get the chip
	ManagedReference<SceneObject*> obj = sui->getUsingObject().get();

	if (obj == nullptr)
		return;

	DroidProgrammingChip* droidChip = obj.castTo<DroidProgrammingChip*>();

	if (droidChip == nullptr)
		return;

	// Get the command
	int idx = Integer::valueOf(args->get(0).toString());

	Vector<String> playerDroidCommands;

	skillManager->getPlayerDroidCommands(ghost, playerDroidCommands);

	String commandName = playerDroidCommands.get(idx);
	int commandSize = skillManager->getDroidProgramSize(commandName.hashCode());

	// burn the chip
	Locker locker(droidChip, creature);
	droidChip->programChip(commandName, commandSize);
	locker.release();

	creature->sendSystemMessage("@space/space_interaction:memory_chip_burnt");
}