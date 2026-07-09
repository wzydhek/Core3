/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "StringId.h"

StringId::StringId() : Object() {
	file = "";
	filler = 0;
	stringID = "";
}

StringId::StringId(const StringId& id) : Object() {
	file = id.file;
	filler = 0;
	stringID = id.stringID;
}

StringId::StringId(const String& fullPath) : Object() {
	setStringId(fullPath);
	filler = 0;
}

StringId::StringId(const char * fullPath) : Object() {
	setStringId(String(fullPath));
	filler = 0;
}

StringId::StringId(const String& fil, const String& stringId) : Object() {
	file = fil;
	stringID = stringId;
	filler = 0;
}

StringId::StringId(StringId&& id) : Object(), file(std::move(id.file)), filler(id.filler),
		stringID(std::move(id.stringID)) {

}

void StringId::clear() {
	file = "";
	stringID = "";
	filler = 0;
}

void StringId::setStringId(const String& fullPath) {
	if (fullPath.isEmpty())
		return;

	if (fullPath.charAt(0) == '@') {
		StringTokenizer tokenizer(fullPath.subString(1));
		tokenizer.setDelimeter(":");

		file = tokenizer.hasMoreTokens() ? tokenizer.getStringToken() : "";
		stringID = tokenizer.hasMoreTokens() ? tokenizer.getStringToken() : "";
	}
}

void server::zone::objects::scene::variables::to_json(nlohmann::json& j, const server::zone::objects::scene::variables::StringId& str) {
	j["file"] = str.getFile();
	j["filler"] = str.getFiller();
	j["stringID"] = str.getStringID();
}

StringId& StringId::operator=(const StringId& id) {
	if (&id == this)
		return *this;

	file = id.file;
	stringID = id.stringID;
	filler = id.filler;

	return *this;
}

StringId& StringId::operator=(StringId&& id) {
	if (&id == this)
		return *this;

	file = std::move(id.file);
	stringID = std::move(id.stringID);
	filler = id.filler;

	return *this;
}

bool StringId::operator==(const StringId& id) const {
	if (&id == this)
		return true;

	if (file == id.file && stringID == id.stringID)
		return true;

	return false;
}

int StringId::compareTo(const StringId& id) const {
	return getFullPath().compareTo(id.getFullPath());
}

void StringId::getFullPath(String& str) const {
	str = "@" + file + ":" + stringID;
}

String StringId::getFullPath() const {
	return "@" + file + ":" + stringID;
}

const String& StringId::getFile() const {
	return file;
}

const String& StringId::getStringID() const {
	return stringID;
}

uint32 StringId::size() const {
	return file.length() + stringID.length();
}

bool StringId::isEmpty() const {
	if (file.isEmpty())
		return true;

	return false;
}

int StringId::getFiller() const {
	return filler;
}

void StringId::setStringId(const String& file, const String& id) {
	StringId::file = file;
	StringId::stringID = id;
}

bool StringId::toBinaryStream(ObjectOutputStream* stream) {
	return file.toBinaryStream(stream) && TypeInfo<int>::toBinaryStream(&filler, stream) && stringID.toBinaryStream(stream);
}

bool StringId::parseFromBinaryStream(ObjectInputStream* stream) {
	file.parseFromBinaryStream(stream);
	TypeInfo<int>::parseFromBinaryStream(&filler, stream);
	stringID.parseFromBinaryStream(stream);

	return true;
}

String StringId::toString() const {
	StringBuffer asStr;
	asStr << file << ":" << stringID;
	return asStr.toString();
}