/*
 * 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "BaseDroidModuleComponent.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace droid {

class DroidDetonationModuleDataComponent : public BaseDroidModuleComponent {

protected:
	bool initialized;
	float rating;
	int moduleCount;
	bool started;
	bool mseDroid;
	bool advanced;
public:
	DroidDetonationModuleDataComponent();

	~DroidDetonationModuleDataComponent();

	String getModuleName() const;

	void initializeTransientMembers();

	void fillAttributeList(AttributeListMessage* msg, CreatureObject* droid);

	void fillObjectMenuResponse(SceneObject* droidObject, ObjectMenuResponse* menuResponse, CreatureObject* player);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID, PetControlDevice* controller);

	virtual int getBatteryDrain();

	void deactivate();

	String toString() const;

	void onCall();

	void onStore();

	virtual bool isStackable();

	virtual void addToStack(BaseDroidModuleComponent* other);

	virtual void copy(BaseDroidModuleComponent* other);

	// method for init process
	void updateCraftingValues(CraftingValues* values, bool firstUpdate);

	int calculateDamage(DroidObject* droid);

	bool readyForDetonation();

	void setReadyForDetonation();

	bool countdownInProgress();

	void startCountDown();

	void stopCountDown();

	void setSpecies(int i);

	void initialize(DroidObject* droid);

	virtual bool isDetonationModule();
};

} // droid
} // components
} // tangible
} // objects
} // zone
} // server

using namespace server::zone::objects::tangible::components::droid;
