/*
 * SuiCommand.h
 *
 *  Created on: Nov 7, 2013
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"

class SuiCommand : public Object {
public:
	static const int SCT_none = 0x00;
	static const int SCT_clearDataSource = 0x01;
	static const int SCT_addChildWidget = 0x02;
	static const int SCT_setProperty = 0x03;
	static const int SCT_addDataItem = 0x04;
	static const int SCT_subscribeToEvent = 0x05;
	static const int SCT_addDataSourceContainer = 0x06;
	static const int SCT_clearDataSourceContainer = 0x07;
	static const int SCT_addDataSource = 0x08;

private:
	byte commandType;
	Vector<UnicodeString> wideParameters;
	Vector<String> narrowParameters;

public:
	SuiCommand();

	SuiCommand(const byte& commandType);

	byte getCommandType();

	void addNarrowParameter(const String& param);

	String getNarrowParameter(int index);

	void addWideParameter(const UnicodeString& param);

	UnicodeString& getWideParameter(int index);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};
