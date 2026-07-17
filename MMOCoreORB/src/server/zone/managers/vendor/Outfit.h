/*
 * Outfit.h
 *
 *  Created on: Mar 31, 2011
 *      Author: polonel
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace managers {
namespace vendor {

class Outfit : public Object {
	String outfitName;

	Vector<uint32> clothingCRC;

public:
	Outfit();

	Outfit(const Outfit& outfit);

	Outfit& operator=(const Outfit& outfit);

	int compareTo(const Outfit& outfit) const;

	void addClothingCRC(unsigned int clothingcrc);

	String& getOutfitName();

	Vector<uint32>* getClothing();

	int getClothingSize();

};
} // namespace vendor
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::vendor;
