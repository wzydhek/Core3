#include "PlayerBitmasks.h"

PlayerBitmasks::PlayerBitmasks() {
	for (int i = 0; i < 4; ++i)
		playerBitmask[i] = 0;

	addSerializableVariables();
}

PlayerBitmasks::PlayerBitmasks(const PlayerBitmasks& bitmasks) : Object(), Serializable(), ReadWriteLock() {
	for (int i = 0; i < 4; ++i) {
		playerBitmask[i] = bitmasks.playerBitmask[i];
	}

	addSerializableVariables();
}

PlayerBitmasks& PlayerBitmasks::operator=(const PlayerBitmasks& bitmasks) {
	for (int i = 0; i < 4; ++i) {
		playerBitmask[i] = bitmasks.playerBitmask[i];
	}

	return *this;
}

void PlayerBitmasks::addSerializableVariables() {
	addSerializableVariable("playerBitmask1", &playerBitmask[0]);
	addSerializableVariable("playerBitmask2", &playerBitmask[1]);
	addSerializableVariable("playerBitmask3", &playerBitmask[2]);
	addSerializableVariable("playerBitmask4", &playerBitmask[3]);
}

void to_json(nlohmann::json& j, const PlayerBitmasks& b) {
	auto array = nlohmann::json::array();

	for (int i = 0; i < 4; ++i) {
		array.push_back(b.playerBitmask[i]);
	}

	j["playerBitmasks"] = array;
}

void PlayerBitmasks::setOneBit(const uint32 bitmask) {
	uint32 bitBucket = bitmask / 32;
	uint32 bitValue = 1 << (bitmask % 32);

#ifdef DEBUG_PLAYERBITMASKS
	Logger::console.info("setPlayerBitmask - Bitmask = " + String::valueOf(bitmask) + " Bit Bucket = " + String::valueOf(bitBucket) + " Bit Value = " + String::valueOf(bitValue), true);
#endif
	Locker locker(this);

	playerBitmask[bitBucket] |= bitValue;
}

void PlayerBitmasks::clearOneBit(const uint32 bitmask) {
	uint32 bitBucket = bitmask / 32;
	uint32 bitValue = 1 << (bitmask % 32);

#ifdef DEBUG_PLAYERBITMASKS
	Logger::console.info("removePlayerBitmask - Bitmask = " + String::valueOf(bitmask) + " Bit Bucket = " + String::valueOf(bitBucket) + " Bit Value = " + String::valueOf(bitValue), true);
#endif
	Locker locker(this);
	playerBitmask[bitBucket] &= ~bitValue;
}

bool PlayerBitmasks::hasPlayerBit(const uint32 bitmask) const {
	uint32 bitBucket = bitmask / 32;
	uint32 bitValue = 1 << (bitmask % 32);

#ifdef DEBUG_PLAYERBITMASKS
	Logger::console.info("hasPlayerBitmask - Bitmask = " + String::valueOf(bitmask) + " Bit Bucket = " + String::valueOf(bitBucket) + " Bit Value = " + String::valueOf(bitValue), true);
#endif
	ReadLocker locker(this);
	return (playerBitmask[bitBucket] & bitValue) != 0;
}

uint32 PlayerBitmasks::getBitmask(int index) const {
	uint32 res = 0;

	if (index > 3 || index < 0) {
		Logger::console.error("PlayerBitmasks::getBitmask index out of bounds" + String::valueOf(index));

		return res;
	}

	ReadLocker locker(this);

	res = playerBitmask[index];

	return res;
}