#include "ForceAbsorb1Command.h"
#include "server/zone/objects/player/PlayerObject.h"

ForceAbsorb1Command::ForceAbsorb1Command(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_FORCE_ABSORB_1;
	blockingCRCs.add(BuffCRC::JEDI_FORCE_ABSORB_2);
	singleUseEventTypes.add(ObserverEventType::FORCEABSORB);

	// Skill mods.
	skillMods.put("force_absorb", 1);
}

int ForceAbsorb1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}

void ForceAbsorb1Command::handleBuff(SceneObject* creature, ManagedObject* object, int64 param) const {
	ManagedReference<CreatureObject*> player = creature->asCreatureObject();

	if (player == nullptr) {
		return;
	}

	ManagedReference<PlayerObject*> ghost = player->getPlayerObject();

	if (ghost == nullptr) {
		return;
	}

	// Client Effect upon hit (needed)
	player->playEffect("clienteffect/pl_force_absorb_hit.cef", "");

	ghost->setForcePower(ghost->getForcePower() + param);
}