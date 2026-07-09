#include "NameStructureSuiCallback.h"

NameStructureSuiCallback::NameStructureSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void NameStructureSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isInputBox() || cancelPressed || args->size() < 1)
		return;

	ManagedReference<SceneObject*> obj = sui->getUsingObject().get();

	if (obj == nullptr)
		return;

	if (obj->getGameObjectType() == SceneObjectType::PLAYERTERMINALSTRUCTURE) {
		ManagedReference<SceneObject*> root = obj->getRootParent();
		if (root != nullptr)
			obj = root;
	}

	UnicodeString name = args->get(0);

	creature->executeObjectControllerAction(0xC367B461, obj->getObjectID(), name); // nameStructure
}