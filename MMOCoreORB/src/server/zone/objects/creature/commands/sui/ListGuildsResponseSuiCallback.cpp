#include "ListGuildsResponseSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/managers/guild/GuildManager.h"

ListGuildsResponseSuiCallback::ListGuildsResponseSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void ListGuildsResponseSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || cancelPressed)
		return;

	if (!player->getPlayerObject()->isPrivileged())
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	if (index == -1)
		return;

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);

	uint64 guildObjectID = listBox->getMenuObjectID(index);

	ManagedReference<SceneObject*> obj = server->getObject(guildObjectID);

	if (obj == nullptr || !obj->isGuildObject())
		return;

	GuildObject* guild = cast<GuildObject*>(obj.get());

	ManagedReference<GuildManager*> guildManager = server->getGuildManager();

	guildManager->sendAdminGuildInfoTo(player, guild);
}