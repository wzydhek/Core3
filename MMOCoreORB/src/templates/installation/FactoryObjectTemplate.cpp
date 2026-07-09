#include "FactoryObjectTemplate.h"

FactoryObjectTemplate::FactoryObjectTemplate() {
}

FactoryObjectTemplate::~FactoryObjectTemplate() {
}

void FactoryObjectTemplate::readObject(LuaObject* templateData) {
	SharedInstallationObjectTemplate::readObject(templateData);

	LuaObject craftingTabsSupportedList = templateData->getObjectField("craftingTabsSupported");

	for (int i = 1; i < craftingTabsSupportedList.getTableSize() + 1; ++i)
		craftingTabsSupported.add(craftingTabsSupportedList.getIntAt(i));

	craftingTabsSupportedList.pop();
}

Vector<int> FactoryObjectTemplate::getCraftingTabsSupported() {
	return craftingTabsSupported;
}

bool FactoryObjectTemplate::isFactoryObjectTemplate() {
	return true;
}