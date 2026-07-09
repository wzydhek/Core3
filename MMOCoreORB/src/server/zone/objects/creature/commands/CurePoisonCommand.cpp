#include "CurePoisonCommand.h"

CurePoisonCommand::CurePoisonCommand(const String& name, ZoneProcessServer* server) : CurePackCommand(name, server) {
	state = CreatureState::POISONED;
}