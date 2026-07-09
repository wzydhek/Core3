
#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"
#include "server/zone/objects/tangible/eventperk/FlagGame.h"

class FlagGameDataComponent : public DataObjectComponent {
protected:
	ManagedReference<FlagGame*> game;

public:
	FlagGameDataComponent();

	virtual ~FlagGameDataComponent();

	void writeJSON(nlohmann::json& j) const;

	bool toBinaryStream(ObjectOutputStream* stream);

	int writeObjectMembers(ObjectOutputStream* stream);

	bool readObjectMember(ObjectInputStream* stream, const String& name);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	void setFlagGame(FlagGame* ga);

	FlagGame* getFlagGame();

	bool isFlagGameData();
};
