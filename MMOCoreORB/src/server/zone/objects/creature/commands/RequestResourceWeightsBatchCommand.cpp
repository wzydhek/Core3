#include "RequestResourceWeightsBatchCommand.h"
#include "server/zone/managers/crafting/CraftingManager.h"

RequestResourceWeightsBatchCommand::RequestResourceWeightsBatchCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int RequestResourceWeightsBatchCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	ManagedReference<CraftingManager*> craftingManager = creature->getZoneServer()->getCraftingManager();

	if (craftingManager == nullptr)
		return GENERALERROR;

	StringTokenizer tokenizer(arguments.toString());

	String value;
	uint32 schematicID;

	while (tokenizer.hasMoreTokens()) {
		tokenizer.getStringToken(value);

		try {
			schematicID = Integer::valueOf(value);

			craftingManager->sendResourceWeightsTo(creature, schematicID);
		} catch (Exception& e) {
			warning("Invalid draft slot request: " + value);
		}
	}

	return SUCCESS;
}