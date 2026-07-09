#include "SetHueCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

SetHueCommand::SetHueCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SetHueCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ZoneServer* zoneServer = server->getZoneServer();

	if (zoneServer == nullptr)
		return GENERALERROR;

	ManagedReference<SceneObject*> targetObject = zoneServer->getObject(target);

	if (targetObject == nullptr || !targetObject->isAiAgent())
		return INVALIDTARGET;

	auto agent = targetObject->asAiAgent();

	if (agent == nullptr || !agent->isMonster())
		return GENERALERROR;

	UnicodeTokenizer tokenizer(arguments);
	tokenizer.setDelimeter(" ");

	if (!tokenizer.hasMoreTokens())
		return INVALIDPARAMETERS;

	int hue = tokenizer.getIntToken();

	Locker clocker(agent, creature);

	agent->setHue(hue);

	return SUCCESS;
}