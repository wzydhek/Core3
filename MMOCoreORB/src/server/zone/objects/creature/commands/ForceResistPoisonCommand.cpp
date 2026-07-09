#include "ForceResistPoisonCommand.h"

ForceResistPoisonCommand::ForceResistPoisonCommand(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_RESIST_POISON;

	skillMods.put("resistance_poison", 25);
	skillMods.put("absorption_poison", 25);
}

int ForceResistPoisonCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}