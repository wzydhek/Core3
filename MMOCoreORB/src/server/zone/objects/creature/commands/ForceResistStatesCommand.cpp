#include "ForceResistStatesCommand.h"

ForceResistStatesCommand::ForceResistStatesCommand(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_RESIST_STATES;

	skillMods.put("resistance_states", 25);
}

int ForceResistStatesCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}