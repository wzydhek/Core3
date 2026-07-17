/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace packets {
namespace tangible {

class TangibleObjectDeltaMessage3 : public DeltaMessage {
	ManagedReference<TangibleObject*> tano;

public:
	TangibleObjectDeltaMessage3(TangibleObject* ta, uint32 objType = 0x54414E4F);

	void updateCustomizationString();

	void updateComplexity();

	void updateObjectName(const StringId& name);

	void updateCustomName(const UnicodeString& name, const UnicodeString& tag = "");

	void updateCountdownTimer();

	void updateConditionDamage();

	void updateMaxCondition();

	void updateOptionsBitmask();
};

} // namespace tangible
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::tangible;
