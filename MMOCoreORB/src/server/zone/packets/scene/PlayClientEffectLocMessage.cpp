#include "PlayClientEffectLocMessage.h"

PlayClientEffectLoc::PlayClientEffectLoc(const String& file, const String& zoneName, float x, float z, float y, uint64 cell, int terrainDelta, const String& label) : BaseMessage(), listSize(0) {
	/* Struct
	 * 09 00 // Operand
	 * 74 9E 94 02 // Opcode
	 * A_STRING (effect)
	 * A_STRING (planet)
	 * FLOAT // X
	 * FLOAT // Z
	 * FLOAT // Y
	 * 00 00 00 00 00 00 00 00
	 * 00 00 00 00
	 */
	insertShort(9);
	insertInt(0x02949E74);
	insertAscii(file);
	insertAscii(zoneName);
	insertFloat(x);
	insertFloat(z);
	insertFloat(y);
	insertLong(cell);
	insertInt(terrainDelta);
	insertAscii(label);
}