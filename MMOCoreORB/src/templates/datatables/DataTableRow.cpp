#include "DataTableRow.h"

DataTableRow::DataTableRow() {
}

DataTableRow::~DataTableRow() {
	cells.forEach([](auto cell) { delete cell; });
}

void DataTableRow::addCell(DataTableCell* c) {
	cells.add(c);
}

DataTableCell* DataTableRow::getCell(int idx) {
	return cells.get(idx);
}

const DataTableCell* DataTableRow::getCell(int idx) const {
	return cells.get(idx);
}

int DataTableRow::getCellsSize() const {
	return cells.size();
}