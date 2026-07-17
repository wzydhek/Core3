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

	bool hasFeature(const String& key);
};

}
}

using namespace server::features;
