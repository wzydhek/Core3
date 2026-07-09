#include "DestroyCommandSuiCallback.h"

DestroyCommandSuiCallback::DestroyCommandSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void DestroyCommandSuiCallback::run(CreatureObject* creature, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isMessageBox() || cancelPressed)
		return;

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject().get();

	if (obj == nullptr)
		return;

	if (obj->isPlayerCreature()) {
		creature->sendSystemMessage("Destroying players with this command is prohibited.");
		return;
	}

	obj->destroyObjectFromWorld(true);

	obj->destroyObjectFromDatabase(true);

	creature->sendSystemMessage("The object has been successfully destroyed from the database.");
}