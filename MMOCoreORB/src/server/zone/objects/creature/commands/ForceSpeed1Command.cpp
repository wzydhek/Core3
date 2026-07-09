#include "ForceSpeed1Command.h"

ForceSpeed1Command::ForceSpeed1Command(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_FORCE_SPEED_1;

	blockingCRCs.add(BuffCRC::JEDI_FORCE_SPEED_2);

	skillMods.put("combat_haste", 15);
}

int ForceSpeed1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}