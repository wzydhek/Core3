/*
 * DestuctibleBuildingDataComponent.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: pete
 */
#include "DestructibleBuildingDataComponent.h"

DestructibleBuildingDataComponent::DestructibleBuildingDataComponent() {
	this->setLoggingName("DESTOBJ");
	intCurrentState = INVULNERABLE;

	currentDnaChain = "";

	activeDefenses = true;
	terminalDamaged = false;
	terminalsSpawned = false;

	uplinkBand = 0;
	inRepair = false;
	defenseAddedThisVuln = false;
}

DestructibleBuildingDataComponent::~DestructibleBuildingDataComponent() {
}

void DestructibleBuildingDataComponent::setState(int state) {
	if (state >= INVULNERABLE && state <= REBOOTSEQUENCE)
		intCurrentState = state;
}

void DestructibleBuildingDataComponent::writeJSON(nlohmann::json& j) const {
	BuildingDataComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(dnaStrand);
	SERIALIZE_JSON_MEMBER(dnaLocks);
	SERIALIZE_JSON_MEMBER(currentDnaChain);
	SERIALIZE_JSON_MEMBER(powerSwitchRules);
	SERIALIZE_JSON_MEMBER(powerSwitchStates);
	SERIALIZE_JSON_MEMBER(intCurrentState);
	SERIALIZE_JSON_MEMBER(terminalDamaged);
	SERIALIZE_JSON_MEMBER(inRepair);
	SERIALIZE_JSON_MEMBER(turretSlots);
	SERIALIZE_JSON_MEMBER(minefieldSlots);
	SERIALIZE_JSON_MEMBER(scannerSlots);
	SERIALIZE_JSON_MEMBER(lastVulnerableTime);
	SERIALIZE_JSON_MEMBER(nextVulnerableTime);
	SERIALIZE_JSON_MEMBER(vulnerabilityEndTime);
	SERIALIZE_JSON_MEMBER(placementTime);
	SERIALIZE_JSON_MEMBER(lastResetTime);
	SERIALIZE_JSON_MEMBER(uplinkBand);
	SERIALIZE_JSON_MEMBER(activeDefenses);
	SERIALIZE_JSON_MEMBER(defenseAddedThisVuln);
	SERIALIZE_JSON_MEMBER(terminalsSpawned);
	SERIALIZE_JSON_MEMBER(baseTerminals);
	SERIALIZE_JSON_MEMBER(hackBaseAlarms);
	SERIALIZE_JSON_MEMBER(destructBaseAlarms);
}


void DestructibleBuildingDataComponent::initializeTransientMembers() {
	uplinkBand = System::random(0x9);
}

bool DestructibleBuildingDataComponent::parseFromBinaryStream(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();

	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);
		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if (readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	return true;
}

bool DestructibleBuildingDataComponent::toBinaryStream(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);

	return true;
}

