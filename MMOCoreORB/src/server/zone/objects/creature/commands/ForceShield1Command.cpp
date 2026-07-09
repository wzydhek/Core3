#include "ForceShield1Command.h"
#include "server/zone/objects/player/PlayerObject.h"

ForceShield1Command::ForceShield1Command(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_FORCE_SHIELD_1;
	blockingCRCs.add(BuffCRC::JEDI_FORCE_SHIELD_2);
	singleUseEventTypes.add(ObserverEventType::FORCESHIELD);
	skillMods.put("force_shield", 25);
}

int ForceShield1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}

void ForceShield1Command::handleBuff(SceneObject* creature, ManagedObject* object, int64 param) const {
	ManagedReference<CreatureObject*> player = creature->asCreatureObject();

	if (player == nullptr)
		return;

	ManagedReference<PlayerObject*> ghost = player->getPlayerObject();

	if (ghost == nullptr)
		return;

	// Client Effect upon hit (needed)
	player->playEffect("clienteffect/pl_force_shield_hit.cef", "");

	int fCost = param * getFrsModifiedExtraForceCost(player, 0.5);
	if (ghost->getForcePower() <= fCost) { // Remove buff if not enough force.
		Buff* buff = player->getBuff(BuffCRC::JEDI_FORCE_SHIELD_1);
		if (buff != nullptr) {
			Locker locker(buff);

			player->removeBuff(buff);
		}
	} else {
		ghost->setForcePower(ghost->getForcePower() - fCost);
	}
}