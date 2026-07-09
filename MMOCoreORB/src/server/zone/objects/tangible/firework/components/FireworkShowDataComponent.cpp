#include "FireworkShowDataComponent.h"

FireworkShowDataComponent::FireworkShowDataComponent() {
}

FireworkShowDataComponent::~FireworkShowDataComponent() {
}

void FireworkShowDataComponent::writeJSON(nlohmann::json& j) const {
	SERIALIZE_JSON_MEMBER(fireworkList);
}

bool FireworkShowDataComponent::toBinaryStream(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);

	return true;
}

int FireworkShowDataComponent::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint32 _totalSize;

	_name = "fireworkList";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<VectorMap<ManagedReference<FireworkObject*>, int>>::toBinaryStream(&fireworkList, stream);
	_totalSize = (uint32)(stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	return 1;
}

bool FireworkShowDataComponent::readObjectMember(ObjectInputStream* stream, const String& name) {
	if (name == "fireworkList") {
		TypeInfo<VectorMap<ManagedReference<FireworkObject*>, int>>::parseFromBinaryStream(&fireworkList, stream);

		return true;
	}
	return false;
}

bool FireworkShowDataComponent::parseFromBinaryStream(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();

	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);
		uint32 _varSize = stream->readInt();
		int _currentOffset = stream->getOffset();
		if (readObjectMember(stream, _name)) {
		}
		stream->setOffset(_currentOffset + _varSize);
	}
	return true;
}

bool FireworkShowDataComponent::isFireworkShowData() {
	return true;
}

int FireworkShowDataComponent::getTotalFireworkCount() {
	return fireworkList.size();
}

int FireworkShowDataComponent::getIndexOfFirework(FireworkObject* firework) {
	for (int i = 0; i < fireworkList.size(); i++) {
		if (fireworkList.elementAt(i).getKey() == firework)
			return i;
	}
	return -1;
}

FireworkObject* FireworkShowDataComponent::getFirework(int index) {
	return fireworkList.elementAt(index).getKey();
}

int FireworkShowDataComponent::getFireworkDelay(int index) {
	return fireworkList.elementAt(index).getValue();
}

void FireworkShowDataComponent::setFireworkDelay(int index, int delay) {
	VectorMapEntry<ManagedReference<FireworkObject*>, int> entry(fireworkList.elementAt(index).getKey(), delay);
	fireworkList.remove(index);
	fireworkList.add(index, entry);
}

void FireworkShowDataComponent::addFirework(int index, FireworkObject* firework, int delay) {
	VectorMapEntry<ManagedReference<FireworkObject*>, int> entry(firework, delay);
	fireworkList.add(index, entry);
}
void FireworkShowDataComponent::removeFirework(int index) {
	if (index < fireworkList.size()) {
		fireworkList.remove(index);
	}
}

void FireworkShowDataComponent::swapFireworkPositions(int index, int index2) {
	VectorMapEntry<ManagedReference<FireworkObject*>, int> temp(fireworkList.elementAt(index).getKey(), fireworkList.elementAt(index).getValue());
	VectorMapEntry<ManagedReference<FireworkObject*>, int> temp2(fireworkList.elementAt(index2).getKey(), fireworkList.elementAt(index2).getValue());
	fireworkList.remove(index);
	fireworkList.add(index, temp2);
	fireworkList.remove(index2);
	fireworkList.add(index2, temp);
}