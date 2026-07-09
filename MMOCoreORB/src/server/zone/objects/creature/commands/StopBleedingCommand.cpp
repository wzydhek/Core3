#include "StopBleedingCommand.h"

StopBleedingCommand::StopBleedingCommand(const String& name, ZoneProcessServer* server) : ForceHealQueueCommand(name, server) {
}