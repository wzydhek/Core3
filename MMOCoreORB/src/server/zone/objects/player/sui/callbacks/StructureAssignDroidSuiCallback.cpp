#include "StructureAssignDroidSuiCallback.h"
#include "server/zone/Zone.h"

StructureAssignDroidSuiCallback::StructureAssignDroidSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void StructureAssignDroidSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || cancelPressed)
		return;

	if (args->size() < 1) {
		return;
	}

	ManagedReference<SceneObject*> object = suiBox->getUsingObject().get();
	if (object == nullptr || !object->isStructureObject())
		return;

	SuiListBox* suiListBox = cast<SuiListBox*>(suiBox);
	int index = Integer::valueOf(args->get(0).toString());
	uint64 itemId = suiListBox->getMenuObjectID(index);

	StructureObject* structure = cast<StructureObject*>(object.get());
	ManagedReference<Zone*> zone = structure->getZone();
	if (zone == nullptr)
		return;
	// fetch the module object by id
	Reference<DroidObject*> droid = zone->getZoneServer()->getObject(itemId).castTo<DroidObject*>();
	// Creature is already locked (done in handleSuiEventNotification in SuiManager).

	if (droid == nullptr)
		return;

	Locker _lock(droid, player);
	if (droid->isStructureAssigned(structure)) {
		player->sendSystemMessage("@player_structure:structure_on_list");
		return;
	}
	bool b = droid->assignStructure(structure);
	if (!b) {
		// droid full
		player->sendSystemMessage("@player_structure:droid_full");
		return;
	} else {
		StringBuffer buff;
		buff << droid->getDisplayedName();
		buff << " has been assigned to maintain ";
		buff << structure->getDisplayedName() << ".";
		player->sendSystemMessage(buff.toString());
		return;
	}
}