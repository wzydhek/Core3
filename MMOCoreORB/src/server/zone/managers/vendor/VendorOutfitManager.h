/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.
*/

#pragma once

#include "Outfit.h"

namespace server {
namespace zone {
namespace managers {
namespace vendor {

class VendorOutfitManager : public Singleton<VendorOutfitManager>, public Logger, public Object {
	VectorMap<String, Reference<Outfit*> > outfits;

public:
	VendorOutfitManager();

	~VendorOutfitManager();

	void initialize();

	void loadLuaOutfits();

	VectorMap<String, Reference<Outfit*>>* getOutfits();

	String& getOutfitName(int idx);

	Reference<Outfit*> getOutfit(int idx);

	Reference<Outfit*> getOutfit(const String& key);

};

}
}
}
}

using namespace server::zone::managers::vendor;
