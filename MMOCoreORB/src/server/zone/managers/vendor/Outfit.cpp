#include "Outfit.h"

Outfit::Outfit() : Object() {
	outfitName = "";
}

Outfit::Outfit(const Outfit& outfit) : Object() {
	outfitName = outfit.outfitName;
	clothingCRC = outfit.clothingCRC;
}

Outfit& Outfit::operator=(const Outfit& outfit) {
	if (this == &outfit)
		return *this;

	outfitName = outfit.outfitName;
	clothingCRC = outfit.clothingCRC;

	return *this;
}

int Outfit::compareTo(const Outfit& outfit) const {
	return 0;
}

void Outfit::addClothingCRC(unsigned int clothingcrc) {
	clothingCRC.add(clothingcrc);
}

String& Outfit::getOutfitName() {
	return outfitName;
}

Vector<uint32>* Outfit::getClothing() {
	return &clothingCRC;
}

int Outfit::getClothingSize() {
	return clothingCRC.size();
}