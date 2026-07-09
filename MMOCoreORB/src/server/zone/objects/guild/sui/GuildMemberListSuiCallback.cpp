#include "GuildMemberListSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

GuildMemberListSuiCallback::GuildMemberListSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void GuildMemberListSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || cancelPressed)
		return;

	ManagedReference<GuildManager*> guildManager = server->getGuildManager();

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	if (index == -1)
		return;

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject().get();

	if (obj == nullptr || !obj->isTerminal())
		return;

	Terminal* terminal = cast<Terminal*>(obj.get());

	if (!terminal->isGuildTerminal())
		return;

	GuildTerminal* guildTerminal = cast<GuildTerminal*>(terminal);

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);

	uint64 memberID = listBox->getMenuObjectID(index);

	ManagedReference<GuildObject*> guild = player->getGuildObject().get();
	if (guild == nullptr)
		return;

	if (!guild->hasMember(player->getObjectID()) && !player->getPlayerObject()->isPrivileged()) {
		player->sendSystemMessage("@guild:generic_fail_no_permission"); // You do not have permission to perform that operation.
		return;
	}

	guildManager->sendGuildMemberOptionsTo(player, guild, memberID, guildTerminal);
}