#include "HeightMapPlane.h"

HeightMapPlane::HeightMapPlane(int idx, int size) {
	buffer = new byte[size * size * sizeof(float)];

	index = idx;
	planeSize = size;
}

HeightMapPlane::~HeightMapPlane() {
	delete[] buffer;
}

// getters
byte* HeightMapPlane::getBuffer() {
	return buffer;
}

float HeightMapPlane::getHeight(int x, int y) {
	int offset = x + planeSize * y;

	if (x > planeSize || x < 0 || y > planeSize || y < 0)
		throw ArrayIndexOutOfBoundsException(offset);

	return ((float*)buffer)[offset];
}

int HeightMapPlane::getIndex() {
	return index;
}

// setters
void HeightMapPlane::setIndex(int idx) {
	index = idx;
}