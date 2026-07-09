#include "VendorInfoCommand.h"

int VendorInfoCommand::executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments) {
	if (!creature->isPlayerCreature())
		return 1;

	return 0;
}