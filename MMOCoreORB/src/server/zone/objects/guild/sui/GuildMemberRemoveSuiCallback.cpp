#include "GuildMemberRemoveSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

GuildMemberRemoveSuiCallback::GuildMemberRemoveSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GuildMemberRemoveSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);
	if (!suiBox->isMessageBox() || cancelPressed)
		return;

	ManagedReference<GuildManager*> guildManager = server->getGuildManager();

	if (guildManager == nullptr)
		return;

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject().get();

	if (obj == nullptr || !obj->isPlayerCreature())
		return;

	CreatureObject* target = cast<CreatureObject*>(obj.get());

	guildManager->kickMember(player, target);
}