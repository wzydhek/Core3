#include "CityInfoCommand.h"
#include "server/zone/managers/city/CityManager.h"

CityInfoCommand::CityInfoCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int CityInfoCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	byte rank = 0;
	StringTokenizer args(arguments.toString());
	String planet;

	if (args.hasMoreTokens()) {
		args.getStringToken(planet);
	} else {
		sendSyntax(creature);
		return INVALIDSYNTAX;
	}

	if (args.hasMoreTokens()) {
		rank = args.getIntToken();
		if (rank < 1 || rank > 5) {
			creature->sendSystemMessage("Rank, if specified, must be between 1 and 5.");
			return INVALIDPARAMETERS;
		}
	}

	if (creature->getZoneServer() == nullptr)
		return GENERALERROR;

	CityManager* cityManager = creature->getZoneServer()->getCityManager();

	if (cityManager == nullptr)
		return GENERALERROR;

	cityManager->sendCityReport(creature, planet, rank);
	return SUCCESS;
}

void CityInfoCommand::sendSyntax(CreatureObject* creature) {
	String syntax = "/cityinfo [planetname] <rank>";
	creature->sendSystemMessage(syntax);
}