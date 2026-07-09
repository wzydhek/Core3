#include "VendorReturnToPositionTask.h"

VendorReturnToPositionTask::VendorReturnToPositionTask(CreatureObject* cr, int va) {
	vendor = cr;
	heading = va;
}

void VendorReturnToPositionTask::run() {
	ManagedReference<CreatureObject*> strongref = vendor.get();

	if (strongref == nullptr)
		return;

	Locker locker(strongref);
	strongref->updateDirection(Math::deg2rad(heading));

	strongref->removePendingTask("vendorreturn");
}