/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

class FrsData : public Object {
	int councilType;
	int rank;

public:
	FrsData();

	FrsData(const FrsData& data);

	FrsData& operator=(const FrsData& data);

	friend void to_json(nlohmann::json& j, const FrsData& f);

	bool operator==(const FrsData& data) const;

	void setCouncilType(int type);

	int getCouncilType() const;

	void setRank(int newRank);

	int getRank() const;

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};
