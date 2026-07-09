#include "ClearVeteranRewardCommand.h"
#include "server/login/account/Account.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/PlayerObject.h"

ClearVeteranRewardCommand::ClearVeteranRewardCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ClearVeteranRewardCommand::doQueueCommand(CreatureObject* player, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(player))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(player))
		return INVALIDLOCOMOTION;

	StringTokenizer tokenizer(arguments.toString());
	tokenizer.setDelimeter(" ");

	int milestone = -1;

	if (tokenizer.hasMoreTokens())
		milestone = tokenizer.getIntToken();

	if (milestone < 0) {
		player->sendSystemMessage("SYNTAX: /clearVeteranReward player milestone");
		return INVALIDPARAMETERS;
	}

	ManagedReference<SceneObject*> obj = server->getZoneServer()->getObject(target);
	if (obj == nullptr || !obj->isPlayerCreature()) {
		player->sendSystemMessage("SYNTAX: /clearVeteranReward player milestone");
		return INVALIDPARAMETERS;
	}

	CreatureObject* targetCreature = cast<CreatureObject*>(obj.get());
	PlayerObject* targetGhost = targetCreature->getPlayerObject();

	Locker clocker(targetCreature, player);

	String reward = targetGhost->getChosenVeteranReward(milestone);
	if (reward.isEmpty()) {
		player->sendSystemMessage("Player has not chosen a reward for that milestone");
		return GENERALERROR;
	}

	// Get account
	ManagedReference<Account*> account = targetGhost->getAccount();

	if (account == nullptr) {
		player->sendSystemMessage("Error finding account");
		return GENERALERROR;
	}

	Locker alocker(account);

	// Clear reward in all characters registered to the account

	GalaxyAccountInfo* info = targetGhost->getGalaxyAccountInfo();

	if (info == nullptr)
		return GENERALERROR;

	info->clearVeteranReward(milestone);

	player->sendSystemMessage(targetGhost->getAccount()->getUsername() + "'s " + String::valueOf(milestone) + "-day reward has been cleared");

	return SUCCESS;
}