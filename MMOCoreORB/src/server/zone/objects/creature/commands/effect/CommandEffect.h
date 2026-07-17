/*
 * CommandEffect.h
 *
 *  Created on: Jan 18, 2012
 *      Author: da
 */

#pragma once

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {
namespace effect {

class CommandEffect {
public:
	enum { INVALID, BLIND, DIZZY, INTIMIDATE, STUN, KNOCKDOWN, POSTUREUP, POSTUREDOWN, NEXTATTACKDELAY, HEALTHDEGRADE, ACTIONDEGRADE, MINDDEGRADE, REMOVECOVER, FORCECHOKE, ATTACKER_FORCE_STAND, ATTACKER_FORCE_CROUCH, ATTACKER_FORCE_PRONE };
};

} // namespace effect
} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands::effect;
