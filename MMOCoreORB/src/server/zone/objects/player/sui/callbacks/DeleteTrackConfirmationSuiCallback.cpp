#include "DeleteTrackConfirmationSuiCallback.h"

DeleteTrackConfirmationSuiCallback::DeleteTrackConfirmationSuiCallback(ZoneServer* server, DroidPlaybackModuleDataComponent* m, int index) : SuiCallback(server) {
	track = index;
	module = m;
}

void DeleteTrackConfirmationSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isMessageBox())
		return;

	SuiMessageBox* listBox = cast<SuiMessageBox*>(suiBox);
	ManagedReference<SceneObject*> object = suiBox->getUsingObject().get();

	if (object == nullptr)
		return;

	DroidObject* droid = cast<DroidObject*>(object.get());

	if (droid == nullptr || module == nullptr || cancelPressed)
		return;

	Locker crosslock(droid, player);
	module->deleteTrack(player, track);
}