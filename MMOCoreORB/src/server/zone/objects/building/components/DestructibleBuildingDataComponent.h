/*
 * DestructibleBuildingDataComponent.h
 *
 *  Created on: Oct 22, 2012
 *      Author: pete
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/building/components/BuildingDataComponent.h"
#include "system/util/Vector.h"
#include "server/zone/objects/scene/SceneObject.h"

class DestructibleBuildingDataComponent : public BuildingDataComponent, public Logger {

private:
	Vector<String> dnaStrand;
	Vector<int> dnaLocks;
	String currentDnaChain;

	Vector<int> powerSwitchRules;
	Vector<bool> powerSwitchStates;

	int  intCurrentState; // serialized
	bool terminalDamaged; //serialized
	bool inRepair; // serialized

	Vector<uint64> turretSlots;
	Vector<uint64> minefieldSlots;
	Vector<uint64> scannerSlots;

	Time lastVulnerableTime; // serialized
	Time nextVulnerableTime; // serialized
	Time vulnerabilityEndTime; //serialized
	Time placementTime; // serialized
	Time lastResetTime; // serialized
	int uplinkBand; // secret code used to jam the uplink
	bool activeDefenses;
	bool defenseAddedThisVuln;
	bool terminalsSpawned;
	Vector<ManagedReference<SceneObject*> > baseTerminals;
	Vector<uint64> hackBaseAlarms;
	Vector<uint64> destructBaseAlarms;

public:
	const static int INVULNERABLE = 0;
	const static int VULNERABLE = 1;
	const static int BAND = 2;
	const static int JAMMED = 3;
	const static int SLICED = 4;
	const static int DNA = 5;
	const static int OVERLOADED = 6;
	const static int SHUTDOWNSEQUENCE = 7;
	const static int REBOOTSEQUENCE = 8;

	DestructibleBuildingDataComponent();

	virtual ~DestructibleBuildingDataComponent();

	void writeJSON(nlohmann::json& j) const;

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	bool isVulnerable();

	bool isDestructibleBuildingData();

	int getState();

	Time getLastVulnerableTime();

	Time getNextVulnerableTime();

	Time getVulnerabilityEndTime();

	Time getPlacementTime();

	Time getLastResetTime();

	int getUplinkBand();

	int isTerminalBeingRepaired();

	bool isTerminalDamaged();

	void setState(int state);

	void setLastVulnerableTime(const Time& time);

	void setNextVulnerableTime(const Time& time);

	void setVulnerabilityEndTime(const Time& time);

	void setPlacementTime(Time time);

	void setLastResetTime(Time time);

	void setUplinkBand(int band);

	void setTerminalBeingRepaired(bool val);

	void setTerminalDamaged(bool val);

	void setActiveTurret(int indx, uint64 turretOID);

	void setActiveMinefield(int indx, uint64 minefieldOID);

	void initializeTransientMembers();

	int getTotalTurretCount();

	int getTotalMinefieldCount();

	int getTotalScannerCount();

	bool isTurretSlotOccupied(int indx);

	bool isMinefieldSlotOccupied(int indx);

	bool isScannerSlotOccupied(int idx);

	uint64 getTurretID(int indx);

	uint64 getMinefieldID(int indx);

	uint64 getScannerID(int indx);

	bool hasTurret(uint64 turretID);

	bool hasMinefield(uint64 minefieldOID);

	bool hasScanner(uint64 minefieldOID);

	bool hasDefense(uint64 defenseOID);

	int getIndexOfTurret(uint64 turretID);

	int getIndexOfMinefield(uint64 minefieldOID);

	int getIndexOfScanner(uint64 scannerOID);

	void setTurretID(int indx, uint64 turretOID);

	void setScannerID(int indx, uint64 scannerOID);

	void setMinefieldID(int indx, uint64 minefieldOID);

	void addScanner(int indx, uint64 scannerOID);

	void addTurret(int indx, uint64 turretOID);

	void addMinefield(int indx, uint64 minefieldOID);

	bool isGCWBaseData();

	bool hasDefense();

	void setDefense(bool value);

	bool wasDefenseAddedThisVuln();

	void setDefenseAddedThisVuln(bool added);

	void clearDnaStrand();

	void setDnaStrand(const Vector<String>& strand);

	const Vector<String>& getDnaStrand();

	void clearDnaLocks();

	void setDnaLocks(const Vector<int>& locks);

	const Vector<int>& getDnaLocks() const;

	Vector<int>& getDnaLocks();

	const String& getCurrentDnaChain();

	void setCurrentDnaChain(const String& chain);

	const Vector<int>& getPowerSwitchRules();

	void setPowerSwitchRules(const Vector<int>& rules);

	const Vector<bool>& getPowerSwitchStates();

	void setPowerSwitchStates(const Vector<bool>& states);

	bool getPowerPosition(int indx);

	int getBaseTerminalCount();

	SceneObject* getBaseTerminal(int idx);

	void addBaseTerminal(SceneObject* term);

	void clearBaseTerminals();

	bool areTerminalsSpawned();

	void setTerminalsSpawned(bool val);

	Vector<uint64> getHackAlarms();

	Vector<uint64> getDestructAlarms();

	void addHackBaseAlarm(uint64 alarmID);

	void addDestructBaseAlarm(uint64 alarmID);

private:

	int writeObjectMembers(ObjectOutputStream* stream);
	bool readObjectMember(ObjectInputStream* stream, const String& name);
};
