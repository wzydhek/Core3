/*
 * ShipManager.h
 *
 *  Created on: 18/10/2013
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/ship/ShipComponentData.h"
#include "server/zone/objects/ship/ShipProjectileData.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "server/zone/objects/ship/ComponentSlots.h"
#include "server/zone/objects/intangible/ShipControlDevice.h"
#include "server/zone/objects/ship/ShipAppearanceData.h"
#include "server/zone/objects/ship/ShipCollisionData.h"
#include "server/zone/objects/ship/ShipMissileData.h"
#include "server/zone/objects/ship/ShipCountermeasureData.h"
#include "server/zone/objects/ship/components/ShipChassisComponent.h"
#include "server/zone/objects/ship/ShipTurretData.h"
#include "server/zone/managers/ship/DroidCommandData.h"
#include "ShipUniqueIdMap.h"
#include "SpaceSpawnGroup.h"
#include "server/zone/objects/ship/ai/ShipAiAgentPilotData.h"

namespace server {
namespace zone {
namespace managers {
namespace ship {

class ShipManager : public Singleton<ShipManager>, public Object, public Logger {
protected:
	Reference<Lua*> lua;

	HashTable<uint32, Reference<ShipComponentData*>> shipComponents;
	HashTable<String, ShipComponentData*> shipComponentTemplateNames;
	HashTable<String, Reference<ShipAppearanceData*>> shipAppearanceData;
	HashTable<uint32, Reference<ShipProjectileData*>> shipProjectileData;
	HashTable<String, ShipProjectileData*> shipProjectiletTemplateNames;
	HashTable<uint32, Reference<ShipCollisionData*>> shipCollisionData;
	HashTable<String, Reference<ShipChassisData*>> chassisData;
	HashTable<String, Reference<ShipAiAgentPilotData*>> pilotData;

	HashTable<uint32, Reference<ShipMissileData*>> missileData;
	HashTable<uint32, Reference<ShipCountermeasureData*>> countermeasureData;
	VectorMap<String, VectorMap<uint32, Reference<ShipTurretData*>>> turretData;

	VectorMap<String, Vector3> hyperspaceLocations;
	VectorMap<String, String> hyperspaceZones;

	HashTable<uint32, Reference<SpaceSpawnGroup*>> spawnGroupMap;

	HashTable<uint32, Reference<DroidCommandData*>> DroidCommands;

	ShipUniqueIdMap shipUniqueIdMap;

private:
	void loadShipComponentData();
	void loadShipWeaponData();
	void loadShipChassisData();
	void loadHyperspaceLocations();
	void loadShipAppearanceData();
	void loadShipMissileData();
	void loadShipCountermeasureData();
	void loadShipCollisionData();
	void loadShipTurretIffData();
	void loadShipTurretLuaData();
	void loadDroidCommands();
	void loadShipAiAgentPilotData();

public:
	enum {
		SHIP = 0,
		FIGHTERSHIP = 1,
		POBSHIP = 2,
		SPACESTATION = 3
	};

	const static int NO_CERT_COST_MULTI = 5;

	enum LUA_ERROR_CODE {
		NO_ERROR = 0,
		GENERAL_ERROR,
		DUPLICATE_SHIP_MOBILE,
		INCORRECT_ARGUMENTS,
		DUPLICATE_CONVO
	};

	static int ERROR_CODE;

	ShipManager();
	virtual ~ShipManager() {};

	void initialize();
	void stop();

	static int checkArgumentCount(lua_State* L, int args);
	static int includeFile(lua_State* L);
	static int addShipSpawnGroup(lua_State* L);

	bool hyperspaceLocationExists(const String& name) const;

	const Vector3& getHyperspaceLocation(const String& name) const;

	const String& getHyperspaceZone(const String& name) const;

	const ShipComponentData* getShipComponent(const String& name) const;

	const ShipComponentData* getShipComponent(uint32 hash) const;

	const ShipComponentData* getShipComponentFromTemplate(const String& templateName) const;

	const ShipProjectileData* getProjectileData(uint32 hash) const;

	const ShipChassisData* getChassisData(const String& shipName) const;

	const ShipAppearanceData* getAppearanceData(const String& shipName) const;

	const ShipTurretData* getShipTurretData(const String& shipName, uint32 slot) const;

	const ShipCollisionData* getCollisionData(ShipObject* ship);

	const ShipMissileData* getMissileData(uint32 ammoType) const;

	const ShipCountermeasureData* getCountermeasureData(uint32 ammoType) const;

	const ShipAiAgentPilotData* getPilotData(const String& pilotType) const;

	ShipUniqueIdMap* getShipUniqueIdMap();

private:
	int loadShipSpawnGroups();
	void loadShipComponentObjects(ShipObject* ship);
	ShipControlDevice* createShipControlDevice(ShipObject* ship);

public:
	ShipAiAgent* createAiShip(const String& shipName);
	ShipAiAgent* createAiShip(const String& shipName, uint32 shipCRC);
	ShipObject* createPlayerShip(CreatureObject* owner, const String& shipName, const String& certificationRequired, bool loadComponents = false);

	bool createDeedFromChassis(CreatureObject* owner, ShipChassisComponent* chassisBlueprint, CreatureObject* chassisDealer);

	/**
	* @pre { destructor and destructedObject locked }
	* @post { destructor and destructedObject locked }
	* @param destructorShip pre-locked
	* @param destructedShip pre-locked
	*/

	int notifyDestruction(ShipObject* destructorShip, ShipAiAgent* destructedShip, int condition, bool isCombatAction);

	/**
	 * Sends a sui list box containing information about the structure.
	 * @param creature The creature receiving the report.
	 * @param pobShip The pobShip the report is about.
	 */
	void reportPobShipStatus(CreatureObject* creature, PobShipObject* pobShip, SceneObject* terminal);

	/**
	 * Sends a Sui prompt to the player asking if they wish to delete all the items in their ship.
	 * @param creature The player receiving the prompt.
	 * @param pobShip The POB ship that will have all items deleted.
	 */
	void promptDeleteAllItems(CreatureObject* creature, PobShipObject* pobShip);

	/**
	 * Sends a Sui prompt to the player asking if they want to move the first item in the pob ship to their feet.
	 * @param creature The creature who the item will be moved to.
	 * @param pobShip The structure which holds the items.
	 */
	void promptFindLostItems(CreatureObject* creature, PobShipObject* pobShip);

	/**
	 * Sends a Sui prompt to the player asking if they want rename their ship
	 * @param creature The creature who owns the ship
	 * @param the ship control device
	 */
	void promptNameShip(CreatureObject* creature, ShipControlDevice* shipDevice);

	void reDeedShip(CreatureObject* creature, ShipControlDevice* shipDevice);

	HashTableIterator<uint32, Reference<SpaceSpawnGroup*>> spawnGroupIterator();

	SpaceSpawnGroup* getSpaceSpawnGroup(uint32 crc);

	uint16 setShipUniqueID(ShipObject* ship);

	void dropShipUniqueID(ShipObject* ship);

	DroidCommandData* getDroidCommandData(uint32 hashCode) const;
};

} // namespace ship
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::ship;
