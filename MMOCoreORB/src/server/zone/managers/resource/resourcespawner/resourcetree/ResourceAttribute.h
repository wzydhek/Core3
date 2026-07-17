/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file ResourceAttribute.h
 * \author Kyle Burkhardt
 * \date 5-03-10
 */

#pragma once

#include "server/zone/managers/crafting/CraftingManager.h"

namespace server {
namespace zone {
namespace managers {
namespace resource {
namespace resourcespawner {
namespace resourcetree {

/**
 * The resource attribute class stores the name
 * of a resource attribute and the min / max value
 */
class ResourceAttribute {
private:
	String name;
	int minimum;
	int maximum;
	int index;

public:
	/**
	 * Constructor
	 * \param n Name of the Attribute
	 * \param min Minimum Value
	 * \param max Maximum Value
	 */
	ResourceAttribute(const String& n, const int min, const int max);

	/**
	 * Destructor
	 */
	~ResourceAttribute();

	void setIndex(const String& name);

	/**
	 * Returns the name of the Attribute
	 */
	const String& getName() const;

	/**
	 * Returns the minimum value of the Attribute
	 */
	int getMinimum() const;

	/**
	 * Returns the maximum value of the Attribute
	 */
	int getMaximum() const;

	int getIndex() const;
};

} // namespace resourcetree
} // namespace resourcespawner
} // namespace resource
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::resource::resourcespawner::resourcetree;
