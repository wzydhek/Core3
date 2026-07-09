#include "UpdateVendorTask.h"

UpdateVendorTask::UpdateVendorTask(SceneObject* vndr) {
	vendor = vndr;

	setCustomTaskQueue("slowQueue");
}

void UpdateVendorTask::run() {
	ManagedReference<SceneObject*> strongRef = vendor.get();

	if (strongRef == nullptr || strongRef->isBazaarTerminal())
		return;

	Locker locker(strongRef);

	DataObjectComponentReference* data = strongRef->getDataObjectComponent();
	if (data == nullptr || data->get() == nullptr || !data->get()->isVendorData()) {
		return;
	}

	VendorDataComponent* vendorData = cast<VendorDataComponent*>(data->get());
	if (vendorData == nullptr) {
		return;
	}

	setTaskName((strongRef->getLoggingName() + " ran UpdateVendorTask of owner 0x" + String::hexvalueOf(vendorData->getOwnerId())).toCharArray());

	vendorData->runVendorUpdate();
}