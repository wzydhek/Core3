/*
 * CreatureTemplateMap.h
 *
 *  Created on: Oct 8, 2010
 *      Author: dannuic
 */

#pragma once

#include "server/zone/objects/creature/ai/CreatureTemplate.h"
#include "server/zone/objects/creature/conversation/ConversationTemplate.h"
#include "templates/mobile/LairTemplate.h"
#include "templates/mobile/PatrolPathTemplate.h"
#include "templates/mobile/MobileOutfitGroup.h"
#include "SpawnGroup.h"
#include "AiSpeciesData.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class CreatureTemplateManager : public Singleton<CreatureTemplateManager>, public Object, public Logger {
protected:
	VectorMap<uint32, Vector<String> > weaponMap;
	VectorMap<uint32, Vector<String> > dressMap;
	Vector<Reference<AiSpeciesData*> > aiSpeciesData;
	Reference<Lua*> lua;
	HashTable<uint32, Reference<CreatureTemplate*> > hashTable;

	HashTable<uint32, Reference<ConversationTemplate*> > conversations;

	HashTable<uint32, Reference<LairTemplate*> > lairTemplates;
	HashTable<uint32, Reference<SpawnGroup*> > spawnGroupMap;
	HashTable<uint32, Reference<SpawnGroup*> > destroyMissionGroupMap;
	HashTable<String, Reference<PatrolPathTemplate*> > patrolPaths;
	HashTable<String, Reference<MobileOutfitGroup*> > outfits;
	static AtomicInteger loadedMobileTemplates;
	float globalAttackSpeedOverride;

public:
	static int DEBUG_MODE;
	enum LUA_ERROR_CODE { NO_ERROR = 0, GENERAL_ERROR, DUPLICATE_MOBILE, INCORRECT_ARGUMENTS, DUPLICATE_CONVO };
	static int ERROR_CODE;

	CreatureTemplateManager();
	virtual ~CreatureTemplateManager();

	int loadTemplates();
	void loadLuaConfig();
	static int includeFile(lua_State* L);
	static int addTemplate(lua_State* L);
	static int addWeapon(lua_State* L);
	static int addSpawnGroup(lua_State* L);
	static int addDestroyMissionGroup(lua_State* L);
	static int addConversationTemplate(lua_State* L);
	static int addLairTemplate(lua_State* L);
	static int addPatrolPathTemplate(lua_State* L);
	static int addOutfitGroup(lua_State* L);
	static int addDressGroup(lua_State* L);

	static int checkArgumentCount(lua_State* L, int args);

	int size();

	HashTableIterator<uint32, Reference<CreatureTemplate*>> iterator();

	HashTableIterator<uint32, Reference<LairTemplate*>> lairTemplateIterator();

	HashTableIterator<uint32, Reference<SpawnGroup*>> spawnGroupIterator();

	HashTableIterator<uint32, Reference<SpawnGroup*>> destroyMissionGroupIterator();

	CreatureTemplate* getTemplate(uint32 crc);

	PatrolPathTemplate* getPatrolPathTemplate(const String& name);

	CreatureTemplate* getTemplate(const String& ascii);

	MobileOutfitGroup* getMobileOutfitGroup(const String& name);

	ConversationTemplate* getConversationTemplate(const String& name);

	ConversationTemplate* getConversationTemplate(uint32 crc);

	const Vector<String>& getWeapons(uint32 crc);

	const Vector<String>& getWeapons(const String& ascii);

	SpawnGroup* getSpawnGroup(uint32 crc);

	LairTemplate* getLairTemplate(uint32 crc);

	SpawnGroup* getDestroyMissionGroup(uint32 crc);

	AiSpeciesData* getAiSpeciesData(uint32 speciesID);

	const Vector<String>& getDressGroup(uint32 crc);

	const Vector<String>& getDressGroup(const String& ascii);

	float getGlobalAttackSpeedOverride() const;

};

}
}
}
}

using namespace server::zone::managers::creature;
