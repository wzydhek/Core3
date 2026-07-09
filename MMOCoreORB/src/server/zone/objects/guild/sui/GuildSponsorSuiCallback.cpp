#include "GuildSponsorSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

GuildSponsorSuiCallback::GuildSponsorSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GuildSponsorSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isInputBox() || cancelPressed)
		return;

	if (args->size() < 1)
		return;

	String playerName = args->get(0).toString();

	ManagedReference<GuildManager*> guildManager = server->getGuildManager();

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject().get();

	if (obj == nullptr || !obj->isTerminal())
		return;

	Terminal* terminal = cast<Terminal*>(obj.get());

	if (!terminal->isGuildTerminal())
		return;

	guildManager->sponsorPlayer(player, playerName);
}