#include "UplinkTerminalResetTask.h"

UplinkTerminalResetTask::UplinkTerminalResetTask(BuildingObject* base, GCWManager* gcwMan, DestructibleBuildingDataComponent* bData) {
	building = base;
	gcwManager = gcwMan;
	baseData = bData;
}

void UplinkTerminalResetTask::run() {
	if (building == nullptr || gcwManager == nullptr || baseData == nullptr) {
		return;
	}

	if (gcwManager->isShutdownSequenceStarted(building) || gcwManager->isFacilityRebooting(building)) {
		reschedule(15 * 60 * 1000); // If base is rebooting or entered destruction sequence the task is rescheduled 15 Minutes
		return;
	}

	gcwManager->renewUplinkBand(building);
	baseData->setState(DestructibleBuildingDataComponent::VULNERABLE);
}