#include "HealAllOther2Command.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/packets/object/CombatAction.h"

HealAllOther2Command::HealAllOther2Command(const String& name, ZoneProcessServer* server) : ForceHealQueueCommand(name, server) {
}