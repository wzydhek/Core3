/*
 * JediQueueCommand.h
 *
 *  Created on: Apr 9, 2015
 *      Author: valkyra
 */

#pragma once

#include "QueueCommand.h"

class JediQueueCommand : public QueueCommand {

protected:
	int forceCost;
	int duration;
	uint32 animationCRC;
	String clientEffect;
	float speedMod;
	int visMod;
	int buffClass;
	float frsLightForceCostModifier;
	float frsDarkForceCostModifier;
	float frsDarkExtraForceCostModifier;
	float frsLightExtraForceCostModifier;
	float frsLightBuffModifier;
	float frsDarkBuffModifier;
	float frsLightForcePowerModifier;
	float frsDarkForcePowerModifier;

	uint32 buffCRC;
	Vector<uint32> overrideableCRCs;
	Vector<uint32> blockingCRCs;
	Vector<unsigned int> singleUseEventTypes;


public:
	enum { BASE_BUFF, SINGLE_USE_BUFF };

	JediQueueCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool isJediQueueCommand() const;

	int doJediSelfBuffCommand(CreatureObject* creature) const;

	int doBuff(CreatureObject* creature) const;

	int doJediForceCostCheck(CreatureObject* creature) const;

	int doCommonJediSelfChecks(CreatureObject* creature) const;

	ManagedReference<Buff*> createJediSelfBuff(CreatureObject* creature) const;

	int getFrsModifiedBuffValue(CreatureObject* player, int amount) const;

	int getFrsModifiedForceCost(CreatureObject* creature) const;

	float getFrsModifiedExtraForceCost(CreatureObject* creature, float val) const;

	void doForceCost(CreatureObject* creature) const;

	void setForceCost(int fc);

	void setDuration(int dur);

	void setAnimationCRC(uint32 crc);

	void setClientEffect(String ce);

	void setSpeedMod(float sm);

	void setBuffClass(int bt);

	void setVisMod(int vm);

	int getVisMod() const;

	void setFrsLightForceCostModifier(float val);

	void setFrsDarkForceCostModifier(float val);

	void setFrsDarkExtraForceCostModifier(float val);

	void setFrsLightExtraForceCostModifier(float val);

	void setFrsLightBuffModifier(float val);

	void setFrsDarkBuffModifier(float val);

	void setFrsLightForcePowerModifier(float val);

	void setFrsDarkForcePowerModifier(float val);
};
