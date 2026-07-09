#include "GuildStructurePermissionsTask.h"

GuildStructurePermissionsTask::GuildStructurePermissionsTask(BuildingObject* buildingObj, GuildObject* guildObj) {
	weakBuilding = buildingObj;
	weakGuild = guildObj;
}

void GuildStructurePermissionsTask::run() {
	auto building = weakBuilding.get();
	auto guild = weakGuild.get();

	if (building == nullptr || guild == nullptr)
		return;

	auto zone = building->getZone();

	if (zone == nullptr)
		return;

	SortedVector<TreeEntry*> closeObjects;

	CloseObjectsVector* closeVector = (CloseObjectsVector*)building->getCloseObjects();
	closeVector->safeCopyReceiversTo(closeObjects, CloseObjectsVector::PLAYERTYPE);

	for (int i = 0; i < closeObjects.size(); i++) {
		auto targetObject = static_cast<SceneObject*>(closeObjects.get(i));

		if (targetObject == nullptr || !targetObject->isPlayerCreature())
			continue;

		if (!guild->hasMember(targetObject->getObjectID()))
			continue;

		auto player = targetObject->asCreatureObject();

		if (player == nullptr)
			continue;

		building->updateCellPermissionsTo(player);
	}
}