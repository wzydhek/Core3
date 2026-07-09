#include "HealAllOther1Command.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/packets/object/CombatAction.h"

HealAllOther1Command::HealAllOther1Command(const String& name, ZoneProcessServer* server) : ForceHealQueueCommand(name, server) {
}