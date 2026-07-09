#include "BoolParam.h"

BoolParam::BoolParam() : TemplateBase<bool>(false) {
	setType(BOOL);
}

BoolParam::BoolParam(bool b) : TemplateBase<bool>(b) {
	setType(BOOL);
}

BoolParam& BoolParam::operator=(bool val) {
	create(val);

	return *this;
}

String BoolParam::toString() const {
	return String::valueOf((int)get());
}

bool BoolParam::toBinaryStream(ObjectOutputStream* stream) {
	return false;
}

/*static bool parseFromString(T* address, const sys::lang::String& value, int version = 0) {
	return address->parseFromString(value, version);
}*/

bool BoolParam::parseFromBinaryStream(ObjectInputStream* stream) {
	return false;
}

bool BoolParam::parse(engine::util::Chunk* source) {
	uint8 readCase = source->readByte();

	if (readCase == 1) {
		create(source->readByte());

		return true;
	}

	return false;
	/*else {
		create(false);
	}*/
}