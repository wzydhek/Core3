#include "ResourceAttribute.h"

/**
 * Constructor
 * \param n Name of the Attribute
 * \param min Minimum Value
 * \param max Maximum Value
 */
ResourceAttribute::ResourceAttribute(const String& n, const int min, const int max) {
	name = n;
	minimum = min;
	maximum = max;
	index = 0;

	setIndex(name);
}

/**
 * Destructor
 */
ResourceAttribute::~ResourceAttribute() {
}

void ResourceAttribute::setIndex(const String& name) {
	if (name == "res_decay_resist")
		index = CraftingManager::DR;
	else if (name == "res_quality")
		index = CraftingManager::OQ;
	else if (name == "res_flavor")
		index = CraftingManager::FL;
	else if (name == "res_potential_energy")
		index = CraftingManager::PE;
	else if (name == "res_malleability")
		index = CraftingManager::MA;
	else if (name == "res_toughness")
		index = CraftingManager::UT;
	else if (name == "res_shock_resistance")
		index = CraftingManager::SR;
	else if (name == "res_conductivity")
		index = CraftingManager::CD;
	else if (name == "res_cold_resist")
		index = CraftingManager::CR;
	else if (name == "res_heat_resist")
		index = CraftingManager::HR;
}

/**
 * Returns the name of the Attribute
 */
const String& ResourceAttribute::getName() const {
	return name;
}

/**
 * Returns the minimum value of the Attribute
 */
int ResourceAttribute::getMinimum() const {
	return minimum;
}

/**
 * Returns the maximum value of the Attribute
 */
int ResourceAttribute::getMaximum() const {
	return maximum;
}

int ResourceAttribute::getIndex() const {
	return index;
}