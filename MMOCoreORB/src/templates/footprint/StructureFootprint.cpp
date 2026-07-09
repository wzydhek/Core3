#include "StructureFootprint.h"

StructureFootprint::StructureFootprint() {
	rowSize = 0;
	colSize = 0;

	centerX = 0;
	centerY = 0;

	rowChunkSize = 0.f;
	colChunkSize = 0.f;
}

StructureFootprint::StructureFootprint(const StructureFootprint& sfp) : Object(), TemplateData(), IffTemplate() {
	rowSize = sfp.rowSize;
	colSize = sfp.colSize;

	centerX = sfp.centerX;
	centerY = sfp.centerY;

	rowChunkSize = sfp.rowChunkSize;
	colChunkSize = sfp.colChunkSize;

	rows = sfp.rows;
}

StructureFootprint& StructureFootprint::operator=(const StructureFootprint& sfp) {
	if (this == &sfp)
		return *this;

	rowSize = sfp.rowSize;
	colSize = sfp.colSize;

	centerX = sfp.centerX;
	centerY = sfp.centerY;

	rowChunkSize = sfp.rowChunkSize;
	colChunkSize = sfp.colChunkSize;

	rows = sfp.rows;

	return *this;
}

void StructureFootprint::readObject(IffStream* iffStream) {
	iffStream->openForm('FOOT');

	uint32 version = iffStream->getNextFormType();
	iffStream->openForm(version);

	switch (version) {
		case '0000': {
			Chunk* info = iffStream->openChunk('INFO');
			colSize = info->readInt();
			rowSize = info->readInt();
			centerX = info->readInt();
			centerY = info->readInt();
			colChunkSize = info->readFloat();
			rowChunkSize = info->readFloat();
			iffStream->closeChunk('INFO');

			// TODO: Parse chunk PRNT
		} break;
	}

	iffStream->closeForm(version);
	iffStream->closeForm('FOOT');
}

String StructureFootprint::toString() const {
	StringBuffer str;
	str << "{rowSize=" << rowSize << ";colSize=" << colSize << ";centerX=" << centerX << ";centerY=" << centerY << ";rowChunkSize=" << rowChunkSize << ";colChunkSize=" << colChunkSize << "}";

	return str.toString();
}

String StructureFootprint::toStringData() const {
	return toString();
}

float StructureFootprint::getRowSize() const {
	return rowSize;
}

float StructureFootprint::getColSize() const {
	return colSize;
}

float StructureFootprint::getCenterX() const {
	return centerX;
}

float StructureFootprint::getCenterY() const {
	return centerY;
}

float StructureFootprint::getRowChunkSize() const {
	return rowChunkSize;
}

float StructureFootprint::getColChunkSize() const {
	return colChunkSize;
}