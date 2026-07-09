#include "StructureSelectSignSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/Zone.h"

StructureSelectSignSuiCallback::StructureSelectSignSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void StructureSelectSignSuiCallback::run(CreatureObject* creature, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || cancelPressed)
		return;

	if (args->size() < 1)
		return;

	ManagedReference<SceneObject*> object = suiBox->getUsingObject().get();
	if (object == nullptr || !object->isBuildingObject())
		return;

	SuiListBox* suiListBox = cast<SuiListBox*>(suiBox);
	int index = Integer::valueOf(args->get(0).toString());

	if (index < 0 || index >= suiListBox->getMenuSize())
		return;

	String suiItem = suiListBox->getMenuItemName(index);

	StructureObject* structure = cast<StructureObject*>(object.get());
	ManagedReference<Zone*> zone = structure->getZone();
	if (zone == nullptr)
		return;

	// Creature is already locked (done in handleSuiEventNotification in SuiManager).
	Locker _lock(structure, creature);

	// Set the sign
	StructureManager::instance()->setSign(structure, creature, suiItem);
}