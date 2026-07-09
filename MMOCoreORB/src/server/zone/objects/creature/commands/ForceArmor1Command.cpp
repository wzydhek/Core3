#include "ForceArmor1Command.h"
#include "server/zone/objects/player/PlayerObject.h"

ForceArmor1Command::ForceArmor1Command(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_FORCE_ARMOR_1;
	blockingCRCs.add(BuffCRC::JEDI_FORCE_ARMOR_2);
	singleUseEventTypes.add(ObserverEventType::FORCEARMOR);
	skillMods.put("force_armor", 25);
}

int ForceArmor1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}

void ForceArmor1Command::handleBuff(SceneObject* sceneObject, ManagedObject* object, int64 param) const {
	ManagedReference<CreatureObject*> player = sceneObject->asCreatureObject();

	if (player == nullptr)
		return;

	ManagedReference<PlayerObject*> ghost = player->getPlayerObject();

	if (ghost == nullptr)
		return;

	// Client Effect upon hit (needed)
	player->playEffect("clienteffect/pl_force_armor_hit.cef", "");

	int fCost = param * getFrsModifiedExtraForceCost(player, 0.5);
	if (ghost->getForcePower() <= fCost) { // Remove buff if not enough force.
		Buff* buff = player->getBuff(BuffCRC::JEDI_FORCE_ARMOR_1);
		if (buff != nullptr) {
			Locker locker(buff);

			player->removeBuff(buff);
		}
	} else {
		ghost->setForcePower(ghost->getForcePower() - fCost);
	}
}