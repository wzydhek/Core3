#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

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
