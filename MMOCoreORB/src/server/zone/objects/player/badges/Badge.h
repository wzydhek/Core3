/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "templates/datatables/DataTableRow.h"

class Badge {

public:
	enum /*Type*/ {
		ACCUMULATION,
		INTEREST,
		EXPLORATION,
		MASTER,
		EVENT,
		CONTENT,
		UNKNOWN
	};


	Badge();
	//Badge(Badge&) = default;

	void readFromRow(DataTableRow* row);


	int getIndex() const;
	
	const String getKey() const;

	const String getMusic() const;

	int getCategory() const;
	
	int getShow() const;

	const String getTypeString() const;

	uint8 getType() const;

	int getTypeInt() const;

	bool getHasMusic() const;


private:

	static uint8 getTypeFromString(const String& string);

	int index;
	int category;
	int show;
	/*Type type;*/
	uint8 type;
	bool hasMusic;
	String key;
	String music;
	String typeString;
};
