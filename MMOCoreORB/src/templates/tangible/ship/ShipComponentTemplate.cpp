#include "ShipComponentTemplate.h"

ShipComponentTemplate::ShipComponentTemplate() {
	attributeMap.setNoDuplicateInsertPlan();
	attributeMap.setNullValue(0.f);

	modifierMap.setNoDuplicateInsertPlan();
	modifierMap.setNullValue(0.f);
}

ShipComponentTemplate::~ShipComponentTemplate() {
}

void ShipComponentTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	componentDataName = templateData->getStringField("componentDataName");

	auto attributes = templateData->getObjectField("attributes");

	if (attributes.isValidTable()) {
		for (int i = 1; i <= attributes.getTableSize(); ++i) {
			auto entry = attributes.getObjectAt(i);

			if (entry.isValidTable() && entry.getTableSize() == 2) {
				String key = entry.getStringAt(1);
				float value = entry.getFloatAt(2);

				attributeMap.put(key, value);
			}

			entry.pop();
		}
	}

	attributes.pop();

	auto modifiers = templateData->getObjectField("modifiers");

	if (modifiers.isValidTable()) {
		for (int i = 1; i <= modifiers.getTableSize(); ++i) {
			auto entry = modifiers.getObjectAt(i);

			if (entry.isValidTable() && entry.getTableSize() == 2) {
				String key = entry.getStringAt(1);
				float value = entry.getFloatAt(2);

				modifierMap.put(key, value);
			}

			entry.pop();
		}
	}

	modifiers.pop();
}

const VectorMap<String, float>& ShipComponentTemplate::getAttributeMap() const {
	return attributeMap;
}

const VectorMap<String, float>& ShipComponentTemplate::getModifierMap() const {
	return modifierMap;
}

const String& ShipComponentTemplate::getComponentDataName() const {
	return componentDataName.get();
}