#include "ShuttleBeaconSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

ShuttleBeaconSuiCallback::ShuttleBeaconSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void ShuttleBeaconSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || cancelPressed)
		return;

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);

	ManagedReference<SceneObject*> beacon = listBox->getUsingObject().get();

	if (beacon == nullptr)
		return;

	ManagedReference<ShuttleBeacon*> shuttleBeacon = cast<ShuttleBeacon*>(beacon.get());

	if (shuttleBeacon == nullptr)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	if (index == -1)
		return;

	shuttleBeacon->spawnShuttle(player, index);
}