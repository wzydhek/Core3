#include "ModSortingHelper.h"

ModSortingHelper::ModSortingHelper() : Mod("", 0) {
}

ModSortingHelper::ModSortingHelper(String name, int value) : Mod(name, value) {
}

int ModSortingHelper::compareTo(const Mod& e) const {
	// Make copies of this and e to get around getValue not being const
	if (Mod(*this).getValue() >= Mod(e).getValue()) {
		return 1;
	} else {
		return -1;
	}
}