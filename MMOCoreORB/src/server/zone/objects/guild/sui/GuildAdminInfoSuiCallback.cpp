#include "GuildAdminInfoSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

GuildAdminInfoSuiCallback::GuildAdminInfoSuiCallback(ZoneServer* server, GuildObject* guild) : SuiCallback(server) {
	guildObject = guild;
}

void GuildAdminInfoSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isMessageBox() || cancelPressed)
		return;

	uint64 playerID = player->getObjectID();

	ManagedReference<GuildObject*> guild = guildObject.get();

	if (guild == nullptr)
		return;

	if (!guild->hasNamePermission(playerID) && !player->getPlayerObject()->isPrivileged()) {
		player->sendSystemMessage("@guild:generic_fail_no_permission"); // You do not have permission to perform that operation.
		return;
	}

	ManagedReference<GuildManager*> guildManager = server->getGuildManager();

	if (guildManager != nullptr) {
		guildManager->sendGuildChangeNameTo(player, guild);
	}
}