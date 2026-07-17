/*
 * SlotId.h
 *
 *  Created on: May 25, 2011
 *      Author: crush
 */

#pragma once

#include "system/lang/Object.h"
#include "engine/util/iffstream/IffStream.h"

namespace templates {
namespace slots {

class SlotId : public Object {
	String slotName;
	bool isAnythingSlot;
	bool isModifiableByPlayer;
	bool isVisibleSlot;
	String hardpointName;
	uint16 combatBoneId;
	bool observeWithParent;
	bool exposeToWorld;

public:
	SlotId();

	SlotId(const SlotId& sid);

	SlotId& operator=(const SlotId& sid);

	int compareTo(const SlotId& sid) const;

	void readObject(Chunk* chunk);

	void writeHtmlTableRow(StringBuffer& str) const;

	const String& getSlotName() const;
};

} // namespace slots
} // namespace templates

using namespace templates::slots;
