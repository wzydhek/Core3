#include "DestroyVendorSuiCallback.h"

DestroyVendorSuiCallback::DestroyVendorSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void DestroyVendorSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isMessageBox() || cancelPressed)
		return;

	if (args->size() < 1)
		return;

	ManagedReference<SceneObject*> object = suiBox->getUsingObject().get();

	if (object == nullptr || !object->isVendor())
		return;

	TangibleObject* vendor = cast<TangibleObject*>(object.get());

	if (vendor == nullptr)
		return;

	Locker clocker(vendor, player);

	TransactionLog trx(player, vendor, TrxCode::VENDORLIFECYCLE);

	if (trx.isVerbose()) {
		// Force a synchronous export because the object will be deleted before we can export it!
		trx.addRelatedObject(object, true);
		trx.setExportRelatedObjects(true);
		trx.exportRelated();
	}

	VendorManager::instance()->destroyVendor(vendor);
}