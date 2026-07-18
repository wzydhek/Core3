/*
 * CreatureAttackMap.h
 *
 *  Created on: Sep 28, 2010
 *      Author: dannuic
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace variables {

class CreatureAttack {
protected:
	String command;
	String arguments;

public:
	CreatureAttack();

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	friend void to_json(nlohmann::json& j, const CreatureAttack& a);

	const String& getCommand() const;

	const String& getArguments() const;

	void setCommand(const String& c);

	void setArguments(const String& a);
};

class CreatureAttackMap : public Vector<CreatureAttack> {
public:
	CreatureAttackMap();

	virtual ~CreatureAttackMap();

	void addAttack(String c, String a);

	const String& getCommand(int i) const;

	const String& getArguments(int i) const;

	int getRandomAttackNumber() const;
};

void to_json(nlohmann::json& j, const CreatureAttack& a);

} // namespace variables
} // namespace ai
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::ai::variables;
