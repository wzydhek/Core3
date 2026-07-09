#include "XpPurchaseTemplate.h"

XpPurchaseTemplate::XpPurchaseTemplate() {
	requiredSkill = "";
	xpType = "";
	grantType = "";
	grantName = "";
	xpAmount = 0;
	noRemove = false;
}

XpPurchaseTemplate::~XpPurchaseTemplate() {
}

void XpPurchaseTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	requiredSkill = templateData->getStringField("requiredSkill");
	grantType = templateData->getStringField("grantType");
	grantName = templateData->getStringField("grantName");
	xpType = templateData->getStringField("xpType");
	xpAmount = templateData->getIntField("xpAmount");
	noRemove = templateData->getBooleanField("noRemove");
}

const String& XpPurchaseTemplate::getRequiredSkill() {
	return requiredSkill;
}

const String& XpPurchaseTemplate::getGrantType() {
	return grantType;
}

const String& XpPurchaseTemplate::getGrantName() {
	return grantName;
}

const String& XpPurchaseTemplate::getXpType() {
	return xpType;
}

bool XpPurchaseTemplate::isNoRemove() {
	return noRemove;
}

int XpPurchaseTemplate::getXpAmount() {
	return xpAmount;
}