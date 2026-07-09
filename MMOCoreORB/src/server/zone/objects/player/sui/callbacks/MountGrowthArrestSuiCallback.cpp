#include "MountGrowthArrestSuiCallback.h"
#include "server/zone/objects/creature/ai/Creature.h"

MountGrowthArrestSuiCallback::MountGrowthArrestSuiCallback(ZoneServer* server, PetControlDevice* device) : SuiCallback(server) {
	controlDevice = device;
}

void MountGrowthArrestSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<PetControlDevice*> device = controlDevice.get();

	if (device == nullptr || cancelPressed)
		return;

	if (args->size() < 1)
		return;

	bool otherPressed = Bool::valueOf(args->get(0).toString());

	ManagedReference<TangibleObject*> controlledObject = device->getControlledObject();

	if (controlledObject == nullptr || !controlledObject->isCreature())
		return;

	ManagedReference<Creature*> pet = cast<Creature*>(controlledObject.get());

	Locker lock(pet, player);

	Locker locker(device);

	if (otherPressed)
		device->growPet(player, true);
	else
		device->arrestGrowth();
}