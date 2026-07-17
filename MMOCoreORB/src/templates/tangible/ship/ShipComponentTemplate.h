#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {
namespace ship {

class ShipComponentTemplate: public SharedTangibleObjectTemplate {
protected:
	VectorMap<String, float> attributeMap;
	VectorMap<String, float> modifierMap;

	StringParam componentDataName;

public:
	ShipComponentTemplate();

	~ShipComponentTemplate();

	void readObject(LuaObject* templateData);

	const VectorMap<String, float>& getAttributeMap() const;

	const VectorMap<String, float>& getModifierMap() const;

	const String& getComponentDataName() const;
};

} // namespace ship
} // namespace tangible
} // namespace templates

using namespace templates::tangible::ship;
