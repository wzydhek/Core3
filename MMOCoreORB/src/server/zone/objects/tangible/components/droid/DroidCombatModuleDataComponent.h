/*
 * 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "BaseDroidModuleComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace droid {

class DroidCombatModuleDataComponent : public BaseDroidModuleComponent {

protected:
	float rating;

public:
	DroidCombatModuleDataComponent();

	~DroidCombatModuleDataComponent();

	String getModuleName() const;

	void initializeTransientMembers();

	void fillAttributeList(AttributeListMessage* msg, CreatureObject* droid);

	int getBatteryDrain();

	String toString() const;

	bool isStackable();

	void copy(BaseDroidModuleComponent* other);

	void addToStack(BaseDroidModuleComponent* other);

	void updateCraftingValues(CraftingValues* values, bool firstUpdate);

	void initialize(DroidObject* droid);

	bool isCombatModule();
};

} // droid
} // components
} // tangible
} // objects
} // zone
} // server

using namespace server::zone::objects::tangible::components::droid;
