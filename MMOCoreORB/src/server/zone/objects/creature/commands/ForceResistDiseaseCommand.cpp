#include "ForceResistDiseaseCommand.h"

ForceResistDiseaseCommand::ForceResistDiseaseCommand(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_RESIST_DISEASE;

	skillMods.put("resistance_disease", 25);
	skillMods.put("absorption_disease", 25);
}

int ForceResistDiseaseCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}