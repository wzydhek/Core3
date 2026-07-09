#include "PowerRegulatorSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/Zone.h"

PowerRegulatorSuiCallback::PowerRegulatorSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void PowerRegulatorSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed || !suiBox->isListBox() || player == nullptr || args->size() <= 0)
		return;

	if (player->isDead() || player->isIncapacitated())
		return;

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject().get();

	if (obj == nullptr || !obj->isTangibleObject())
		return;

	ManagedReference<TangibleObject*> powerRegulator = cast<TangibleObject*>(obj.get());

	GCWManager* gcwMan = player->getZone()->getGCWManager();

	if (gcwMan == nullptr)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	gcwMan->handlePowerRegulatorSwitch(player, powerRegulator, index);
}