#include "SuiCommand.h"

SuiCommand::SuiCommand() : Object() {
	this->commandType = 0;
}

SuiCommand::SuiCommand(const byte& commandType) : Object() {
	this->commandType = commandType;
}

byte SuiCommand::getCommandType() {
	return commandType;
}

void SuiCommand::addNarrowParameter(const String& param) {
	narrowParameters.add(param);
}

String SuiCommand::getNarrowParameter(int index) {
	return narrowParameters.get(index);
}

void SuiCommand::addWideParameter(const UnicodeString& param) {
	wideParameters.add(param);
}

UnicodeString& SuiCommand::getWideParameter(int index) {
	return wideParameters.get(index);
}

bool SuiCommand::toBinaryStream(ObjectOutputStream* stream) {
	stream->writeByte(commandType);
	stream->writeInt(wideParameters.size());

	for (int i = 0; i < wideParameters.size(); ++i)
		wideParameters.get(i).toBinaryStream(stream);

	stream->writeInt(narrowParameters.size());

	for (int i = 0; i < narrowParameters.size(); ++i)
		narrowParameters.get(i).toBinaryStream(stream);

	return true;
}

bool SuiCommand::parseFromBinaryStream(ObjectInputStream* stream) {
	commandType = stream->readInt();

	int size = stream->readInt();

	for (int i = 0; i < size; ++i) {
		UnicodeString param;
		param.parseFromBinaryStream(stream);
		wideParameters.add(param);
	}

	size = stream->readInt();

	for (int i = 0; i < size; ++i) {
		String param;
		param.parseFromBinaryStream(stream);
		narrowParameters.add(param);
	}

	return true;
}