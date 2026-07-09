#include "PetFixSuiCallback.h"
#include "server/zone/objects/creature/ai/Creature.h"

PetFixSuiCallback::PetFixSuiCallback(ZoneServer* server, PetControlDevice* device) : SuiCallback(server) {
	controlDevice = device;
}

void PetFixSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
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
	ManagedReference<PetDeed*> deed = pet->getPetDeed();
	Locker lock(pet, player);

	if (otherPressed) {
		deed->adjustPetLevel(player, pet);
	} else {
		if (deed->adjustPetStats(player, pet)) {
			Locker locker(device);
			device->growPet(player, true);
		}
	}

	device->sendAttributeListTo(player);
}