#include "CooldownTimerMap.h"

CooldownTimer::CooldownTimer() : Variable() {
	// timeStamp = nullptr;
}

CooldownTimer::CooldownTimer(const Time& timestamp) : Variable() {
	timeStamp = timestamp;
}

CooldownTimer::CooldownTimer(const CooldownTimer& obj) : Variable() {
	timeStamp = obj.timeStamp;
}

CooldownTimer& CooldownTimer::operator=(const CooldownTimer& tim) {
	timeStamp = tim.timeStamp;

	return *this;
}

void CooldownTimer::operator=(Time obj) {
	timeStamp = obj;
}

bool CooldownTimer::toString(String& str) {
	timeStamp.toString(str);

	return true;
}

bool CooldownTimer::parseFromString(const String& str, int version) {
	Time parsed;

	parsed.parseFromString(str);

	if (parsed.isPast())
		return false;

	timeStamp = parsed;

	return true;
}

bool CooldownTimer::toBinaryStream(ObjectOutputStream* stream) {
	timeStamp.toBinaryStream(stream);

	return true;
}

void to_json(nlohmann::json& j, const CooldownTimer& t) {
	j["timeStamp"] = t.timeStamp;
}

bool CooldownTimer::parseFromBinaryStream(ObjectInputStream* stream) {
	Time parsed;

	parsed.parseFromBinaryStream(stream);

	if (parsed.isPast())
		return false;

	timeStamp = parsed;

	return true;
}

bool CooldownTimer::isPast() const {
	return timeStamp.isPast();
}

void CooldownTimer::addMiliTime(uint64 mtime) {
	timeStamp.addMiliTime(mtime);
}

Time* CooldownTimer::getTime() {
	return &timeStamp;
}

const Time* CooldownTimer::getTime() const {
	return &timeStamp;
}

CooldownTimerMap::CooldownTimerMap() : timers(1, 1) {
}

CooldownTimerMap::CooldownTimerMap(const CooldownTimerMap& map) : Object(), cooldownMutex() {
	timers = map.timers;
}

CooldownTimerMap::~CooldownTimerMap() {
}

CooldownTimerMap& CooldownTimerMap::operator=(const CooldownTimerMap& map) {
	if (this == &map)
		return *this;

	timers = map.timers;
	cooldownMutex = map.cooldownMutex;

	return *this;
}

bool CooldownTimerMap::isPast(const String& cooldownName) const {
	Locker locker(&cooldownMutex);

	auto entry = timers.getEntry(cooldownName);

	if (entry == nullptr)
		return true;

	return entry->getValue().isPast();
}

void CooldownTimerMap::updateToCurrentAndAddMili(const String& cooldownName, uint64 mili) {
	Locker locker(&cooldownMutex);

	Time* cooldown = updateToCurrentTime(cooldownName);

	cooldown->addMiliTime(mili);
}

Time* CooldownTimerMap::updateToCurrentTime(const String& cooldownName) {
	Locker locker(&cooldownMutex);

	if (!timers.containsKey(cooldownName)) {
		timers.put(cooldownName, Time());
	}

	Time* cooldown = timers.get(cooldownName).getTime();
	cooldown->updateToCurrentTime();

	return cooldown;
}

void CooldownTimerMap::addMiliTime(const String& cooldownName, uint64 mili) {
	Locker locker(&cooldownMutex);

	if (!timers.containsKey(cooldownName)) {
		timers.put(cooldownName, Time());
	}

	Time* cooldown = timers.get(cooldownName).getTime();
	cooldown->addMiliTime(mili);
}

const Time* CooldownTimerMap::getTime(const String& cooldownName) const {
	Locker locker(&cooldownMutex);

	auto entry = timers.getEntry(cooldownName);

	if (entry == nullptr)
		return nullptr;

	const Time* cooldown = entry->getValue().getTime();

	return cooldown;
}

Object* CooldownTimerMap::clone() {
	return ObjectCloner<CooldownTimerMap>::clone(this);
}

Object* CooldownTimerMap::clone(void* object) {
	return TransactionalObjectCloner<CooldownTimerMap>::clone(this);
}