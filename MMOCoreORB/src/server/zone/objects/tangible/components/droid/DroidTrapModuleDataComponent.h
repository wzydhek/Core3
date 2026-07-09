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

class DroidTrapModuleDataComponent : public BaseDroidModuleComponent {

protected:
	float trapBonus;
	int modules;
	ManagedReference<TangibleObject*> trap;
public:
	static const String EMPTY_TRAP_MESSAGE;

	DroidTrapModuleDataComponent();
	~DroidTrapModuleDataComponent();

	String getModuleName() const;
	void initializeTransientMembers();
	void fillAttributeList(AttributeListMessage* msg, CreatureObject* droid);
	int getBatteryDrain();
	String toString() const;
	// crafting droid module specific
	void onCall();
	void onStore();
	bool isStackable();
	void copy(BaseDroidModuleComponent* other);
	void addToStack(BaseDroidModuleComponent* other);
	void updateCraftingValues(CraftingValues* values, bool firstUpdate);
	void fillObjectMenuResponse(SceneObject* droidObject, ObjectMenuResponse* menuResponse, CreatureObject* player);
	int handleObjectMenuSelect(CreatureObject* player, byte selectedID, PetControlDevice* controller);
	void handleInsertTrap(CreatureObject* player, TangibleObject* trap);
	bool compatibleTrap(CreatureObject*player, uint32 type);
	void handlePetCommand(String cmd, CreatureObject* speaker) ;
	bool toBinaryStream(ObjectOutputStream* stream);
	bool parseFromBinaryStream(ObjectInputStream* stream);
	void decrementTrap();
	ManagedReference<TangibleObject*> getTrap();
	float getTrapBonus();

	void writeJSON(nlohmann::json& j) const;

private:
	int writeObjectMembers(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const String& name);

};

} // droid
} // components
} // tangible
} // objects
} // zone
} // server

using namespace server::zone::objects::tangible::components::droid;
