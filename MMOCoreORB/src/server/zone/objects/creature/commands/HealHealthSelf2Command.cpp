#include "HealHealthSelf2Command.h"
#include "server/zone/objects/scene/SceneObject.h"

HealHealthSelf2Command::HealHealthSelf2Command(const String& name, ZoneProcessServer* server) : ForceHealQueueCommand(name, server) {
}