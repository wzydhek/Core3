#include "DeltaMessage.h"

DeltaMessage::DeltaMessage(uint64 oid, uint32 name, uint8 type) {
	insertShort(0x05);
	insertInt(0x12862153);
	insertLong(oid);
	insertInt(name);
	insertByte(type);
	insertInt(0);

	setCompression(true);

	updateCount = 0;
	insertShort(updateCount);
}

void DeltaMessage::startUpdate(uint16 type) {
	++updateCount;
	insertShort(type);
}

void DeltaMessage::addByteUpdate(uint16 type, uint8 value) {
	startUpdate(type);
	insertByte(value);
}

void DeltaMessage::addShortUpdate(uint16 type, uint16 value) {
	startUpdate(type);
	insertShort(value);
}

void DeltaMessage::addIntUpdate(uint16 type, uint32 value) {
	startUpdate(type);
	insertInt(value);
}

void DeltaMessage::addLongUpdate(uint16 type, uint64 value) {
	startUpdate(type);
	insertLong(value);
}

void DeltaMessage::addFloatUpdate(uint16 type, float value) {
	startUpdate(type);
	insertFloat(value);
}

void DeltaMessage::addAsciiUpdate(uint16 type, const String& val) {
	startUpdate(type);
	insertAscii(val.toCharArray());
}

void DeltaMessage::addStringIdUpdate(uint16 type, const StringId& val) {
	startUpdate(type);
	insertAscii(val.getFile());
	insertInt(0);
	insertAscii(val.getStringID());
}

void DeltaMessage::addUnicodeUpdate(uint16 type, const String& val) {
	startUpdate(type);
	UnicodeString v = UnicodeString(val);
	insertUnicode(v);
}

void DeltaMessage::addUnicodeUpdate(uint16 type, const UnicodeString& val) {
	startUpdate(type);
	insertUnicode(val);
}

void DeltaMessage::startList(uint32 cnt, uint32 updcnt) {
	insertInt(cnt);
	insertInt(updcnt);
}

void DeltaMessage::addListIntElement(uint16 index, uint32 value) {
	insertByte(0x01);
	insertShort(index);
	insertInt(value);
}

void DeltaMessage::addListFloatElement(uint16 index, float value) {
	insertByte(0x01);
	insertShort(index);
	insertFloat(value);
}

void DeltaMessage::addListLongElement(uint16 index, uint64 value) {
	insertByte(0x01);
	insertShort(index);
	insertLong(value);
}

void DeltaMessage::addListAsciiElement(const String& value) {
	insertByte(0x00);
	insertAscii(value.toCharArray());
}

void DeltaMessage::removeListIntElement(uint16 index, uint32 value) {
	insertByte(0x02);
	insertShort(index);
	insertInt(value);
}

void DeltaMessage::removeListFloatElement(uint16 index, float value) {
	insertByte(0x02);
	insertShort(index);
	insertFloat(value);
}

void DeltaMessage::removeListLongElement(uint16 index, uint64 value) {
	insertByte(0x02);
	insertShort(index);
	insertLong(value);
}

void DeltaMessage::removeListLongElement(uint16 index) {
	insertByte(0x03);
	insertShort(index);
}

void DeltaMessage::removeListAsciiElement(const String& value) {
	insertByte(0x01);
	insertAscii(value.toCharArray());
}

void DeltaMessage::close() {
	insertInt(23, size() - 27);
	insertShort(27, updateCount);
}