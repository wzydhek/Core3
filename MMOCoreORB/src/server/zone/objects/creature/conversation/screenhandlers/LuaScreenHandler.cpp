/*
 * LuaScreenHandler.cpp
 *
 *  Created on: 03/01/2012
 *      Author: victor
 */

#include "LuaScreenHandler.h"

LuaScreenHandler::LuaScreenHandler() : ScreenHandler(), Logger("LuaScreenHandler") {
}

bool LuaScreenHandler::toBinaryStream(ObjectOutputStream* stream) {
	return true;
}

bool LuaScreenHandler::parseFromBinaryStream(ObjectInputStream* stream) {
	return true;
}