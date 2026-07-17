/*
 * DataTableRow.h
 *
 *  Created on: Feb 11, 2011
 *      Author: crush
 */

#pragma once

#include "templates/datatables/DataTableCell.h"

namespace templates {
namespace datatables {

class DataTableRow {
	Vector<DataTableCell*> cells;

public:
	DataTableRow();

	~DataTableRow();

	void addCell(DataTableCell* c);

	DataTableCell* getCell(int idx);

	const DataTableCell* getCell(int idx) const;

	int getCellsSize() const;

	template <typename V>
	void getValue(int idx, V& out) const {
		cells.get(idx)->getValue(out);
	}
};

} // namespace datatables
} // namespace templates

using namespace templates::datatables;
