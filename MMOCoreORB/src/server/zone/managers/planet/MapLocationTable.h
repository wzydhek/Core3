/*
 * MapLocationTable.h
 *
 *  Created on: 18/06/2010
 *      Author: victor
 */

#pragma once

#include "MapLocationEntry.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

class MapLocationTable : public Object, public ReadWriteLock {
	VectorMap<String, SortedVector<MapLocationEntry> > locations;

public:
	MapLocationTable();

	MapLocationTable(const MapLocationTable& t);

	Object* clone();

	Object* clone(void* object);

	void transferObject(SceneObject* object);

	void dropObject(SceneObject* object);

	bool containsObject(SceneObject* object) const;

	void updateObjectsIcon(SceneObject* object, byte icon);

	const SortedVector<MapLocationEntry> getLocation(const String& name) const;

	const SortedVector<MapLocationEntry>& get(int index) const;

	int findLocation(const String& name) const;

	int size() const;
};
