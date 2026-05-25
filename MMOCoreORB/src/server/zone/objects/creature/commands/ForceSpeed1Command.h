/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

class ForceSpeed1Command : public JediQueueCommand {
public:

	ForceSpeed1Command(const String& name, ZoneProcessServer* server)
	: JediQueueCommand(name, server) {

		buffCRC = BuffCRC::JEDI_FORCE_SPEED_1;

		blockingCRCs.add(BuffCRC::JEDI_FORCE_SPEED_2);

		skillMods.put("combat_haste", 15);
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		return doJediSelfBuffCommand(creature);
	}

};
