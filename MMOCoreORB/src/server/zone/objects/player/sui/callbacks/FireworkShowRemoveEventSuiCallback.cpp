#include "FireworkShowRemoveEventSuiCallback.h"

FireworkShowRemoveEventSuiCallback::FireworkShowRemoveEventSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void FireworkShowRemoveEventSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || cancelPressed)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	if (index == -1)
		return;

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);
	uint64 fireworkObjectID = listBox->getMenuObjectID(index);

	ManagedReference<FireworkObject*> firework = (server->getObject(fireworkObjectID)).castTo<FireworkObject*>();

	if (firework == nullptr || !firework->isFireworkObject())
		return;

	ManagedReference<SceneObject*> fireworkShow = suiBox->getUsingObject().get();

	if (fireworkShow == nullptr || !fireworkShow->isFireworkObject())
		return;

	DataObjectComponent* data = fireworkShow->getDataObjectComponent()->get();

	if (data == nullptr || !data->isFireworkShowData())
		return;

	FireworkShowDataComponent* fireworkShowData = cast<FireworkShowDataComponent*>(data);

	int fireworkIndex = fireworkShowData->getIndexOfFirework(firework);

	if (fireworkIndex == -1)
		return;

	fireworkShowData->removeFirework(fireworkIndex);

	ManagedReference<SceneObject*> inventory = player->getSlottedObject("inventory");

	inventory->transferObject(firework, -1, false);
	firework->sendTo(player, true);

	ManagedReference<TangibleObject*> fireworkShowObject = fireworkShow.castTo<TangibleObject*>();

	if (fireworkShowObject != nullptr) {
		Locker locker(fireworkShowObject);
		fireworkShowObject->decreaseUseCount();
	}

	FireworkShowMenuComponent* showMenu = cast<FireworkShowMenuComponent*>(fireworkShow->getObjectMenuComponent());
	showMenu->removeEvent(player, fireworkShow.castTo<FireworkObject*>());
}