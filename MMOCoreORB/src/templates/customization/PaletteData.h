/*
 * PaletteData.h
 *
 *  Created on: 29/03/2012
 *      Author: victor
 */

#pragma once

#include "templates/datatables/DataTableRow.h"

namespace templates {
namespace customization {

class PaletteData : public Object {
protected:
	String name;
	int creationColumns;
	int creationIndexes;
	int idNoviceColumns;
	int idNoviceIndexes;
	int idLevel1Columns;
	int idLevel1Indexes;
	int idLevel2Columns;
	int idLevel2Indexes;
	int idLevel3Columns;
	int idLevel3Indexes;
	int idLevel4Columns;
	int idLevel4Indexes;
	int idMasterColumns;
	int idMasterIndexes;

public:
	PaletteData();

	void readObject(DataTableRow* row);

	int getCreationColumns() const;

	int getCreationIndexes() const;

	int getIdLevel1Columns() const;

	int getIdLevel1Indexes() const;

	int getIdLevel2Columns() const;

	int getIdLevel2Indexes() const;

	int getIdLevel3Columns() const;

	int getIdLevel3Indexes() const;

	int getIdLevel4Columns() const;

	int getIdLevel4Indexes() const;

	int getIdMasterColumns() const;

	int getIdMasterIndexes() const;

	void setIdMasterIndexes(int idMasterIndexes);

	int getIdNoviceColumns() const;

	int getIdNoviceIndexes() const;

	String getName();
};

} // namespace customization
} // namespace templates

using namespace templates::customization;
