#include "FlagGameDataComponent.h"

FlagGameDataComponent::FlagGameDataComponent() {
}

FlagGameDataComponent::~FlagGameDataComponent() {
}

void FlagGameDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(game);
}

bool FlagGameDataComponent::toBinaryStream(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);

	return true;
}

int FlagGameDataComponent::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint32 _totalSize;

	_name = "game";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedReference<FlagGame*>>::toBinaryStream(&game, stream);
	_totalSize = (uint32)(stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	return 1;
}

bool FlagGameDataComponent::readObjectMember(ObjectInputStream* stream, const String& name) {
	if (name == "game") {
		TypeInfo<ManagedReference<FlagGame*>>::parseFromBinaryStream(&game, stream);

		return true;
	}
	return false;
}

bool FlagGameDataComponent::parseFromBinaryStream(ObjectInputStream* stream) {
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

void FlagGameDataComponent::setFlagGame(FlagGame* ga) {
	game = ga;
}

FlagGame* FlagGameDataComponent::getFlagGame() {
	return game;
}

bool FlagGameDataComponent::isFlagGameData() {
	return true;
}