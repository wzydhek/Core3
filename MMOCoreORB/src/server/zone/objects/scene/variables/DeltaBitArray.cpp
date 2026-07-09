#include "DeltaBitArray.h"

DeltaBitArray::DeltaBitArray() : DeltaVector<byte>(1, 1) {
}

DeltaBitArray::DeltaBitArray(int initsize, int incr) : DeltaVector<byte>(initsize, incr) {
}

DeltaBitArray::DeltaBitArray(const DeltaBitArray& v) : DeltaVector<byte>(v) {
}

DeltaBitArray& DeltaBitArray::operator=(const DeltaBitArray& v) {
	if (this == &v)
		return *this;

	DeltaVector<byte>::operator=(v);

	return *this;
}

void DeltaBitArray::setBit(uint32 bitIndex, byte value) {
	int vectorIndex = bitIndex / 8;
	byte vectorBitIndex = 1 << (bitIndex % 8);

	while (size() <= vectorIndex)
		add(0);

	byte currentVal = get(vectorIndex);

	if (value) {
		if (!(currentVal & vectorBitIndex)) {
			currentVal |= vectorBitIndex;
		}
	} else {
		if (currentVal & vectorBitIndex) {
			currentVal &= ~vectorBitIndex;
		}
	}

	set(vectorIndex, currentVal);
}

bool DeltaBitArray::getBitValue(uint32 bitIndex) const {
	int vectorIndex = bitIndex / 8;
	byte vectorBitIndex = 1 << (bitIndex % 8);

	if (vectorIndex >= size())
		return false;

	byte val = get(vectorIndex);

	return val & vectorBitIndex;
}

void DeltaBitArray::clearBit(int bitIndex) {
	setBit(bitIndex, 0);
}

int DeltaBitArray::bitCount() const {
	return size() * 8;
}