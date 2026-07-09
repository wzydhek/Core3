/*
 * MobileOutfit.h
 *
 *  Created on: 22/01/2012
 *      Author: victor
 */

#pragma once

#include "system/lang.h"
#include "engine/lua/LuaObject.h"

class OutfitTangibleObject : public Object {
	String objectTemplate;
	VectorMap<String, uint8> customizationVariables;
public:
	OutfitTangibleObject();

	OutfitTangibleObject(const OutfitTangibleObject& o);

	OutfitTangibleObject& operator=(const OutfitTangibleObject& o);

	void readObject(LuaObject* luaObject);

	String getObjectTemplate();

	VectorMap<String, uint8>* getCustomizationVariables();
};

class MobileOutfit : public Object {
	Vector<OutfitTangibleObject> objects;
public:
	MobileOutfit();

	MobileOutfit(const MobileOutfit& o);

	MobileOutfit& operator=(const MobileOutfit& o);

	void readObject(LuaObject* luaObject);

	Vector<OutfitTangibleObject>* getObjects();

};
