/*
 * SlotId.h
 *
 *  Created on: May 25, 2011
 *      Author: crush
 */

#pragma once

#include "system/lang/Object.h"

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
	SlotId() : isAnythingSlot(0), isModifiableByPlayer(0), isVisibleSlot(0), combatBoneId(0), observeWithParent(0), exposeToWorld(0) {
	}

	SlotId(const SlotId& sid) : Object() {
		slotName = sid.slotName;
		isAnythingSlot = sid.isAnythingSlot;
		isModifiableByPlayer = sid.isModifiableByPlayer;
		isVisibleSlot = sid.isVisibleSlot;
		hardpointName = sid.hardpointName;
		combatBoneId = sid.combatBoneId;
		observeWithParent = sid.observeWithParent;
		exposeToWorld = sid.exposeToWorld;
	}

	SlotId& operator= (const SlotId& sid) {
		if (this == &sid)
			return *this;

		slotName = sid.slotName;
		isAnythingSlot = sid.isAnythingSlot;
		isModifiableByPlayer = sid.isModifiableByPlayer;
		isVisibleSlot = sid.isVisibleSlot;
		hardpointName = sid.hardpointName;
		combatBoneId = sid.combatBoneId;
		observeWithParent = sid.observeWithParent;
		exposeToWorld = sid.exposeToWorld;

		return *this;
	}

	int compareTo(const SlotId& sid) const {
		return slotName.compareTo(sid.slotName);
	}

	void readObject(Chunk* chunk) {
		chunk->readString(slotName);
		isAnythingSlot = chunk->readByte() != 0;
		isModifiableByPlayer = chunk->readByte() != 0;
		isVisibleSlot = chunk->readByte() !=0;
		chunk->readString(hardpointName);
		combatBoneId = chunk->readShort();
		observeWithParent = chunk->readByte() != 0;
		exposeToWorld = chunk->readByte() != 0;
	}

	void writeHtmlTableRow(StringBuffer& str) const {
		str << "<tr>";
		str << "<td>" << slotName << "</td>";
		str << "<td>" << isAnythingSlot << "</td>";
		str << "<td>" << isModifiableByPlayer << "</td>";
		str << "<td>" << isVisibleSlot << "</td>";
		str << "<td>" << hardpointName << "</td>";
		str << "<td>" << combatBoneId << "</td>";
		str << "<td>" << observeWithParent << "</td>";
		str << "<td>" << exposeToWorld << "</td>";
		str << "</tr>";
	}

	inline const String& getSlotName() const {
		return slotName;
	}
};
