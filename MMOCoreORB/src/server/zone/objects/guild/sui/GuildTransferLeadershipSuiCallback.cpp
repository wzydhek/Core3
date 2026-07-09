#include "GuildTransferLeadershipSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/guild/GuildManager.h"

GuildTransferLeadershipSuiCallback::GuildTransferLeadershipSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GuildTransferLeadershipSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isInputBox() || cancelPressed)
		return;

	if (args->size() < 1)
		return;

	String newOwnerName = args->get(0).toString();

	ManagedReference<GuildManager*> guildManager = server->getGuildManager();

	if (guildManager == nullptr)
		return;

	guildManager->sendTransferAckTo(player, newOwnerName, suiBox->getUsingObject().get());
}