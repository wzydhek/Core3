#include "ExtinguishFireCommand.h"

ExtinguishFireCommand::ExtinguishFireCommand(const String& name, ZoneProcessServer* server) : CurePackCommand(name, server) {
	state = CreatureState::ONFIRE;
}