/*
 * ShipAgentTemplate.h
 *
 *  Created on: 2024/11/01
 *  Author: Hakry
 */

#pragma once

#include "engine/engine.h"
#include "templates/params/ship/ShipFlag.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {

class ShipAgentTemplate : public Object {
protected:
	String templateName;

	String shipTemplate;
	String pilotTemplate;
	String shipType;

	int experience;

	float lootChance;
	int lootRolls;
	String lootTable;

	int minCredits;
	int maxCredits;

	int aggressive;

	String spaceFaction;
	Vector<String> alliedFactions;
	Vector<String> enemyFactions;

	int imperialFactionReward;
	int rebelFactionReward;

	int color1;
	int color2;
	int texture;

	String questLoot;
	String interiorChassis;
	int formationLocation;
	String appearance;

	String tauntType;
	float tauntAttackChance;
	float tauntDefendChance;
	float tauntDieChance;
	float tauntAggressiveness;

	unsigned int pvpBitmask;
	unsigned int shipBitmask;
	uint32 optionsBitmask;

	uint64 customShipAiMap;

	uint32 conversationTemplate;
	uint32 conversationMobile;
	uint32 conversationMessage; // Too Far Message

	String cargoString;

public:
	ShipAgentTemplate();

	virtual ~ShipAgentTemplate();

	void readObject(LuaObject* templateData);

	void setTemplateName(const String& t);

	// Accessors
	String getTemplateName() const;

	String getShipTemplate() const;

	String getPilotTemplate() const;

	String getShipType() const;

	int getExperience() const;

	float getLootChance() const;

	int getLootRolls() const;

	String getLootTable() const;

	int getMinCredits() const;

	int getMaxCredits() const;

	int getAggressive() const;

	String getSpaceFaction() const;

	int getTotalAlliedFactions() const;

	String getAlliedFaction(int index) const;

	int getTotalEnemyFactions() const;

	String getEnemyFaction(int index) const;

	int getImperialFactionReward() const;

	int getRebelFactionReward() const;

	int getColor1() const;

	int getColor2() const;

	int getTexture() const;

	String getQuestLoot() const;

	String getInteriorChassis() const;

	int getFormationLocation() const;

	String getAppearance() const;

	String getTauntType() const;

	float getTauntAttackChance() const;

	float getTauntDefendChance() const;

	float getTauntDieChance() const;

	float getTauntAggressiveness() const;

	uint32 getPvpBitmask() const;

	uint32 getShipBitmask() const;

	uint32 getOptionsBitmask() const;

	uint64 getCustomShipAiMap() const;

	uint32 getConversationTemplate() const;

	uint32 getConversationMobile() const;

	uint32 getConversationMessage() const;

	String getCargoString() const;
};

} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai;
