#include "GuildWarEnemyNameSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

GuildWarEnemyNameSuiCallback::GuildWarEnemyNameSuiCallback(ZoneServer* server, GuildObject* guild) : SuiCallback(server) {
	guildObject = guild;
}

void GuildWarEnemyNameSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isInputBox() || player == nullptr || args->size() <= 0 || cancelPressed)
		return;

	String value = args->get(0).toString();

	server->getGuildManager()->declareWarByName(player, guildObject.get(), value);
}