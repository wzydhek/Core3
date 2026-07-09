#include "SquadLeaderCommand.h"
#include "templates/params/creature/CreatureAttribute.h"

SquadLeaderCommand::SquadLeaderCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
	combatSpam = "";
	action = "";
	actionCRC = 0;
}

int SquadLeaderCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return SUCCESS;
}

bool SquadLeaderCommand::checkGroupLeader(CreatureObject* player, GroupObject* group) const {
	if (player == nullptr)
		return false;

	if (group == nullptr) {
		player->sendSystemMessage("@error_message:not_grouped");
		return false;
	}

	if (group->getLeader() == nullptr) {
		player->sendSystemMessage("@error_message:not_group_leader");
		return false;
	}

	if (group->getLeader() != player) {
		player->sendSystemMessage("@error_message:not_group_leader");
		return false;
	}

	return true;
}

bool SquadLeaderCommand::isValidGroupAbilityTarget(CreatureObject* leader, CreatureObject* target, bool allowPet) {
	if (target == nullptr || target->isDead() || target->isIncapacitated()) {
		return false;
	}

	if (allowPet) {
		if (!target->isPlayerCreature() && !target->isPet()) {
			return false;
		}
	} else if (!target->isPlayerCreature()) {
		return false;
	}

	if (target == leader)
		return true;

	if (leader->getZone() != target->getZone())
		return false;

	CreatureObject* targetCreo = target;

	if (allowPet && target->isPet()) {
		targetCreo = target->getLinkedCreature().get();

		if (targetCreo == nullptr)
			return false;
	}

	// Use healing checks
	if (!targetCreo->isHealableBy(leader))
		return false;

	if (target->getParentRecursively(SceneObjectType::BUILDING) != leader->getParentRecursively(SceneObjectType::BUILDING))
		return false;

	return true;
}

float SquadLeaderCommand::calculateGroupModifier(GroupObject* group) const {
	if (group == nullptr)
		return 0;

	float modifier = 1.0f + ((float)(group->getGroupSize()) / 20.0f);

	return modifier;
}

bool SquadLeaderCommand::inflictHAM(CreatureObject* player, int health, int action, int mind) const {
	if (player == nullptr)
		return false;

	if (health < 0 || action < 0 || mind < 0)
		return false;

	if (player->getHAM(CreatureAttribute::ACTION) <= action || player->getHAM(CreatureAttribute::HEALTH) <= health || player->getHAM(CreatureAttribute::MIND) <= mind)
		return false;

	if (health > 0)
		player->inflictDamage(player, CreatureAttribute::HEALTH, health, true);

	if (action > 0)
		player->inflictDamage(player, CreatureAttribute::ACTION, action, true);

	if (mind > 0)
		player->inflictDamage(player, CreatureAttribute::MIND, mind, true);

	return true;
}

void SquadLeaderCommand::sendCombatSpam(CreatureObject* player) const {
	if (player == nullptr)
		return;

	if (combatSpam == "")
		return;

	player->sendSystemMessage("@cbt_spam:" + combatSpam);
}

bool SquadLeaderCommand::isSquadLeaderCommand() {
	return true;
}

float SquadLeaderCommand::getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const {
	return defaultTime;
}

const String& SquadLeaderCommand::getAction() const {
	return action;
}

void SquadLeaderCommand::setAction(String action) {
	this->action = action;
}