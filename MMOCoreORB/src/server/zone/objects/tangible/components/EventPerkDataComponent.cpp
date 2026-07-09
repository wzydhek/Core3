#include "EventPerkDataComponent.h"

EventPerkDataComponent::EventPerkDataComponent() {
	deed = nullptr;
	actor = nullptr;
}

EventPerkDataComponent::~EventPerkDataComponent() {
	deed = nullptr;
	actor = nullptr;
}

void EventPerkDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(deed);
	SERIALIZE_JSON_MEMBER(actor);
}

bool EventPerkDataComponent::toBinaryStream(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);

	int _varCount = writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);

	return true;
}

int EventPerkDataComponent::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint32 _totalSize;

	_name = "deed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedReference<EventPerkDeed*>>::toBinaryStream(&deed, stream);
	_totalSize = (uint32)(stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "actor";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedReference<CreatureObject*>>::toBinaryStream(&actor, stream);
	_totalSize = (uint32)(stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	return 1;
}

bool EventPerkDataComponent::readObjectMember(ObjectInputStream* stream, const String& name) {
	if (name == "deed") {
		TypeInfo<ManagedReference<EventPerkDeed*>>::parseFromBinaryStream(&deed, stream);

		return true;
	} else if (name == "actor") {
		TypeInfo<ManagedReference<CreatureObject*>>::parseFromBinaryStream(&actor, stream);

		return true;
	}

	return false;
}

bool EventPerkDataComponent::parseFromBinaryStream(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();

	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();
		int _currentOffset = stream->getOffset();

		readObjectMember(stream, _name);

		stream->setOffset(_currentOffset + _varSize);
	}

	return true;
}

void EventPerkDataComponent::setDeed(EventPerkDeed* de) {
	deed = de;
}

void EventPerkDataComponent::setActor(CreatureObject* npcActor) {
	actor = npcActor;
}

EventPerkDeed* EventPerkDataComponent::getDeed() {
	return deed;
}

CreatureObject* EventPerkDataComponent::getActor() {
	return actor;
}

bool EventPerkDataComponent::isEventPerkData() {
	return true;
}