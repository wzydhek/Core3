#include "VendorMaintSuiCallback.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"

VendorMaintSuiCallback::VendorMaintSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void VendorMaintSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isInputBox() || creature == nullptr || cancelPressed || args->size() <= 0) {
		return;
	}

	try {
		int value = Integer::valueOf(args->get(0).toString());

		ManagedReference<SceneObject*> vendor = sui->getUsingObject().get();

		if (vendor == nullptr)
			return;

		DataObjectComponentReference* data = vendor->getDataObjectComponent();
		if (data == nullptr || data->get() == nullptr || !data->get()->isVendorData()) {
			return;
		}

		VendorDataComponent* vendorData = cast<VendorDataComponent*>(data->get());
		if (vendorData == nullptr) {
			return;
		}

		if (sui->getWindowType() == SuiWindowType::STRUCTURE_VENDOR_PAY) {
			vendorData->handlePayMaintanence(value);
		} else {
			vendorData->handleWithdrawMaintanence(value);
		}

	} catch (Exception& e) {
	}
}