int DestructibleBuildingDataComponent::writeObjectMembers(ObjectOutputStream* stream) {

	String _name;
	int _offset;
	uint32 _totalSize;

	_name = "placementTime";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Time >::toBinaryStream(&placementTime, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "nextVulnerableTime";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Time >::toBinaryStream(&nextVulnerableTime, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "lastResetTime";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Time >::toBinaryStream(&lastResetTime, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "lastVulnerableTime";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Time >::toBinaryStream(&lastVulnerableTime, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "vulnerabilityEndTime";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Time >::toBinaryStream(&vulnerabilityEndTime, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "intCurrentState";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&intCurrentState, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "inRepair";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&inRepair, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "terminalDamaged";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&terminalDamaged, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "turretSlots";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Vector<uint64>  >::toBinaryStream(&turretSlots, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "minefieldSlots";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Vector<uint64>  >::toBinaryStream(&minefieldSlots, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "scannerSlots";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Vector<uint64>  >::toBinaryStream(&scannerSlots, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "activeDefenses";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&activeDefenses, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "defenseAddedThisVuln";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&defenseAddedThisVuln, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "hackBaseAlarms";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Vector<uint64>  >::toBinaryStream(&hackBaseAlarms, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "destructBaseAlarms";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Vector<uint64>  >::toBinaryStream(&destructBaseAlarms, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	return 15;
}

bool DestructibleBuildingDataComponent::readObjectMember(ObjectInputStream* stream, const String& name) {
	if (name == "placementTime") {
		TypeInfo<Time >::parseFromBinaryStream(&placementTime, stream);
		return true;

	} else if (name == "nextVulnerableTime") {
		TypeInfo<Time >::parseFromBinaryStream(&nextVulnerableTime, stream);
		return true;

	} else if (name == "lastResetTime") {
		TypeInfo<Time >::parseFromBinaryStream(&lastResetTime, stream);
		return true;

	} else if (name == "lastVulnerableTime") {
		TypeInfo<Time >::parseFromBinaryStream(&lastVulnerableTime, stream);
		return true;

	} else if (name == "vulnerabilityEndTime") {
		TypeInfo<Time >::parseFromBinaryStream(&vulnerabilityEndTime, stream);
		return true;

	} else if (name == "inRepair") {
		TypeInfo<bool >::parseFromBinaryStream(&inRepair, stream);
		return true;

	} else if (name == "terminalDamaged") {
		TypeInfo<bool >::parseFromBinaryStream(&terminalDamaged, stream);
		return true;

	} else if (name == "intCurrentState") {
		TypeInfo<int >::parseFromBinaryStream(&intCurrentState, stream);
		return true;

	} else if (name == "turretSlots") {
		TypeInfo<Vector<uint64> >::parseFromBinaryStream(&turretSlots, stream);
		return true;

	} else if (name == "minefieldSlots") {
		TypeInfo<Vector<uint64> >::parseFromBinaryStream(&minefieldSlots, stream);
		return true;

	} else if (name == "scannerSlots") {
		TypeInfo<Vector<uint64> >::parseFromBinaryStream(&scannerSlots, stream);
		return true;

	} else if (name == "activeDefenses") {
		TypeInfo<bool >::parseFromBinaryStream(&activeDefenses, stream);
		return true;

	} else if (name == "defenseAddedThisVuln") {
		TypeInfo<bool >::parseFromBinaryStream(&defenseAddedThisVuln, stream);
		return true;
	} else if (name == "hackBaseAlarms") {
		TypeInfo<Vector<uint64> >::parseFromBinaryStream(&hackBaseAlarms, stream);
		return true;
	} else if (name == "destructBaseAlarms") {
		TypeInfo<Vector<uint64> >::parseFromBinaryStream(&destructBaseAlarms, stream);
		return true;
	}

	return false;
}

bool DestructibleBuildingDataComponent::isVulnerable() {
	return (intCurrentState >= VULNERABLE);
}

bool DestructibleBuildingDataComponent::isDestructibleBuildingData() {
	return true;
}

int DestructibleBuildingDataComponent::getState() {
	return intCurrentState;
}

Time DestructibleBuildingDataComponent::getLastVulnerableTime() {
	return lastVulnerableTime;
}

Time DestructibleBuildingDataComponent::getNextVulnerableTime() {
	return nextVulnerableTime;
}

Time DestructibleBuildingDataComponent::getVulnerabilityEndTime() {
	return vulnerabilityEndTime;
}

Time DestructibleBuildingDataComponent::getPlacementTime() {
	return placementTime;
}

Time DestructibleBuildingDataComponent::getLastResetTime() {
	return lastResetTime;
}

int DestructibleBuildingDataComponent::getUplinkBand() {
	return uplinkBand;
}

int DestructibleBuildingDataComponent::isTerminalBeingRepaired() {
	return inRepair;
}

bool DestructibleBuildingDataComponent::isTerminalDamaged() {
	return terminalDamaged;
}

void DestructibleBuildingDataComponent::setLastVulnerableTime(const Time& time) {
	lastVulnerableTime = time;
}

void DestructibleBuildingDataComponent::setNextVulnerableTime(const Time& time) {
	nextVulnerableTime = time;
}

void DestructibleBuildingDataComponent::setVulnerabilityEndTime(const Time& time) {
	vulnerabilityEndTime = time;
}

void DestructibleBuildingDataComponent::setPlacementTime(Time time) {
	placementTime = time;
}

void DestructibleBuildingDataComponent::setLastResetTime(Time time) {
	lastResetTime = time;
}

void DestructibleBuildingDataComponent::setUplinkBand(int band) {
	uplinkBand = band;
}

void DestructibleBuildingDataComponent::setTerminalBeingRepaired(bool val) {
	inRepair = val;
}

void DestructibleBuildingDataComponent::setTerminalDamaged(bool val) {
	terminalDamaged = val;
}

void DestructibleBuildingDataComponent::setActiveTurret(int indx, uint64 turretOID) {
	turretSlots.get(indx) = turretOID;
}

void DestructibleBuildingDataComponent::setActiveMinefield(int indx, uint64 minefieldOID) {
	minefieldSlots.get(indx) = minefieldOID;
}

int DestructibleBuildingDataComponent::getTotalTurretCount() {
	return turretSlots.size();
}

int DestructibleBuildingDataComponent::getTotalMinefieldCount() {
	return minefieldSlots.size();
}

int DestructibleBuildingDataComponent::getTotalScannerCount() {
	return scannerSlots.size();
}

bool DestructibleBuildingDataComponent::isTurretSlotOccupied(int indx) {
	return (turretSlots.get(indx) > 0);
}

bool DestructibleBuildingDataComponent::isMinefieldSlotOccupied(int indx) {
	return (minefieldSlots.get(indx) > 0);
}

bool DestructibleBuildingDataComponent::isScannerSlotOccupied(int idx) {
	return (scannerSlots.get(idx) > 0);
}

uint64 DestructibleBuildingDataComponent::getTurretID(int indx) {
	return turretSlots.elementAt(indx);
}

uint64 DestructibleBuildingDataComponent::getMinefieldID(int indx) {
	return minefieldSlots.elementAt(indx);
}

uint64 DestructibleBuildingDataComponent::getScannerID(int indx) {
	return scannerSlots.elementAt(indx);
}

bool DestructibleBuildingDataComponent::hasTurret(uint64 turretID) {
	return turretSlots.contains(turretID);
}

bool DestructibleBuildingDataComponent::hasMinefield(uint64 minefieldOID) {
	return minefieldSlots.contains(minefieldOID);
}

bool DestructibleBuildingDataComponent::hasScanner(uint64 minefieldOID) {
	return scannerSlots.contains(minefieldOID);
}

bool DestructibleBuildingDataComponent::hasDefense(uint64 defenseOID) {
	return hasTurret(defenseOID) || hasMinefield(defenseOID) || hasScanner(defenseOID);
}

int DestructibleBuildingDataComponent::getIndexOfTurret(uint64 turretID) {
	for (int i = 0; i < turretSlots.size(); i++) {
		if (turretSlots.elementAt(i) == turretID)
			return i;
	}

	return -1;
}

int DestructibleBuildingDataComponent::getIndexOfMinefield(uint64 minefieldOID) {
	for (int i = 0; i < minefieldSlots.size(); i++) {
		if (minefieldSlots.elementAt(i) == minefieldOID)
			return i;
	}

	return -1;
}

int DestructibleBuildingDataComponent::getIndexOfScanner(uint64 scannerOID) {
	for (int i = 0; i < scannerSlots.size(); i++) {
		if (scannerSlots.elementAt(i) == scannerOID)
			return i;
	}

	return -1;
}

void DestructibleBuildingDataComponent::setTurretID(int indx, uint64 turretOID) {
	turretSlots.elementAt(indx) = turretOID;
}

void DestructibleBuildingDataComponent::setScannerID(int indx, uint64 scannerOID) {
	scannerSlots.elementAt(indx) = scannerOID;
}

void DestructibleBuildingDataComponent::setMinefieldID(int indx, uint64 minefieldOID) {
	minefieldSlots.elementAt(indx) = minefieldOID;
}

void DestructibleBuildingDataComponent::addScanner(int indx, uint64 scannerOID) {
	scannerSlots.add(indx, scannerOID);
}

void DestructibleBuildingDataComponent::addTurret(int indx, uint64 turretOID) {
	turretSlots.add(indx, turretOID);
}

void DestructibleBuildingDataComponent::addMinefield(int indx, uint64 minefieldOID) {
	minefieldSlots.add(indx, minefieldOID);
}

bool DestructibleBuildingDataComponent::isGCWBaseData() {
	return true;
}

bool DestructibleBuildingDataComponent::hasDefense() {
	return activeDefenses;
}

void DestructibleBuildingDataComponent::setDefense(bool value) {
	activeDefenses = value;
}

bool DestructibleBuildingDataComponent::wasDefenseAddedThisVuln() {
	return defenseAddedThisVuln;
}

void DestructibleBuildingDataComponent::setDefenseAddedThisVuln(bool added) {
	defenseAddedThisVuln = added;
}

void DestructibleBuildingDataComponent::clearDnaStrand() {
	dnaStrand.removeAll();
}

void DestructibleBuildingDataComponent::setDnaStrand(const Vector<String>& strand) {
	dnaStrand = strand;
}

const Vector<String>& DestructibleBuildingDataComponent::getDnaStrand() {
	return dnaStrand;
}

void DestructibleBuildingDataComponent::clearDnaLocks() {
	dnaLocks.removeAll();
}

void DestructibleBuildingDataComponent::setDnaLocks(const Vector<int>& locks) {
	dnaLocks = locks;
}

const Vector<int>& DestructibleBuildingDataComponent::getDnaLocks() const {
	return dnaLocks;
}

Vector<int>& DestructibleBuildingDataComponent::getDnaLocks() {
	return dnaLocks;
}

const String& DestructibleBuildingDataComponent::getCurrentDnaChain() {
	return currentDnaChain;
}

void DestructibleBuildingDataComponent::setCurrentDnaChain(const String& chain) {
	currentDnaChain = chain;
}

const Vector<int>& DestructibleBuildingDataComponent::getPowerSwitchRules() {
	return powerSwitchRules;
}

void DestructibleBuildingDataComponent::setPowerSwitchRules(const Vector<int>& rules) {
	powerSwitchRules = rules;
}

const Vector<bool>& DestructibleBuildingDataComponent::getPowerSwitchStates() {
	return powerSwitchStates;
}

void DestructibleBuildingDataComponent::setPowerSwitchStates(const Vector<bool>& states) {
	powerSwitchStates = states;
}

bool DestructibleBuildingDataComponent::getPowerPosition(int indx) {
	return powerSwitchStates.get(indx);
}

int DestructibleBuildingDataComponent::getBaseTerminalCount() {
	return baseTerminals.size();
}

SceneObject* DestructibleBuildingDataComponent::getBaseTerminal(int idx) {
	return baseTerminals.get(idx);
}

void DestructibleBuildingDataComponent::addBaseTerminal(SceneObject* term) {
	baseTerminals.add(term);
}

void DestructibleBuildingDataComponent::clearBaseTerminals() {
	baseTerminals.removeAll();
}

bool DestructibleBuildingDataComponent::areTerminalsSpawned() {
	return terminalsSpawned;
}

void DestructibleBuildingDataComponent::setTerminalsSpawned(bool val) {
	terminalsSpawned = val;
}

Vector<uint64> DestructibleBuildingDataComponent::getHackAlarms() {
	return hackBaseAlarms;
}

Vector<uint64> DestructibleBuildingDataComponent::getDestructAlarms() {
	return destructBaseAlarms;
}

void DestructibleBuildingDataComponent::addHackBaseAlarm(uint64 alarmID) {
	hackBaseAlarms.add(alarmID);
}

void DestructibleBuildingDataComponent::addDestructBaseAlarm(uint64 alarmID) {
	destructBaseAlarms.add(alarmID);
}