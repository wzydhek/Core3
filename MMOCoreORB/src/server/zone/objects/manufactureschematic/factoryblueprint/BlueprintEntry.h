/*
 * BlueprintEntry.h
 *
 *  Created on: Apr 3, 2011
 *      Author: kyle
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/packets/scene/AttributeListMessage.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace factory {

class FactoryObject;

} // namespace factory
} // namespace installtion
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::factory;

namespace server {
namespace zone {
namespace objects {
namespace manufactureschematic {
namespace factoryblueprint {

/**
 * This class defines a collective entry that makes up a single blueprint item
 * Ex.  If a schematic contains 2 identical ingredients, they will combine to
 * a single blueprint entry
 */
class BlueprintEntry : public Serializable {
private:

	/// Type of resource
	SerializableString type;

	/// Unique identifier - Resource = spawnName; Component = server script crc
	SerializableString key;

	/// Name to display in UI
	SerializableString displayedName;

	/// Serial number of tangible item
	SerializableString serialNumber;

	/// Designates if this item needs to be identical
	bool identical;

	/// Quantity of ingredient neededs
	int quantity;

	/// Input hopper
	ManagedReference<SceneObject* > inputHopper;

	/// Matching items from factory hopper
	Vector<ManagedReference<TangibleObject*> > matchingHopperItems;

public:

	/// Default Constructor
	BlueprintEntry();

	// Copy ctor
	BlueprintEntry(const BlueprintEntry& entry);

	/// Constructor
	BlueprintEntry(TangibleObject* ingredient, bool isIdentical = false);

	// Deconstructor
	~BlueprintEntry();

	BlueprintEntry& operator=(const BlueprintEntry& entry);
	bool operator==(const BlueprintEntry& entry);

	bool equals(BlueprintEntry* entry);

	friend void to_json(nlohmann::json& j, const BlueprintEntry& p);

	/// Inserts string for ManufactureSchematic attributes
	void insertSchematicAttribute(AttributeListMessage* alm);

	/// Inserts factory ingredient for ingredient list sui
	void insertFactoryIngredient(SuiListBox* ingredientList);

	/// Clear contents
	void clearMatches();

	/// See if this entry has enough resources to continue
	bool hasEnoughResources();

	/// Remove resources from vector
	void removeResources(FactoryObject* factory);

	/// Print internal state
	void print();

	/// If item requires identical
	bool needsIdentical();

	void setIdentical(bool value);

	/// Getter for type
	String getType();

	/// Getter for key
	String getKey();

	/// Getter for serial
	String getSerial();

	/// Getter for displayed name
	String getDisplayedName();

	/// getter for quantity
	int getQuantity();

	void setQuantity(int value);

	/// increase for quantity
	void increaseQuantity(int value);

	/// Add a match to the vector
	void addMatch(TangibleObject* object);

	void setDisplayedName(String value);

	void setType(String value);

	void setKey(String value);

	void setSerial(String value);

	void setHopper(SceneObject* hopper);

private:

	/// Adds members to be serialized
	void addSerializableVariables();
};

void to_json(nlohmann::json& j, const BlueprintEntry& p);

} // namespace factoryblueprint
} // namespace manufactureschematic
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::manufactureschematic::factoryblueprint;
