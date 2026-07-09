#include "PaletteTemplate.h"

PaletteTemplate::PaletteTemplate() {
}

void PaletteTemplate::readObject(ObjectInputStream* stream) {
	uint32 riff = stream->readNetInt();

	if (riff != 'RIFF')
		return;

	uint32 size = stream->readInt();

	if (size < 12) // PAL + data + size
		return;

	uint32 type = stream->readNetInt();

	if (type != 'PAL ')
		return;

	uint32 data = stream->readNetInt();

	if (data != 'data')
		return;

	uint32 dataSize = stream->readInt();

	if (dataSize < 4)
		return;

	uint32 unk = stream->readInt();

	for (dataSize -= 4; dataSize > 0; dataSize -= 4) {
		PaletteColor color;
		color.readObject(stream);

		colors.add(color);
	}
}

const Vector<PaletteColor>& PaletteTemplate::getColors() const {
	return colors;
}

int PaletteTemplate::getColorCount() const {
	return colors.size();
}