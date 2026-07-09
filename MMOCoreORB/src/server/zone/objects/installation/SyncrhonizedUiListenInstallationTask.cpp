#include "SyncrhonizedUiListenInstallationTask.h"

SyncrhonizedUiListenInstallationTask::SyncrhonizedUiListenInstallationTask(InstallationObject* inso) : Task(5000), Logger("SyncrhonizedUiListenInstallationTask") {
	installation = inso;
}

void SyncrhonizedUiListenInstallationTask::run() {
	ManagedReference<InstallationObject*> strongRef = installation.get();

	if (strongRef == nullptr)
		return;

	Locker locker(strongRef);

	try {
		if (strongRef->getZone() == nullptr)
			return;

		strongRef->updateInstallationWork();
		// strongRef->updateOperators();
		strongRef->verifyOperators();
		strongRef->activateUiSync();

	} catch (Exception& e) {
		error(e.getMessage());
		e.printStackTrace();
	}
}