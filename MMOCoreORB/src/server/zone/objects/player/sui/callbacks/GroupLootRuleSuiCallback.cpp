#include "GroupLootRuleSuiCallback.h"

GroupLootRuleSuiCallback::GroupLootRuleSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GroupLootRuleSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	// Pre: player is locked
	// Post: player is locked

	if (cancelPressed || !suiBox->isListBox() || player == nullptr || args->size() <= 0)
		return;

	int selection = Integer::valueOf(args->get(0).toString()); // The row number they chose in the list.

	if (selection < 0) // Player made no selection but pressed OK.
		return;

	ManagedReference<GroupObject*> group = player->getGroup();
	if (group == nullptr)
		return;

	Locker glocker(group, player);

	if (group->getLeader() != player)
		return;

	GroupManager::instance()->changeLootRule(group, selection);
}