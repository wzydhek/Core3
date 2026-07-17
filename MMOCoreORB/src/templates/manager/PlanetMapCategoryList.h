/*
 * PlanetMapCategoryList.h
 *
 *  Created on: Apr 26, 2011
 *      Author: polonel
 */

#pragma once

#include "engine/engine.h"
#include "system/util/HashTable.h"
#include "PlanetMapCategory.h"

namespace templates {

class PlanetMapCategory;

class PlanetMapCategoryList : public HashTable<int, Reference<PlanetMapCategory*> > {
	int hash(const int& key) const override;

	int hash(const String& key) const;

public:
	PlanetMapCategoryList();

	bool containsKey(const String& key) const;

	const Reference<PlanetMapCategory*>& get(const String& key) const;

	const Reference<PlanetMapCategory*>& get(const int& key) const;

	Reference<PlanetMapCategory*> put(const String& key, const Reference<PlanetMapCategory*>& value);
};

} // namespace templates

using namespace templates;
