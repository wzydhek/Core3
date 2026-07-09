#include "server/zone/ZoneServer.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/chat/ChatManager.h"
#include "GuildMailTask.h"

GuildMailTask::GuildMailTask(const String& subject, StringIdChatParameter& body, GuildObject* guild) : guild(guild), body(body), subject(subject) {
	setCustomTaskQueue("slowQueue");
}

void GuildMailTask::run() {
	Vector<uint64> members;

	Locker locker(guild);

	GuildMemberList* memberList = guild->getGuildMemberList();

	if (memberList == nullptr)
		return;

	for (int i = 0; i < memberList->size(); ++i) {
		GuildMemberInfo* gmi = &memberList->get(i);

		if (gmi == nullptr)
			continue;

		members.add(gmi->getPlayerID());
	}

	auto guildName = guild->getGuildName();

	locker.release();

	for (const auto& memberID : members) {
		auto firstName = guild->getZoneServer()->getPlayerManager()->getPlayerName(memberID);

		guild->getZoneServer()->getChatManager()->sendMail(guildName, subject, body, firstName);
	}
}