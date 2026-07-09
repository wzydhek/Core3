#include "RenameVendorSuiCallback.h"

RenameVendorSuiCallback::RenameVendorSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void RenameVendorSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isInputBox())
		return;

	if (args->size() < 1)
		return;

	if (cancelPressed) {
		return;
	}

	String name = args->get(0).toString();

	ManagedReference<SceneObject*> strong = suiBox->getUsingObject().get();

	if (strong == nullptr)
		return;

	TangibleObject* vendor = cast<TangibleObject*>(strong.get());

	if (vendor == nullptr)
		return;

	VendorManager::instance()->handleRenameVendor(player, vendor, name);
}