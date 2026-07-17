/*
 * MobileOutfitGroup.h
 *
 *  Created on: 22/01/2012
 *      Author: victor
 */

#pragma once

#include "templates/mobile/MobileOutfit.h"
#include "templates/LuaTemplate.h"

namespace templates {
namespace mobile {

class MobileOutfitGroup : public Object {
	Vector<MobileOutfit> outfits;
public:
	MobileOutfitGroup();

	MobileOutfitGroup(const MobileOutfitGroup& o);

	MobileOutfitGroup& operator=(const MobileOutfitGroup& o);

	void readObject(LuaObject* luaObject);

	Vector<MobileOutfit>* getOutfits();

};

} // namespace mobile
} // namespace templates

using namespace templates::mobile;
