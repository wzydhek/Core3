/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "Badge.h"

Badge::Badge() :
	index(-1),
	category(-1),
	show(-1),
	type(UNKNOWN),
	hasMusic(false)
{}

void Badge::readFromRow(DataTableRow* row) {
	if (row == nullptr)
		return;

	const int INDEX = 0;
	const int KEY = 1;
	const int MUSIC = 2;
	const int CATEGORY = 3;
	const int SHOW = 4;
	const int TYPE = 5;

	row->getCell(INDEX)->getValue(index);
	row->getCell(KEY)->getValue(key);
	row->getCell(MUSIC)->getValue(music);
	row->getCell(CATEGORY)->getValue(category);
	row->getCell(SHOW)->getValue(show);
	row->getCell(TYPE)->getValue(typeString);

	type = getTypeFromString(typeString);
	hasMusic = music != "NONE";
}


uint8 Badge::getTypeFromString(const String& typeString) {
	if (typeString == "accumulation") {
		return ACCUMULATION;
	} else if (typeString == "interest") {
		return INTEREST;
	} else if (typeString.contains("exploration")) {
		return EXPLORATION;
	} else if (typeString == "master") {
		return MASTER;
	} else if (typeString == "events") {
		return EVENT;
	} else if (typeString == "content") {
		return CONTENT;
	} else {
		StringBuffer buffer;
		buffer << "Unknown badge type ";
		buffer << typeString;
		buffer << ".";
		Logger::console.fatal(buffer.toString());

		throw Exception(buffer.toString());
	}
}

int Badge::getIndex() const {
	return index;
}

const String Badge::getKey() const {
	return key;
}

const String Badge::getMusic() const {
	return music;
}

int Badge::getCategory() const {
	return category;
}

int Badge::getShow() const {
	return show;
}

const String Badge::getTypeString() const {
	return typeString;
}

uint8 Badge::getType() const {
	return type;
}

int Badge::getTypeInt() const {
	return static_cast<int>(type);
}

bool Badge::getHasMusic() const {
	return hasMusic;
}