#include "UpdateWarStatusTask.h"

UpdateWarStatusTask::UpdateWarStatusTask(ZoneServer* zserv, GuildObject* guild, GuildObject* waringGuild) : Task() {
	guild1 = *guild->getGuildMemberList();
	guild2 = *waringGuild->getGuildMemberList();

	server = zserv;
}

void UpdateWarStatusTask::run() {
	PlayerManager* playerManager = server->getPlayerManager();
	ChatManager* chatManager = server->getChatManager();

	// Get online members
	SortedVector<ManagedReference<CreatureObject*>> onlineMembers1;
	SortedVector<ManagedReference<CreatureObject*>> onlineMembers2;

	for (int i = 0; i < guild1.size(); ++i) {
		VectorMapEntry<uint64, GuildMemberInfo>* entry = &guild1.elementAt(i);

		auto memberName = playerManager->getPlayerName(entry->getKey());

		auto creo = chatManager->getPlayer(memberName);

		if (creo == nullptr || !creo->isPlayerCreature())
			continue;

		onlineMembers1.put(creo);
	}

	for (int j = 0; j < guild2.size(); ++j) {
		VectorMapEntry<uint64, GuildMemberInfo>* entry2 = &guild2.elementAt(j);

		auto member2Name = playerManager->getPlayerName(entry2->getKey());

		auto creo2 = chatManager->getPlayer(member2Name);

		if (creo2 == nullptr || !creo2->isPlayerCreature())
			continue;

		onlineMembers2.put(creo2);
	}

	for (int i = 0; i < onlineMembers1.size(); ++i) {
		CreatureObject* creo = onlineMembers1.get(i);

		for (int j = 0; j < onlineMembers2.size(); ++j) {
			CreatureObject* creo2 = onlineMembers2.get(j);

			if (creo->isInRange(creo2, ZoneServer::CLOSEOBJECTRANGE)) {
				creo->sendPvpStatusTo(creo2);
				creo2->sendPvpStatusTo(creo);
			}
		}
	}
}