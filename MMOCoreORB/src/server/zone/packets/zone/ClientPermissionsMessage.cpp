#include "ClientPermissionsMessage.h"

ClientPermissionsMessage::ClientPermissionsMessage() : BaseMessage() {
	insertShort(0x04);
	insertInt(STRING_HASHCODE("ClientPermissionsMessage"));

	// Galaxy Available
	insertBoolean(true);

	// Allow to create character
	insertBoolean(true);

	// Ignores character creation max bool, possibly Jedi Slot
	insertBoolean(false);

	// Unknown
	insertBoolean(false);
}

ClientPermissionsMessage::ClientPermissionsMessage(bool canConnect, bool canCreateCharacter) : BaseMessage() {
	insertShort(0x04);
	insertInt(STRING_HASHCODE("ClientPermissionsMessage"));

	// Galaxy Available
	insertBoolean(canConnect);

	// Allow to create character
	insertBoolean(canCreateCharacter);

	// Ignores character creation max bool, possibly Jedi Slot
	insertBoolean(false);

	// Unknown
	insertBoolean(false);
}