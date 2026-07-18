/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file ResourcePool.h
 * \author Kyle Burkhardt
 * \date 5-03-10
 */

#pragma once

#include "server/zone/objects/resource/ResourceSpawn.h"

namespace server {
namespace zone {
namespace managers {
namespace resource {
namespace resourcespawner {
class ResourceSpawner;
//namespace resourcepool {

/**
 * Abstract parent of all ResourcePool objects
 */
class ResourcePool : public Logger {

protected:

	/**
	 * List of resources this pool can spawn
	 */
	VectorMap<String, ManagedReference<ResourceSpawn* > > includedResources;

	/**
	 * List of resources this pool can't spawn
	 */
	Vector<String> excludedResources;

	/**
	 * resourceSpawner is a pointer to the ResourceSpawner object defined in ResourceManager.
	 */
	ResourceSpawner* resourceSpawner;

public:

	enum {
		NOPOOL,
		MINIMUMPOOL,
		RANDOMPOOL,
		FIXEDPOOL,
		NATIVEPOOL,
		MANUALPOOL
	};

public:
	  /** Constructor
	   * \param spawner pointer to the ResourceSpawner object defined in ResourceManager
	   */
	ResourcePool(ResourceSpawner* spawner);
	/**
	 * Deconstructor
	 */
	virtual ~ResourcePool();

	/**
	 * Initialize pool to contain needed resources
	 */
	void initialize(const String& includes, const String& excludes);

	//Initialize pool using a table of resource names and a number of occurrences
	void initializeByTable(LuaObject includes, const String& excludes);

	void print();

private:
	/**
	 * Remove expired resources and spawn replacements.
	 * \return Whether update completed successfully
	 */
	virtual bool update() = 0;


	/**
	 * Get the position of incoming resource type
	 * This function should only be used when loading
	 * from database.
	 * \param resourceSpawn The resource to add to this pool
	 */
	virtual void addResource(ManagedReference<ResourceSpawn*> resourceSpawn, const String& poolSlot) = 0;

	virtual String healthCheck() = 0;

	friend class ResourceSpawner;
};

//} // namespace resourcepool
} // namespace resourcespawner
} // namespace resource
} // namespace managers
} // namespace zone
} // namespace server

// using namespace server::zone::managers::resource::resourcespawner::resourcepool;
using namespace server::zone::managers::resource::resourcespawner;
