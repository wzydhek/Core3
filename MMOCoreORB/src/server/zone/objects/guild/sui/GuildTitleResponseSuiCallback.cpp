#include "GuildTitleResponseSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

GuildTitleResponseSuiCallback::GuildTitleResponseSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GuildTitleResponseSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isInputBox() || cancelPressed)
		return;

	if (args->size() < 1)
		return;

	String title = args->get(0).toString();

	ManagedReference<GuildManager*> guildManager = server->getGuildManager();

	if (guildManager == nullptr)
		return;

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject().get();

	if (obj == nullptr || !obj->isPlayerCreature())
		return;

	CreatureObject* target = cast<CreatureObject*>(obj.get());

	guildManager->setMemberTitle(player, target, title);
}