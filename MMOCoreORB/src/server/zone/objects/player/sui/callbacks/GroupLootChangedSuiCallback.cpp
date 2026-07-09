#include "GroupLootChangedSuiCallback.h"

GroupLootChangedSuiCallback::GroupLootChangedSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GroupLootChangedSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed || player == nullptr)
		return;

	// Player clicked "Leave Group" on notification box.
	ManagedReference<GroupObject*> group = player->getGroup();
	if (group == nullptr)
		return;

	GroupManager::instance()->leaveGroup(group.get(), player);
}