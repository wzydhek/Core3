#include "CureDiseaseCommand.h"

CureDiseaseCommand::CureDiseaseCommand(const String& name, ZoneProcessServer* server) : CurePackCommand(name, server) {
	state = CreatureState::DISEASED;
}