#include "OverrideTerminalSuiCallback.h"
#include "server/zone/Zone.h"

OverrideTerminalSuiCallback::OverrideTerminalSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void OverrideTerminalSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed || !suiBox->isListBox() || player == nullptr || args->size() <= 0)
		return;

	if (player->isDead() || player->isIncapacitated())
		return;

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject().get();

	if (obj == nullptr || !obj->isTangibleObject())
		return;

	ManagedReference<TangibleObject*> overrideTerminal = cast<TangibleObject*>(obj.get());

	GCWManager* gcwMan = player->getZone()->getGCWManager();

	if (gcwMan == nullptr)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	gcwMan->processDNASample(player, overrideTerminal, index);
}