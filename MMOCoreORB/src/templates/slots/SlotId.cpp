#include "SlotId.h"

SlotId::SlotId() : isAnythingSlot(0), isModifiableByPlayer(0), isVisibleSlot(0), combatBoneId(0), observeWithParent(0), exposeToWorld(0) {
}

SlotId::SlotId(const SlotId& sid) : Object() {
	slotName = sid.slotName;
	isAnythingSlot = sid.isAnythingSlot;
	isModifiableByPlayer = sid.isModifiableByPlayer;
	isVisibleSlot = sid.isVisibleSlot;
	hardpointName = sid.hardpointName;
	combatBoneId = sid.combatBoneId;
	observeWithParent = sid.observeWithParent;
	exposeToWorld = sid.exposeToWorld;
}

SlotId& SlotId::operator=(const SlotId& sid) {
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

int SlotId::compareTo(const SlotId& sid) const {
	return slotName.compareTo(sid.slotName);
}

void SlotId::readObject(Chunk* chunk) {
	chunk->readString(slotName);
	isAnythingSlot = chunk->readByte() != 0;
	isModifiableByPlayer = chunk->readByte() != 0;
	isVisibleSlot = chunk->readByte() != 0;
	chunk->readString(hardpointName);
	combatBoneId = chunk->readShort();
	observeWithParent = chunk->readByte() != 0;
	exposeToWorld = chunk->readByte() != 0;
}

void SlotId::writeHtmlTableRow(StringBuffer& str) const {
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

const String& SlotId::getSlotName() const {
	return slotName;
}