#include "SynchronizedUiStopListeningCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/scene/SceneObject.h"

SynchronizedUiStopListeningCommand::SynchronizedUiStopListeningCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SynchronizedUiStopListeningCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<SceneObject*> object = (creature->getZoneServer()->getObject(target)).castTo<SceneObject*>();
	int value = 0;

	StringTokenizer tokenizer(arguments.toString());

	if (tokenizer.hasMoreTokens())
		value = tokenizer.getIntToken();

	if (object != nullptr && creature->isPlayerCreature()) {
		try {
			Locker clocker(object, creature);

			object->synchronizedUIStopListen(creature, value);
		} catch (Exception& e) {
		}
	}

	return SUCCESS;
}