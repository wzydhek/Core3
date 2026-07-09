#include "ResourcePool.h"

  /** Constructor
 * \param spawner pointer to the ResourceSpawner object defined in ResourceManager
 */
ResourcePool::ResourcePool(ResourceSpawner* spawner) : Logger("ResourcePool") {
	resourceSpawner = spawner;
	includedResources.setNullValue(nullptr);
	includedResources.setAllowDuplicateInsertPlan();
	setGlobalLogging(true);
	setLogging(true);
}
/**
 * Deconstructor
 */
ResourcePool::~ResourcePool() {
	resourceSpawner = nullptr;
	includedResources.removeAll();
	excludedResources.removeAll();
}

/**
 * Initialize pool to contain needed resources
 */
void ResourcePool::initialize(const String& includes, const String& excludes) {
	StringTokenizer includeTokens(includes);
	includeTokens.setDelimeter(",");

	String token;
	while (includeTokens.hasMoreTokens()) {
		includeTokens.getStringToken(token);
		includedResources.put(token, nullptr);
	}

	StringTokenizer excludeTokens(excludes);
	excludeTokens.setDelimeter(",");

	while (excludeTokens.hasMoreTokens()) {
		excludeTokens.getStringToken(token);
		excludedResources.add(token);
	}
}

// Initialize pool using a table of resource names and a number of occurrences
void ResourcePool::initializeByTable(LuaObject includes, const String& excludes) {
	if (!includes.isValidTable()) {
		info("Error initializing resources, not a valid table.", true);
		return;
	}

	for (int i = 1; i <= includes.getTableSize(); i++) {
		LuaObject resourceNameAndNumber = includes.getObjectAt(i);

		if (resourceNameAndNumber.isValidTable()) {
			String name = includes.getStringAt(1);
			int number = includes.getIntAt(2);

			for (unsigned int j = 1; j <= number; j++) {
				includedResources.put(name, nullptr);
			}
		}

		resourceNameAndNumber.pop();
	}

	String token;
	StringTokenizer excludeTokens(excludes);
	excludeTokens.setDelimeter(",");

	while (excludeTokens.hasMoreTokens()) {
		excludeTokens.getStringToken(token);
		excludedResources.add(token);
	}
}

void ResourcePool::print() {
	for (int i = 0; i < includedResources.size(); ++i) {
		ManagedReference<ResourceSpawn*> spawn = includedResources.elementAt(i).getValue();

		StringBuffer msg;

		if (spawn != nullptr) {
			msg << spawn->getName() << " : " << spawn->getType() << endl;
		} else {
			msg << "EMPTY : " << includedResources.elementAt(i).getKey() << endl;
		}

		info(msg.toString());
	}
}