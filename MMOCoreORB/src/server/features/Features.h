/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "system/lang.h"
#include "system/util/HashTable.h"

namespace server {
 namespace features {

class Features {
protected:
	HashTable<String, String> options;

public:
	Features();

	bool loadFeatures();

	inline bool hasFeature(const String& key) {
		return options.containsKey(key);
	}
};

}
}
