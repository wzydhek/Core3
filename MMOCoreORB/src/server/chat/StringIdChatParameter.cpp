/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#include "StringIdChatParameter.h"

StringIdChatParameter::StringIdChatParameter() : StringId() {
	unknownByte = 0;
	DI = 0;
	DF = 0;
}

StringIdChatParameter::StringIdChatParameter(const StringId& id) : StringId(id) {
	unknownByte = 0;
	DI = 0;
	DF = 0;
}

StringIdChatParameter::StringIdChatParameter(const char * cstr) : StringId (cstr) {
	unknownByte = 0;
	DI = 0;
	DF = 0;
}

StringIdChatParameter::StringIdChatParameter(const String& fullPath) : StringId (fullPath) {
	unknownByte = 0;
	DI = 0;
	DF = 0;
}

StringIdChatParameter::StringIdChatParameter(const String& fil, const String& stringId) : StringId(fil, stringId) {
	unknownByte = 0;
	DI = 0;
	DF = 0;
}

StringIdChatParameter::StringIdChatParameter(const StringIdChatParameter& custom) : Object(), ChatParameter(), StringId(custom) {
	TT = custom.TT;
	TU = custom.TU;
	TO = custom.TO;

	DI = custom.DI;
	DF = custom.DF;

	unknownByte = custom.unknownByte;
}

void StringIdChatParameter::addToPacketStream(Message* packet) const {
	packet->insertAscii(file);
	packet->insertInt(0);
	packet->insertAscii(stringID);

	packet->insertLong(TU.getPointerParameter());
	packet->insertAscii(TU.getFileParameter());
	packet->insertInt(0);
	packet->insertAscii(TU.getStringIDParameter());
	packet->insertUnicode(TU.getUnicodeParameter());

	packet->insertLong(TT.getPointerParameter());
	packet->insertAscii(TT.getFileParameter());
	packet->insertInt(0);
	packet->insertAscii(TT.getStringIDParameter());
	packet->insertUnicode(TT.getUnicodeParameter());

	packet->insertLong(TO.getPointerParameter());
	packet->insertAscii(TO.getFileParameter());
	packet->insertInt(0);
	packet->insertAscii(TO.getStringIDParameter());
	packet->insertUnicode(TO.getUnicodeParameter());

	packet->insertInt(DI);
	packet->insertFloat(DF);
	packet->insertByte(unknownByte);
}

void StringIdChatParameter::parse(Message* message) {

}

bool StringIdChatParameter::toBinaryStream(ObjectOutputStream* stream) {
	StringId::toBinaryStream(stream);

	return TT.toBinaryStream(stream) &&
			TU.toBinaryStream(stream) &&
			TO.toBinaryStream(stream) &&
			TypeInfo<uint32 >::toBinaryStream(&DI, stream) &&
			TypeInfo<float >::toBinaryStream(&DF, stream);
}

bool StringIdChatParameter::parseFromBinaryStream(ObjectInputStream* stream) {

	StringId::parseFromBinaryStream(stream);

	TT.parseFromBinaryStream(stream);
	TU.parseFromBinaryStream(stream);
	TO.parseFromBinaryStream(stream);
	TypeInfo<uint32 >::parseFromBinaryStream(&DI, stream);
	TypeInfo<float >::parseFromBinaryStream(&DF, stream);

	return true;
}

String StringIdChatParameter::toString() const {
	return StringId::getFullPath();
}

StringIdChatParameter& StringIdChatParameter::operator=(const StringIdChatParameter& id) {
	if (this == &id)
		return *this;

	TT = id.TT;
	TU = id.TU;
	TO = id.TO;
	NU = id.NU;

	DI = id.DI;
	DF = id.DF;

	unknownByte = id.unknownByte;

	ChatParameter::operator=(id);
	StringId::operator=(id);

	return *this;
}

/**
 * Sets the TT variable of this stf string to another stf string
 * @pre { }
 * @post { TT variable is set }
 * @param file stf file name that contains the stf string
 * @param stringid stringid of stf string
 */
void StringIdChatParameter::setTT(const String& file, const String& stringid) {
	TT.set(file, stringid);
}

/**
 * Sets the TU variable of this stf string to another stf string
 * @pre { }
 * @post { TU variable is set }
 * @param file stf file name that contains the stf string
 * @param stringid stringid of stf string
 */
void StringIdChatParameter::setTU(const String& file, const String& stringid) {
	TU.set(file, stringid);
}

/**
 * Sets the TO variable of this stf string to another stf string
 * @pre { }
 * @post { TO variable is set }
 * @param file stf file name that contains the stf string
 * @param stringid stringid of stf string
 */
void StringIdChatParameter::setTO(const String& file, const String& stringid) {
	TO.set(file, stringid);
}

/**
 * Sets the DI variable
 * @pre { }
 * @post { DI variable is set }
 * @param i value for DI
 */
void StringIdChatParameter::setDI(uint32 i) {
	DI = i;
}

/**
 * Sets the DF variable
 * @pre { }
 * @post { DF variable is set }
 * @param f value for DF
 */
void StringIdChatParameter::setDF(float f) {
	DF = f;
}

void StringIdChatParameter::setUnknownByte(uint16 val) {
	unknownByte = val;
}

StringIdParameter* StringIdChatParameter::getTT() {
	return &TT;
}

StringIdParameter* StringIdChatParameter::getTU() {
	return &TU;
}

StringIdParameter* StringIdChatParameter::getTO() {
	return &TO;
}

const StringIdParameter* StringIdChatParameter::getTT() const {
	return &TT;
}

const StringIdParameter* StringIdChatParameter::getTU() const {
	return &TU;
}

const StringIdParameter* StringIdChatParameter::getTO() const {
	return &TO;
}

const StringIdParameter* StringIdChatParameter::getNU() const {
	return &NU;
}

namespace server {
	namespace chat {
		void to_json(nlohmann::json& j, const StringIdChatParameter& p) {
			j["file"] = p.getFile();
			j["filler"] = p.getFiller();
			j["stringID"] = p.getStringID();
			j["TT"] = p.TT;
			j["TU"] = p.TU;
			j["TO"] = p.TO;
			j["DI"] = p.DI;
			j["DF"] = p.DF;
		}
	}
}
