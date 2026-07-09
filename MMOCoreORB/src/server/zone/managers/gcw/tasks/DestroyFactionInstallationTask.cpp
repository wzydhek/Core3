#include "DestroyFactionInstallationTask.h"

DestroyFactionInstallationTask::DestroyFactionInstallationTask(InstallationObject* inst) {
	installation = inst;
}

void DestroyFactionInstallationTask::run() {
	Zone* zne = installation->getZone();
	if (zne == nullptr)
		return;

	GCWManager* gcwMan = zne->getGCWManager();
	if (gcwMan != nullptr)
		gcwMan->notifyInstallationDestruction(installation);
}