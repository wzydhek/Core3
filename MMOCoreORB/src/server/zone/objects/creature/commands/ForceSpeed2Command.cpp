#include "ForceSpeed2Command.h"

ForceSpeed2Command::ForceSpeed2Command(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_FORCE_SPEED_2;

	overrideableCRCs.add(BuffCRC::JEDI_FORCE_SPEED_1);

	skillMods.put("combat_haste", 25);
}

int ForceSpeed2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}