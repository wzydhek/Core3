#include "PlayerQuestData.h"

PlayerQuestData::PlayerQuestData() : Object() {
	ownerId = 0;
	activeStepBitmask = 0;
	completedStepBitmask = 0;
	completedFlag = 0;
	questCounter = 0;
}

PlayerQuestData::PlayerQuestData(const PlayerQuestData& data) : Object() {
	initialize(data);
}

PlayerQuestData& PlayerQuestData::operator=(const PlayerQuestData& data) {
	if (this == &data)
		return *this;

	initialize(data);

	return *this;
}

void to_json(nlohmann::json& j, const PlayerQuestData& d) {
	j["ownerId"] = d.ownerId;
	j["activeStepBitmask"] = d.activeStepBitmask;
	j["completedStepBitmask"] = d.completedStepBitmask;
	j["completedFlag"] = d.completedFlag;
	j["questCounter"] = d.questCounter;
}

bool PlayerQuestData::toBinaryStream(ObjectOutputStream* stream) {
	stream->writeLong(ownerId);
	stream->writeShort(activeStepBitmask);
	stream->writeShort(completedStepBitmask);
	stream->writeByte(completedFlag);
	stream->writeInt(questCounter);

	return true;
}

bool PlayerQuestData::parseFromBinaryStream(ObjectInputStream* stream) {
	ownerId = stream->readLong();
	activeStepBitmask = stream->readShort();
	completedStepBitmask = stream->readShort();
	completedFlag = stream->readByte();
	questCounter = stream->readInt();

	return true;
}

void PlayerQuestData::initialize(const PlayerQuestData& data) {
	ownerId = data.ownerId;
	activeStepBitmask = data.activeStepBitmask;
	completedStepBitmask = data.completedStepBitmask;
	completedFlag = data.completedFlag;
	questCounter = data.questCounter;
}

// Accessors

uint64 PlayerQuestData::getOwnerId() const {
	return ownerId;
}

uint16 PlayerQuestData::getActiveStepBitmask() const {
	return activeStepBitmask;
}

uint16 PlayerQuestData::getCompletedStepBitmask() const {
	return completedStepBitmask;
}

byte PlayerQuestData::getCompletedFlag() const {
	return completedFlag;
}

int PlayerQuestData::getQuestCounter() const {
	return questCounter;
}

// Mutators

void PlayerQuestData::setOwnerId(uint64 ownerId) {
	this->ownerId = ownerId;
}

void PlayerQuestData::setActiveStepBitmask(uint16 activeStepBitmask) {
	this->activeStepBitmask = activeStepBitmask;
}

void PlayerQuestData::setCompletedStepBitmask(uint16 completedStepBitmask) {
	this->completedStepBitmask = completedStepBitmask;
}

void PlayerQuestData::setCompletedFlag(byte completedFlag) {
	this->completedFlag = completedFlag;
}

void PlayerQuestData::setQuestCounter(int questCounter) {
	this->questCounter = questCounter;
}