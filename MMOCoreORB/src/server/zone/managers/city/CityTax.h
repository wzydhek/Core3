/*
 * CityTax.h
 *
 *  Created on: Jul 25, 2012
 *      Author: swgemu
 */

#pragma once

#include "engine/lua/LuaObject.h"

class CityTax : public Object {
	int minValue;
	int maxValue;

	String menuText;
	String inputTitle;
	String inputText;
	String statusPrompt;
	String systemMessage;
	String emailSubject;
	String emailBody;

public:
	CityTax();

	CityTax(const CityTax& tax);

	CityTax& operator=(const CityTax& tax);

	void readObject(LuaObject* luaObject);

	int getMinValue() const;

	int getMaxValue() const;

	const String& getMenuText() const;

	const String& getInputTitle() const;

	const String& getInputText() const;

	const String& getStatusPrompt() const;

	const String& getSystemMessage() const;

	const String& getEmailSubject() const;

	const String& getEmailBody() const;
};
