#include "EnumerateCharacterId.h"

EnumerateCharacterId::EnumerateCharacterId(Account* account) : BaseMessage(100) {
	insertShort(0x02);
	insertInt(STRING_HASHCODE("EnumerateCharacterId"));

	Reference<const CharacterList*> characters = account->getCharacterList();

	insertInt(characters->size()); // Character List Count

	for (int i = 0; i < characters->size(); ++i) {
		const CharacterListEntry* entry = &characters->get(i);
		const GalaxyBanEntry* galaxyBan = account->getGalaxyBan(entry->getGalaxyID());
		String name = entry->getFullName();

		if (galaxyBan != nullptr) {
			name += " \\#FF0000(GALAXY BAN)";
		} else if (entry->isBanned()) {
			name += " \\#FF0000(BANNED)";
		}

		// Character Information
		insertUnicode(name); // Character Name

		insertInt(entry->getRace());	  // Player Race CRC
		insertLong(entry->getObjectID()); // Player ID

		insertInt(entry->getGalaxyID()); // Server ID That Character Is On
		insertInt(0x01);				 // Character Type - Regular Characters 1, Pre-Pub9 Jedi 2
	}
}

void EnumerateCharacterId::parse(Packet* pack) {
	uint16 ackSequence = pack->parseShort();
}