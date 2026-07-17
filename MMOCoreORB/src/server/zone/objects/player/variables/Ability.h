/*
 * Ability.h
 *
 *  Created on: Aug 23, 2011
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace variables {

class Ability : public Object {
	String abilityName;

public:
	Ability();

	Ability(const String& name);

	Ability(const Ability& a);

	Ability& operator=(const Ability& a);

	int compareTo(const Ability& a);

	const String& getAbilityName() const;

	void setAbilityName(const String& name);

	bool toBinaryStream(ObjectOutputStream* stream);
};

} // namespace variables
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::variables;
