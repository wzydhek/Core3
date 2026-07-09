#include "CuiConsentResponseCommand.h"

CuiConsentResponseCommand::CuiConsentResponseCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int CuiConsentResponseCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	// if (!checkStateMask(creature))
	// return INVALIDSTATE;

	// if (!checkInvalidLocomotions(creature))
	// return INVALIDLOCOMOTION;

	error("CuiConsentResponseCommand got called!!!!!!!!!!!!!!!!!!!!");

	return SUCCESS;
}