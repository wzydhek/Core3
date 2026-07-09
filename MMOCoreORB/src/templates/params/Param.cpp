#include "Param.h"

Param::Param() {
	type = (uint32)-1;
}

Param::~Param() {
}

uint32 Param::getType() const {
	return type;
}

void Param::setType(uint32 tp) {
	type = tp;
}

bool Param::isBool() const {
	return type == BOOL;
}

bool Param::isFloat() const {
	return type == FLOAT;
}

bool Param::isInteger() const {
	return type == INTEGER;
}

bool Param::isString() const {
	return type == STRING;
}

bool Param::isStringId() const {
	return type == STRINGID;
}