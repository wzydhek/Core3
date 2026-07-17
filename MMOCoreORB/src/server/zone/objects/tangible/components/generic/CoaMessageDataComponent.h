
#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace generic {

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

} // namespace generic
} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components::generic;
