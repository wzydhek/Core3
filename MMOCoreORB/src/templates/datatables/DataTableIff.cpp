/*
 * DataTableIff.cpp
 *
 *  Created on: Feb 11, 2011
 *      Author: crush
 */

#include "templates/datatables/DataTableIff.h"
#include "templates/datatables/DataTableCell.h"
#include "templates/datatables/DataTableRow.h"

DataTableIff::DataTableIff() {

}

DataTableIff::~DataTableIff() {
	clearDataTable();
}

void DataTableIff::clearDataTable() {
	columns.removeAll();
	columnTypes.removeAll();

	rows.forEach([](auto row) { delete row; });
}

void DataTableIff::readObject(IffStream* iffStream) {
	iffStream->openForm('DTII');

	uint32 version = iffStream->getNextFormType();
	iffStream->openForm(version);

	//Parse the columns
	Chunk* chunk = iffStream->openChunk('COLS');
	uint32 totalColumns = chunk->readInt();

	for (int i = 0; i < totalColumns; ++i) {
		String columnName;
		chunk->readString(columnName);

		columns.add(columnName);
	}

	iffStream->closeChunk('COLS');

	//Parse the types
	chunk = iffStream->openChunk('TYPE');

	for (int i = 0; i < totalColumns; ++i) {
		String typeName;
		chunk->readString(typeName);

		columnTypes.add(typeName.charAt(0)); //Just need the first character to know the type. Default value doesn't seem to matter.
	}

	iffStream->closeChunk('TYPE');

	chunk = iffStream->openChunk('ROWS');
	uint32 totalRows = chunk->readInt();

	for (int i = 0; i < totalRows; ++i) {
		DataTableRow* row = new DataTableRow();

		for (int j = 0; j < totalColumns; ++j) {
			byte type = columnTypes.get(j);

			DataTableCell* cell = nullptr;

			switch (type) {
			case 'f':
				cell = new DataTableCellFloat();
				cell->parse(chunk);
				break;
			case 's':
				cell = new DataTableCellString();
				cell->parse(chunk);
				break;
			case 'h':
				cell = new DataTableCellHex();
				cell->parse(chunk);
				break;
			case 'b':
				cell = new DataTableCellBinary();
				cell->parse(chunk);
				break;
			case 'c':
			case 'p':
			case 'e':
			case 'z':
			case 'i':
			case 'I':
			default:
				cell = new DataTableCellInt();
				cell->parse(chunk);
				break;
			}

			row->addCell(cell);
		}

		rows.add(row);
	}

	iffStream->closeChunk('ROWS');

	iffStream->closeForm(version);

	iffStream->closeForm('DTII');
}

Vector<const DataTableRow*> DataTableIff::getRowsByColumn(int columnIdx, const String& columnValue) const {
	Vector<const DataTableRow*> retRows;

	for (int i = 0; i < rows.size(); ++i) {
		const DataTableRow* row = rows.get(i);

		if (row->getCell(columnIdx)->toString() == columnValue)
			retRows.add(row);
	}

	return retRows;
}

/**
 * Returns the column header name based on the column index.
 * @param idx The index of the column to retrieve the header name for.
 * @return Returns the header name as a String.
 */
String DataTableIff::getColumnNameByIndex(int idx) const {
	return columns.get(idx);
}

/**
 * Returns the index of the column with the header name passed.
 * @param name The name of the column header to retrieve the index of.
 * @return The index of the column, or -1 if it wasn't found.
 */
int DataTableIff::getColumnIndexByName(const String& name) const {
	for (int i = 0; i < columns.size(); ++i) {
		if (columns.get(i) == name)
			return i;
	}

	return -1;
}

const DataTableRow* DataTableIff::getRow(int idx) const {
	return rows.get(idx);
}

DataTableRow* DataTableIff::getRow(int idx) {
	return rows.get(idx);
}

int DataTableIff::getTotalRows() const {
	return rows.size();
}

int DataTableIff::getTotalColumns() const {
	return columns.size();
}