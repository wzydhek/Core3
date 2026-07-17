/*
 * ContainerObjectsMap.h
 *
 *  Created on: 13/10/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "system/thread/atomic/AtomicTime.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace scene {
   	   class SceneObject;
   	   class UnloadContainerTask;
	   namespace variables {

	   class ContainerObjectsMap : public Variable {
		   int operationMode;

		   VectorMap<uint64, ManagedReference<SceneObject*>> containerObjects;
		   AtomicReference<VectorMap<uint64, uint64>*> oids;

		   AtomicTime lastAccess;

		   ManagedWeakReference<SceneObject*> container;

		   mutable ReadWriteLock* containerLock;

		   Reference<UnloadContainerTask*> unloadTask;

	   public:
		   enum { NORMAL_LOAD = 0, DELAYED_LOAD };

	   private:
		   void copyData(const ContainerObjectsMap& c);
		   void scheduleContainerUnload();

	   public:
		   ContainerObjectsMap();
		   ~ContainerObjectsMap();
		   ContainerObjectsMap(const ContainerObjectsMap& c);

		   ContainerObjectsMap& operator=(const ContainerObjectsMap& c);

		   VectorMap<uint64, ManagedReference<SceneObject*>>* getContainerObjects();

		   bool toBinaryStream(ObjectOutputStream* stream);
		   bool parseFromBinaryStream(ObjectInputStream* stream);

		   void notifyLoadFromDatabase();

		   void loadObjects();
		   void unloadObjects();

		   void removeAll();
		   void removeElementAt(int index);

		   bool contains(uint64 oid) const;
		   int size();

		   ManagedReference<SceneObject*> get(int index);
		   ManagedReference<SceneObject*> get(uint64 oid);

		   void put(uint64 oid, SceneObject* object);
		   void drop(uint64 oid);

		   void setContainer(SceneObject* obj);

		   void setDelayedLoadOperationMode();

		   void setNormalLoadOperationMode();

		   bool hasDelayedLoadOperationMode() const;

		   bool isLoaded(bool readLock = true) const;

		   const AtomicTime* getLastAccess() const;

		   ManagedWeakReference<SceneObject*> getContainer() const;

		   void cancelUnloadTask();

		   VectorMap<uint64, uint64>* getOids() const;

		   const VectorMap<uint64, ManagedReference<SceneObject*>>* getContainerObjects() const;

		   friend void to_json(nlohmann::json& k, const ContainerObjectsMap& map);
	   };
	   }
   }
  }
 }
}

using namespace server::zone::objects::scene::variables;
