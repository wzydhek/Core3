#include "SetMoodInternalCommand.h"

SetMoodInternalCommand::SetMoodInternalCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SetMoodInternalCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	StringTokenizer tokenizer(arguments.toString());

	if (!tokenizer.hasMoreTokens())
		return GENERALERROR;

	uint8 moodid = (uint8)tokenizer.getIntToken();

	creature->setMood(moodid);

	return SUCCESS;
}