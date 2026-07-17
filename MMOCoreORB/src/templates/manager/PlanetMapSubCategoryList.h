
#pragma once

#include "engine/engine.h"
#include "system/util/HashTable.h"
#include "PlanetMapSubCategory.h"

namespace templates {

class PlanetMapSubCategory;

class PlanetMapSubCategoryList : public HashTable<int, Reference<PlanetMapSubCategory*>> {
	int hash(const int& key) const override;

	int hash(const String& key) const;

public:
	PlanetMapSubCategoryList();

	bool containsKey(const String& key) const;

	const Reference<PlanetMapSubCategory*>& get(const String& key) const;

	const Reference<PlanetMapSubCategory*>& get(const int& key) const;

	Reference<PlanetMapSubCategory*> put(const String& key, const Reference<PlanetMapSubCategory*>& value);
};

} // namespace templates

using namespace templates;
