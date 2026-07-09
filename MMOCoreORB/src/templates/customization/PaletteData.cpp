#include "PaletteData.h"

PaletteData::PaletteData() {
	creationColumns = creationIndexes = idNoviceColumns = idNoviceIndexes = idLevel1Columns = idLevel1Indexes = idLevel2Columns = idLevel2Indexes = idLevel3Columns = idLevel3Indexes = idLevel4Columns = idLevel4Indexes = idMasterColumns = idMasterIndexes = 0;
}

void PaletteData::readObject(DataTableRow* row) {
	row->getValue(0, name);
	row->getValue(1, creationColumns);
	row->getValue(2, creationIndexes);
	row->getValue(3, idNoviceColumns);
	row->getValue(4, idNoviceIndexes);
	row->getValue(5, idLevel1Columns);
	row->getValue(6, idLevel1Indexes);
	row->getValue(7, idLevel2Columns);
	row->getValue(8, idLevel2Indexes);
	row->getValue(9, idLevel3Columns);
	row->getValue(10, idLevel3Indexes);
	row->getValue(11, idLevel4Columns);
	row->getValue(12, idLevel4Indexes);
	row->getValue(13, idMasterColumns);
	row->getValue(14, idMasterIndexes);
}

int PaletteData::getCreationColumns() const {
	return creationColumns;
}

int PaletteData::getCreationIndexes() const {
	return creationIndexes;
}

int PaletteData::getIdLevel1Columns() const {
	return idLevel1Columns;
}

int PaletteData::getIdLevel1Indexes() const {
	return idLevel1Indexes;
}

int PaletteData::getIdLevel2Columns() const {
	return idLevel2Columns;
}

int PaletteData::getIdLevel2Indexes() const {
	return idLevel2Indexes;
}

int PaletteData::getIdLevel3Columns() const {
	return idLevel3Columns;
}

int PaletteData::getIdLevel3Indexes() const {
	return idLevel3Indexes;
}

int PaletteData::getIdLevel4Columns() const {
	return idLevel4Columns;
}

int PaletteData::getIdLevel4Indexes() const {
	return idLevel4Indexes;
}

int PaletteData::getIdMasterColumns() const {
	return idMasterColumns;
}

int PaletteData::getIdMasterIndexes() const {
	return idMasterIndexes;
}

void PaletteData::setIdMasterIndexes(int idMasterIndexes) {
	this->idMasterIndexes = idMasterIndexes;
}

int PaletteData::getIdNoviceColumns() const {
	return idNoviceColumns;
}

int PaletteData::getIdNoviceIndexes() const {
	return idNoviceIndexes;
}

String PaletteData::getName() {
	return name;
}