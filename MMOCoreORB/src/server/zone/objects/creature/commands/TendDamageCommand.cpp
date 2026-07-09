#include "TendDamageCommand.h"

TendDamageCommand::TendDamageCommand(const String& name, ZoneProcessServer* server) : TendCommand(name, server) {
	effectName = "clienteffect/healing_healdamage.cef";

	mindCost = 200;
	mindWoundCost = 5;

	tendDamage = true;

	healthHealed = 50;
	actionHealed = 50;

	// defaultTime = 5.0;
	range = 6.0;
}