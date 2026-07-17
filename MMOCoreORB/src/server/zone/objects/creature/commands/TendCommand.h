/*
 * TendCommand.h
 *
 *  Created on: 13/08/2010
 *      Author: victor
 */

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class TendCommand : public QueueCommand {
protected:
	int mindCost;
	int mindWoundCost;

	int healthHealed;
	int actionHealed;
	int mindHealed;

	uint8 woundPool;
	int woundsHealed;

	bool tendDamage;
	bool tendWound;

	float speed;
	float range;
	String effectName;

public:
	TendCommand(const String& name, ZoneProcessServer* server);

	void doAnimations(CreatureObject* creature, CreatureObject* creatureTarget) const;

	void sendHealMessage(CreatureObject* creature, CreatureObject* creatureTarget, int healthDamage, int actionDamage) const;

	void sendWoundMessage(CreatureObject* creature, CreatureObject* creatureTarget, int poolAffected, int woundsHealed) const;

	void awardXp(CreatureObject* creature, const String& type, int power) const;

	uint8 findAttribute(CreatureObject* creature, uint8 startAttribute = 0) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
