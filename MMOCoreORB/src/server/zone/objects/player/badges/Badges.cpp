#include "Badges.h"

Badges::Badges() {
	for (int i = 0; i < 5; ++i)
		badgeBitmask[i] = 0;

	for (int i = 0; i < 6; ++i)
		badgeTypeCounts[i] = 0;

	badgeTotal = 0;

	addSerializableVariables();
}

Badges::Badges(const Badges& badges) : Object(), Serializable(), ReadWriteLock() {
	for (int i = 0; i < 5; ++i) {
		badgeBitmask[i] = badges.badgeBitmask[i];
	}

	for (int i = 0; i < 6; ++i)
		badgeTypeCounts[i] = badges.badgeTypeCounts[i];

	badgeTotal = badges.badgeTotal;

	addSerializableVariables();
}

Badges& Badges::operator=(const Badges& badges) {
	for (int i = 0; i < 5; ++i) {
		badgeBitmask[i] = badges.badgeBitmask[i];
	}

	for (int i = 0; i < 6; ++i)
		badgeTypeCounts[i] = badges.badgeTypeCounts[i];

	badgeTotal = badges.badgeTotal;

	return *this;
}

void Badges::addSerializableVariables() {
	addSerializableVariable("badgeBitmask1", &badgeBitmask[0]);
	addSerializableVariable("badgeBitmask2", &badgeBitmask[1]);
	addSerializableVariable("badgeBitmask3", &badgeBitmask[2]);
	addSerializableVariable("badgeBitmask4", &badgeBitmask[3]);
	addSerializableVariable("badgeBitmask5", &badgeBitmask[4]);

	addSerializableVariable("badgeTypeCount1", &badgeTypeCounts[0]);
	addSerializableVariable("badgeTypeCount2", &badgeTypeCounts[1]);
	addSerializableVariable("badgeTypeCount3", &badgeTypeCounts[2]);
	addSerializableVariable("badgeTypeCount4", &badgeTypeCounts[3]);
	addSerializableVariable("badgeTypeCount5", &badgeTypeCounts[4]);
	addSerializableVariable("badgeTypeCount6", &badgeTypeCounts[5]);

	addSerializableVariable("badgeTotal", &badgeTotal);
}

void to_json(nlohmann::json& j, const Badges& b) {
	auto array = nlohmann::json::array();

	for (int i = 0; i < 5; ++i) {
		array.push_back(b.badgeBitmask[i]);
	}

	j["badgeBitmasks"] = array;

	auto array2 = nlohmann::json::array();

	for (int i = 0; i < 6; ++i) {
		array2.push_back(b.badgeTypeCounts[i]);
	}

	j["badgeTypeCounts"] = array2;
	j["badgeTotal"] = b.badgeTotal;
}

void Badges::setBadge(const uint32 badgeid) {
	const Badge* badge = BadgeList::instance()->get(badgeid);
	setBadge(badge);
}

void Badges::setBadge(const Badge* badge) {
	if (badge == nullptr)
		return;

	Locker locker(this);

	const int badgeIndex = badge->getIndex();

	int bitmaskNumber = badgeIndex >> 5;

	uint32 bit = badgeIndex % 32;
	uint32 value = 1 << bit;

	if (bitmaskNumber > 4 || bitmaskNumber < 0) {
		Logger::console.error("Badge::setBadge wrong badge index " + String::valueOf(badgeIndex));

		return;
	}

	if (!(badgeBitmask[bitmaskNumber] & value)) {
		badgeBitmask[bitmaskNumber] |= value;
		const int badgeType = badge->getTypeInt();
		badgeTypeCounts[badgeType]++;
		badgeTotal++;
	}
}

void Badges::unsetBadge(const uint32 badgeid) {
	const Badge* badge = BadgeList::instance()->get(badgeid);
	unsetBadge(badge);
}

void Badges::unsetBadge(const Badge* badge) {
	if (badge == nullptr)
		return;
	Locker locker(this);

	const int badgeIndex = badge->getIndex();
	int bitmaskNumber = badgeIndex >> 5;

	uint32 bit = badgeIndex % 32;
	uint32 value = 1 << bit;

	if (bitmaskNumber > 4 || bitmaskNumber < 0) {
		Logger::console.error("Badge::unsetBadge wrong badge index " + String::valueOf(badgeIndex));

		return;
	}

	if (badgeBitmask[bitmaskNumber] & value) {
		badgeBitmask[bitmaskNumber] -= value;
		const int badgeType = badge->getTypeInt();
		badgeTypeCounts[badgeType]--;
		badgeTotal--;
	}
}

bool Badges::hasBadge(int badgeindex) const {
	int bitmaskNumber = badgeindex >> 5;

	if (bitmaskNumber > 4 || bitmaskNumber < 0) {
		Logger::console.error("Badge::hasBadge wrong badge index " + String::valueOf(badgeindex));

		return false;
	}

	uint32 bit = badgeindex % 32;
	uint32 value = 1 << bit;

	ReadLocker locker(this);

	bool res = badgeBitmask[bitmaskNumber] & value;

	return res;
}

void Badges::setBitmask(int index, uint32 bitmask) {
	if (index > 4 || index < 0) {
		Logger::console.error("Badge::setBitmask wrong badge index " + String::valueOf(index));

		return;
	}

	Locker locker(this);

	badgeBitmask[index] = bitmask;
}

uint32 Badges::getBitmask(int index) const {
	uint32 res = 0;

	if (index > 4 || index < 0) {
		Logger::console.error("Badge::getBitmask wrong badge index " + String::valueOf(index));

		return res;
	}

	ReadLocker locker(this);

	res = badgeBitmask[index];

	return res;
}

void Badges::setTypeCount(uint8 index, uint8 value) {
	if (index > 5)
		return;

	Locker locker(this);

	badgeTypeCounts[index] = value;
}

uint8 Badges::getTypeCount(uint8 type) const {
	ReadLocker locker(this);

	uint8 res = badgeTypeCounts[type];

	return res;
}

uint8 Badges::getNumBadges() const {
	ReadLocker locker(this);

	uint8 res = badgeTotal;

	return res;
}

void Badges::setNumBadges(uint8 value) {
	Locker locker(this);

	badgeTotal = value;
}