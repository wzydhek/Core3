#include "JediCombatQueueCommand.h"

JediCombatQueueCommand::JediCombatQueueCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
	visMod = 25;
}

bool JediCombatQueueCommand::isJediCombatCommand() const {
	return true;
}