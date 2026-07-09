#include "PaletteColor.h"

PaletteColor::PaletteColor() {
	red = green = blue = unknown = 0;
}

PaletteColor::PaletteColor(const PaletteColor& c) : Object() {
	red = c.red;
	green = c.green;
	blue = c.blue;
	unknown = c.unknown;
}

PaletteColor& PaletteColor::operator=(const PaletteColor& c) {
	if (this == &c)
		return *this;

	red = c.red;
	green = c.green;
	blue = c.blue;
	unknown = c.unknown;

	return *this;
}

void PaletteColor::readObject(ObjectInputStream* stream) {
	red = stream->readByte();
	green = stream->readByte();
	blue = stream->readByte();
	unknown = stream->readByte();
}

uint8 PaletteColor::getRed() {
	return red;
}

uint8 PaletteColor::getGreen() {
	return green;
}

uint8 PaletteColor::getBlue() {
	return blue;
}