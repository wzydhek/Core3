
#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

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

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;
