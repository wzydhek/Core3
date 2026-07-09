#include "LootkitObjectTemplate.h"

LootkitObjectTemplate::LootkitObjectTemplate() : deleteComponents(false) {
}

LootkitObjectTemplate::~LootkitObjectTemplate() {
}

void LootkitObjectTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	deleteComponents = templateData->getByteField("deleteComponents");

	components.removeAll();
	attributes.removeAll();
	comps.removeAll();
	reward.removeAll();

	LuaObject collectibleComponents = templateData->getObjectField("collectibleComponents");
	for (int i = 1; i <= collectibleComponents.getTableSize(); ++i) {
		components.put(collectibleComponents.getStringAt(i).hashCode(), false);
		comps.add(i - 1, collectibleComponents.getStringAt(i).hashCode());
	}
	collectibleComponents.pop();

	LuaObject collectibleComponentsAttributes = templateData->getObjectField("attributes");
	for (int i = 1; i <= collectibleComponentsAttributes.getTableSize(); ++i) {
		attributes.put(comps.get(i - 1), collectibleComponentsAttributes.getStringAt(i));
	}
	collectibleComponentsAttributes.pop();

	LuaObject rewards = templateData->getObjectField("collectibleReward");
	for (int i = 1; i <= rewards.getTableSize(); ++i) {
		reward.add(i - 1, rewards.getStringAt(i).hashCode());
	}
	rewards.pop();
}

VectorMap<uint32, bool> LootkitObjectTemplate::getComponents() const {
	return components;
}

VectorMap<uint32, String> LootkitObjectTemplate::getAttributes() const {
	return attributes;
}

Vector<uint32> LootkitObjectTemplate::getComps() const {
	return comps;
}

Vector<uint32> LootkitObjectTemplate::getReward() const {
	return reward;
}

bool LootkitObjectTemplate::getDeleteComponents() const {
	return deleteComponents;
}

void LootkitObjectTemplate::setDeleteComponents(bool deleteComponents) {
	this->deleteComponents = deleteComponents;
}

void LootkitObjectTemplate::setComponents(VectorMap<uint32, bool> components) {
	this->components = components;
}

void LootkitObjectTemplate::setAttributes(VectorMap<uint32, String> attributes) {
	this->attributes = attributes;
}

void LootkitObjectTemplate::setComps(Vector<uint32> comps) {
	this->comps = comps;
}

void LootkitObjectTemplate::setReward(Vector<uint32> reward) {
	this->reward = reward;
}