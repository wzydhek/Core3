#include "CreatureAttackMap.h"

CreatureAttack::CreatureAttack() {
}

bool CreatureAttack::toBinaryStream(ObjectOutputStream* stream) {
	bool val = command.toBinaryStream(stream);
	bool val2 = arguments.toBinaryStream(stream);

	return val && val2;
}

bool CreatureAttack::parseFromBinaryStream(ObjectInputStream* stream) {
	bool val = command.parseFromBinaryStream(stream);
	bool val2 = arguments.parseFromBinaryStream(stream);

	return val && val2;
}

void server::zone::objects::creature::ai::variables::to_json(nlohmann::json& j, const CreatureAttack& a) {
	j["command"] = a.command;
	j["arguments"] = a.arguments;
}

const String& CreatureAttack::getCommand() const {
	return command;
}

const String& CreatureAttack::getArguments() const {
	return arguments;
}

void CreatureAttack::setCommand(const String& c) {
	command = c;
}

void CreatureAttack::setArguments(const String& a) {
	arguments = a;
}

CreatureAttackMap::CreatureAttackMap() {
}

CreatureAttackMap::~CreatureAttackMap() {
}

void CreatureAttackMap::addAttack(String c, String a) {
	CreatureAttack attack;
	attack.setCommand(c);
	attack.setArguments(a);
	add(attack);
}

const String& CreatureAttackMap::getCommand(int i) const {
	return get(i).getCommand();
}

const String& CreatureAttackMap::getArguments(int i) const {
	return get(i).getArguments();
}

int CreatureAttackMap::getRandomAttackNumber() const {
	return System::random(size() - 1);
}