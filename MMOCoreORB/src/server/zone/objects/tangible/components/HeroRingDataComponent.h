
#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

class HeroRingDataComponent : public DataObjectComponent {
protected:
	int charges;
public:
	HeroRingDataComponent();

	virtual ~HeroRingDataComponent();

	void writeJSON(nlohmann::json& j) const;

	void setCharges(int num);

	int getCharges();

	bool isHeroRingData();

private:
	void addSerializableVariables();
};
