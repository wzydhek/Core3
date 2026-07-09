#include "VendorCreatureTemplate.h"

VendorCreatureTemplate::VendorCreatureTemplate() {
}

VendorCreatureTemplate::~VendorCreatureTemplate() {
}

void VendorCreatureTemplate::readObject(LuaObject* templateData) {
	SharedCreatureObjectTemplate::readObject(templateData);

	LuaObject hairTemplate = templateData->getObjectField("hair");

	hairFile.removeAll();
	for (int i = 1; i <= hairTemplate.getTableSize(); ++i) {
		hairFile.add(hairTemplate.getStringAt(i));
	}

	hairTemplate.pop();

	LuaObject clothesTemplate = templateData->getObjectField("clothing");

	outfits.removeAll();
	for (int i = 1; i <= clothesTemplate.getTableSize(); ++i) {
		outfits.add(clothesTemplate.getStringAt(i));
	}

	clothesTemplate.pop();

	LuaObject customizationStringNamesList = templateData->getObjectField("customizationStringNames");

	for (int i = 1; i <= customizationStringNamesList.getTableSize(); ++i) {
		customizationStringNames.add(customizationStringNamesList.getStringAt(i));
	}

	customizationStringNamesList.pop();

	LuaObject custValues = templateData->getObjectField("customizationValues");

	for (int i = 1; i <= custValues.getTableSize(); ++i) {
		lua_rawgeti(templateData->getLuaState(), -1, i);

		LuaObject values(templateData->getLuaState());

		Vector<int> valuesVector;

		for (int j = 1; j <= values.getTableSize(); ++j) {
			valuesVector.add(values.getIntAt(j));
		}

		customizationValues.add(valuesVector);

		values.pop();
	}

	custValues.pop();
}

String VendorCreatureTemplate::getHairFile(int idx) {
	if (idx < 0 || idx >= hairFile.size())
		return "";

	return hairFile.get(idx);
}

String VendorCreatureTemplate::getOutfitName(int idx) {
	if (idx < 0 || idx >= outfits.size())
		return "";

	return outfits.get(idx);
}

int VendorCreatureTemplate::getCustomizationStringNamesSize() {
	return customizationStringNames.size();
}

String VendorCreatureTemplate::getCustomizationStringName(int idx) {
	if (idx < 0 || idx >= customizationStringNames.size())
		return "";

	return customizationStringNames.get(idx);
}

int VendorCreatureTemplate::getCustomizationValuesSize() {
	return customizationValues.size();
}

Vector<int> VendorCreatureTemplate::getCustomizationValues(int idx) {
	return customizationValues.get(idx);
}

int VendorCreatureTemplate::getOutfitsSize() {
	return outfits.size();
}

int VendorCreatureTemplate::getHairSize() {
	return hairFile.size();
}

bool VendorCreatureTemplate::isVendorCreatureTemplate() {
	return true;
}