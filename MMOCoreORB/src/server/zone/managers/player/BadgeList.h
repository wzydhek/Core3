#pragma once

#include "server/zone/objects/player/badges/Badge.h"

class BadgeList : public Singleton<BadgeList>, public Logger, public Object {
	// idx to Badge
	VectorMap<unsigned int, const Badge*> badges;

	// Name to badge
	HashTable<String, const Badge*> names;

	void loadData();
public:
	BadgeList();
	~BadgeList();

	/*
	 * Adds a badge, takes over ownership
	 */
	void add(Badge* badge);

	/*
	 * Get a badge by name
         * returns nullptr if the name wasn't found
	 */
	const Badge* get(const String& name) const;

	/*
         * Get a badge by index
	 * return nullptre if the name wasn't found
	 */
	const Badge* get(unsigned int idx) const;

	/*
	 * Returns the (idx, Badge*) vector map
	 */
	const VectorMap<unsigned int, const Badge*>* getMap() const;

};
