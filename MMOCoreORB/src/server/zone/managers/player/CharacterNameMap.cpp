#include "CharacterNameMap.h"

CharacterNameMap::CharacterNameMap() : names(3000), reverseTable(3000) {
}

void CharacterNameMap::put(CreatureObject* player) {
	Locker locker(&guard);

	String firstName = player->getFirstName().toLowerCase();
	uint64 oid = player->getObjectID();

	names.put(firstName, oid);
	reverseTable.put(oid, firstName);
}

bool CharacterNameMap::put(const String& name, uint64 oid) {
	Locker locker(&guard);

	auto lowerCase = name.toLowerCase();

	if (names.put(lowerCase, oid) != names.getNullValue())
		return false;

	reverseTable.put(oid, lowerCase);

	return true;
}

void CharacterNameMap::remove(const String& name) {
	Locker locker(&guard);

	uint64 oid = names.remove(name.toLowerCase());
	reverseTable.remove(oid);
}

void CharacterNameMap::remove(uint64 oid) {
	Locker locker(&guard);

	if (reverseTable.containsKey(oid)) {
		String name = reverseTable.get(oid);
		names.remove(name);
		reverseTable.remove(oid);
	}
}

uint64 CharacterNameMap::get(const String& name) {
	ReadLocker locker(&guard);

	return names.get(name.toLowerCase());
}

String CharacterNameMap::get(uint64 oid) {
	ReadLocker locker(&guard);

	return reverseTable.get(oid);
}

bool CharacterNameMap::containsKey(const String& name) {
	ReadLocker locker(&guard);

	return names.containsKey(name.toLowerCase());
}

bool CharacterNameMap::containsOID(uint64 oid) {
	ReadLocker locker(&guard);

	return reverseTable.containsKey(oid);
}

int CharacterNameMap::size() {
	return names.size();
}

HashTable<String, uint64> CharacterNameMap::getNames() {
	ReadLocker locker(&guard);

	return names;
}