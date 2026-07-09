/*
 * CreatureTemplate.h
 *
 *  Created on: Oct 9, 2010
 *      Author: dannuic
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/ai/variables/CreatureAttackMap.h"
#include "templates/params/creature/ObjectFlag.h"
#include "templates/tangible/SharedWeaponObjectTemplate.h"
#include "server/zone/managers/loot/lootgroup/LootGroupCollection.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {

class CreatureTemplate : public Object {
protected:
	String templateName;
	String customName;

	unsigned int armor;

	float kinetic;
	float energy;
	float electricity;
	float stun;
	float blast;
	float heat;
	float cold;
	float acid;
	float lightSaber;

	float tamingChance;
	unsigned int ferocity;

	String meatType;
	String boneType;
	String hideType;
	String milkType;

	int milk;
	int hideAmount;
	int boneAmount;
	int meatAmount;

	String objectName;

	uint32 planetMapCategory;
	String mapCategoryName;

	uint32 planetMapSubCategory;
	String mapSubCategoryName;

	int randomNameType;
	bool randomNameTag;
	String socialGroup;
	String faction;
	int mobType;
	String healerType;

	bool tauntable;

	int level;

	float chanceHit;
	int damageMin;
	int damageMax;
	float specialDamageMult;
	int range;
	float attackSpeed;

	float scale;

	int baseXp;
	int baseHAM;
	int baseHAMmax;

	int aggroRadius;
	unsigned int pvpBitmask;
	unsigned int creatureBitmask;
	unsigned int diet;
	int lightsaberColor;

	Vector<int> hues;

	Vector<String> templates;

	LootGroupCollection lootgroups;

	String primaryWeapon;
	String secondaryWeapon;
	String thrownWeapon;

	CreatureAttackMap* primaryAttacks;
	CreatureAttackMap* secondaryAttacks;

	uint32 conversationTemplate;
	uint32 optionsBitmask;
	uint64 customAiMap;

	String patrolPathTemplate;

	String outfit;

	String aiTemplate;
	String defaultWeapon;
	String defaultAttack;

	String controlDeviceTemplate;
	String containerComponentTemplate;

	String reactionStf;
	String personalityStf;

public:
	CreatureTemplate();

	virtual ~CreatureTemplate();

	void readObject(LuaObject* templateData);

	float getKinetic() const;

	float getEnergy() const;

	float getElectricity() const;

	float getStun() const;

	float getBlast() const;

	float getHeat() const;

	float getCold() const;

	float getAcid() const;

	float getLightSaber() const;

	bool isStalker() const;

	bool isBaby() const;

	bool isKiller() const;

	bool isHealer() const;

	bool isPack() const;

	bool isHerd() const;

	float getTame() const;

	const String& getMeatType() const;

	const String& getBoneType() const;

	const String& getHideType() const;

	const String& getMilkType() const;

	const String& getCustomName() const;

	float getMilk() const;

	float getHideMax() const;

	float getBoneMax() const;

	float getMeatMax() const;

	unsigned int getFerocity() const;

	unsigned int getArmor() const;

	const String& getObjectName() const;

	uint32 getPlanetMapCategory() const;

	String getPlanetMapCategoryName() const;

	uint32 getPlanetMapSubCategory() const;

	String getPlanetMapSubCategoryName() const;

	int getRandomNameType() const;

	int getMobType() const;

	bool getRandomNameTag() const;

	const String& getSocialGroup() const;

	uint32 getConversationTemplate() const;

	uint32 getOptionsBitmask() const;

	uint64 getCustomAiMap();

	const String& getFaction() const;

	int getLevel() const;

	float getChanceHit() const;

	float getScale() const;

	int getDamageMin() const;

	int getDamageMax() const;

	float getAttackSpeed() const;

	float getSpecialDamageMult() const;

	int getRange() const;

	int getBaseXp() const;

	int getBaseHAM() const;

	int getBaseHAMmax() const;

	int getRandomHue() const;

	int getHueCount() const;

	int getTotalHues() const;

	int getAggroRadius() const;

	uint32 getPvpBitmask() const;

	uint32 getCreatureBitmask() const;

	uint32 getDiet() const;

	bool isTauntable() const;

	int getLightsaberColor() const;

	const Vector<String>& getTemplates() const;

	const LootGroupCollection* getLootGroups() const;

	const String& getPrimaryWeapon() const;

	const String& getSecondaryWeapon() const;

	const String& getThrownWeapon() const;

	const CreatureAttackMap* getPrimaryAttacks() const;

	const CreatureAttackMap* getSecondaryAttacks() const;

	const String& getPatrolPathTemplate() const;

	void setTemplateName(const String& t);

	const String& getTemplateName() const;

	String& getTemplateName();

	bool hasPatrolPathTemplate() const;

	const String& getOutfit() const;

	const String& getAiTemplate() const;

	const String& getDefaultWeapon() const;

	const String& getDefaultAttack() const;

	const String& getControlDeviceTemplate() const;

	const String& getContainerComponentTemplate() const;

	const String& getReactionStf() const;

	const String& getPersonalityStf() const;

	const String& getHealerType() const;

	bool isSpecialProtection(int resistType) const;
};

}
}
}
}
}

using namespace server::zone::objects::creature::ai;
