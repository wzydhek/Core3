/*
 * FactoryBlueprint.h
 *
 *  Created on: Apr 3, 2011
 *      Author: kyle
 */

#pragma once

#include "engine/engine.h"
#include "BlueprintEntry.h"
#include "server/zone/objects/installation/factory/FactoryObject.h"

namespace server {
namespace zone {
namespace objects {
namespace manufactureschematic {
namespace factoryblueprint {

class FactoryBlueprint  : public Serializable  {
private:
	Vector<BlueprintEntry> completeEntries;
	Vector<BlueprintEntry> consolidatedEntries;
public:
	FactoryBlueprint();
	FactoryBlueprint(const FactoryBlueprint& blueprint);

	~FactoryBlueprint();

	FactoryBlueprint& operator=(const FactoryBlueprint& blueprint);

	void addIngredient(SceneObject* ingredient, int quantity, bool isIdentical);

	void addConsolidatedEntry(BlueprintEntry* entry);

	BlueprintEntry* getConsolidatedEntry(int i);

	int getConsolidatedSize();

	BlueprintEntry* getCompleteEntry(int i);

	int getCompleteSize();

	void canManufactureItem(String &type, String &displayedName);

	void manufactureItem(FactoryObject* factory);

	void addSerializableVariables();

	void print();

	friend void to_json(nlohmann::json& j, const FactoryBlueprint& p);
};

} // namespace factoryblueprint
} // namespace manufactureschematic
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::manufactureschematic::factoryblueprint;
