#include "ApplyPoisonCommand.h"

ApplyPoisonCommand::ApplyPoisonCommand(const String& name, ZoneProcessServer* server) : DotPackCommand(name, server) {
	skillName = "applypoison";
}