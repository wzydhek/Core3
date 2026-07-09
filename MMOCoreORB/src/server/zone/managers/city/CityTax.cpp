#include "CityTax.h"

CityTax::CityTax() : Object(), minValue(0), maxValue(0) {
}

CityTax::CityTax(const CityTax& tax) : Object() {
	minValue = tax.minValue;
	maxValue = tax.maxValue;
	menuText = tax.menuText;
	inputTitle = tax.inputTitle;
	inputText = tax.inputText;
	statusPrompt = tax.statusPrompt;
	systemMessage = tax.systemMessage;
	emailSubject = tax.emailSubject;
	emailBody = tax.emailBody;
}

CityTax& CityTax::operator=(const CityTax& tax) {
	if (this == &tax)
		return *this;

	minValue = tax.minValue;
	maxValue = tax.maxValue;
	menuText = tax.menuText;
	inputTitle = tax.inputTitle;
	inputText = tax.inputText;
	statusPrompt = tax.statusPrompt;
	systemMessage = tax.systemMessage;
	emailSubject = tax.emailSubject;
	emailBody = tax.emailBody;

	return *this;
}

void CityTax::readObject(LuaObject* luaObject) {
	minValue = luaObject->getIntField("min");
	maxValue = luaObject->getIntField("max");
	menuText = luaObject->getStringField("menuText");
	inputTitle = luaObject->getStringField("inputTitle");
	inputText = luaObject->getStringField("inputText");
	statusPrompt = luaObject->getStringField("statusPrompt");
	systemMessage = luaObject->getStringField("systemMessage");
	emailSubject = luaObject->getStringField("emailSubject");
	emailBody = luaObject->getStringField("emailBody");
}

int CityTax::getMinValue() const {
	return minValue;
}

int CityTax::getMaxValue() const {
	return maxValue;
}

const String& CityTax::getMenuText() const {
	return menuText;
}

const String& CityTax::getInputTitle() const {
	return inputTitle;
}

const String& CityTax::getInputText() const {
	return inputText;
}

const String& CityTax::getStatusPrompt() const {
	return statusPrompt;
}

const String& CityTax::getSystemMessage() const {
	return systemMessage;
}

const String& CityTax::getEmailSubject() const {
	return emailSubject;
}

const String& CityTax::getEmailBody() const {
	return emailBody;
}