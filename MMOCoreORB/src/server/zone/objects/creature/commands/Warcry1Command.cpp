#include "Warcry1Command.h"
#include "server/chat/ChatManager.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/combat/CombatManager.h"

Warcry1Command::Warcry1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Warcry1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	Reference<TangibleObject*> targetObject = server->getZoneServer()->getObject(target).castTo<TangibleObject*>();

	if (targetObject == nullptr || !targetObject->isCreatureObject())
		return INVALIDTARGET;

	int res = doCombatAction(creature, target);

	if (res == TOOFAR)
		CombatManager::instance()->broadcastCombatSpam(creature, targetObject, nullptr, 0, "cbt_spam", "warcry_out_of_range", 0);

	if (res == SUCCESS && creature->isPlayerCreature()) {
		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

		if (ghost != nullptr && !ghost->getCommandMessageString(STRING_HASHCODE("warcry1")).isEmpty() && creature->checkCooldownRecovery("command_message")) {
			UnicodeString shout(ghost->getCommandMessageString(STRING_HASHCODE("warcry1")));
			server->getChatManager()->broadcastChatMessage(creature, shout, 0, 80, creature->getMoodID(), 0, ghost->getLanguageID());
			creature->updateCooldownTimer("command_message", 30 * 1000);
		}
	}
	return res;
}