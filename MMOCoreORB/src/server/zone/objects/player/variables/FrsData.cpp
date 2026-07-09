#include "FrsData.h"

FrsData::FrsData() : Object() {
	councilType = 0;
	rank = -1;
}

FrsData::FrsData(const FrsData& data) : Object() {
	councilType = data.councilType;
	rank = data.rank;
}

FrsData& FrsData::operator=(const FrsData& data) {
	if (this == &data)
		return *this;

	councilType = data.councilType;
	rank = data.rank;

	return *this;
}

void to_json(nlohmann::json& j, const FrsData& f) {
	j["councilType"] = f.councilType;
	j["rank"] = f.rank;
}

bool FrsData::operator==(const FrsData& data) const {
	return councilType == data.councilType && rank == data.rank;
}

void FrsData::setCouncilType(int type) {
	councilType = type;
}

int FrsData::getCouncilType() const {
	return councilType;
}

void FrsData::setRank(int newRank) {
	rank = newRank;
}

int FrsData::getRank() const {
	return rank;
}

bool FrsData::toBinaryStream(ObjectOutputStream* stream) {
	return TypeInfo<int>::toBinaryStream(&councilType, stream) && TypeInfo<int>::toBinaryStream(&rank, stream);
}

bool FrsData::parseFromBinaryStream(ObjectInputStream* stream) {
	TypeInfo<int>::parseFromBinaryStream(&councilType, stream);
	TypeInfo<int>::parseFromBinaryStream(&rank, stream);

	return true;
}