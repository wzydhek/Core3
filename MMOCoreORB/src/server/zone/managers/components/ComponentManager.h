/*
 * ComponentManager.h
 *
 *  Created on: 26/05/2011
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/scene/components/SceneObjectComponent.h"
#include "server/zone/objects/scene/components/DataObjectComponent.h"
#include "engine/util/ObjectFactory.h"

namespace server {
namespace zone {
namespace managers {
namespace components {

class ComponentManager : public Singleton<ComponentManager>, public Object, public ReadWriteLock {
protected:
	HashTable<String, Reference<SceneObjectComponent*> > components;
	ObjectFactory<DataObjectComponent* (), String> dataObjectFactory;

public:
	ComponentManager();

	template<class K>
	K getComponent(const String& name) {
		K comp;

		rlock();

		try {
			comp = dynamic_cast<K>(components.get(name).get());
		} catch (...) {
			runlock();
			throw;
		}

		runlock();

		return comp;
	}

	DataObjectComponent* getDataObjectComponent(const String& name);

	void putComponent(const String& name, SceneObjectComponent* component);

	int size();
};

} // namespace components
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::components;
