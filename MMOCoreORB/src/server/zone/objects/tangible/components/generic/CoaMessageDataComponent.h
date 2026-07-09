
#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

class CoaMessageDataComponent : public DataObjectComponent {
protected:
	SerializableString faction;
	int number;
public:
	CoaMessageDataComponent();

	virtual ~CoaMessageDataComponent();

	void writeJSON(nlohmann::json& j) const;

	void setFaction(String side);

	void setNumber(int num);

	String getFaction();

	int getNumber();

	bool isCoaMessageData();

private:
	void addSerializableVariables();
};
