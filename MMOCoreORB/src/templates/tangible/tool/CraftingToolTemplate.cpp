#include "CraftingToolTemplate.h"

CraftingToolTemplate::CraftingToolTemplate() : toolType(0), complexityLevel(0), forceCritAssembly(0), forceCritExperiment(0) {
}

CraftingToolTemplate::~CraftingToolTemplate() {
}

void CraftingToolTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	toolType = templateData->getIntField("toolType");
	complexityLevel = templateData->getIntField("complexityLevel");
	forceCritAssembly = templateData->getIntField("forceCriticalAssembly");
	forceCritExperiment = templateData->getIntField("forceCriticalExperiment");

	LuaObject tabList = templateData->getObjectField("enabledTabs");

	for (int i = 1; i <= tabList.getTableSize(); ++i) {
		tabs.add(tabList.getIntAt(i));
	}

	tabList.pop();
}

int CraftingToolTemplate::getToolType() const {
	return toolType;
}

int CraftingToolTemplate::getComplexityLevel() const {
	return complexityLevel;
}

int CraftingToolTemplate::getForceCriticalAssembly() const {
	return forceCritAssembly;
}

int CraftingToolTemplate::getForceCriticalExperiment() const {
	return forceCritExperiment;
}

const Vector<uint32>& CraftingToolTemplate::getTabs() const {
	return tabs;
}