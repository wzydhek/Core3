/*
 * DataTableIff.h
 *
 *  Created on: Feb 11, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

namespace templates {
namespace datatables {

class DataTableRow;

class DataTableIff : public IffTemplate {
	Vector<String> columns;
	Vector<byte> columnTypes;
	Vector<DataTableRow*> rows;

public:
	DataTableIff();
	~DataTableIff();

	void readObject(IffStream* iffStream);

	void clearDataTable();

	/**
	 * Returns a collection of rows whose column specified by the column index matches the specified column value.
	 * @param columnIdx Which column to lookup.
	 * @param columnValue What value should be compared.
	 * @return Returns a collection of DataTableRow objects.
	 */
	Vector<const DataTableRow*> getRowsByColumn(int columnIdx, const String& columnValue) const;

	/**
	 * Returns the column header name based on the column index.
	 * @param idx The index of the column to retrieve the header name for.
	 * @return Returns the header name as a String.
	 */
	String getColumnNameByIndex(int idx) const;

	/**
	 * Returns the index of the column with the header name passed.
	 * @param name The name of the column header to retrieve the index of.
	 * @return The index of the column, or -1 if it wasn't found.
	 */
	int getColumnIndexByName(const String& name) const;

	const DataTableRow* getRow(int idx) const;

	DataTableRow* getRow(int idx);

	int getTotalRows() const;

	int getTotalColumns() const;
};

} // namespace datatables
} // namespace templates

using namespace templates::datatables;
