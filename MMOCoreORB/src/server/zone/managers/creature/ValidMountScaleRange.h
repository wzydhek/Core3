#pragma once

#include "templates/datatables/DataTableRow.h"
#include "templates/params/primitives/StringParam.h"

class ValidMountScaleRange : public Object {
protected:
	StringParam appearanceFilename;
	int saddleCapacity;
	float validScaleMin;
	float validScaleMax;

public:
	ValidMountScaleRange();

	~ValidMountScaleRange();

	void parseDataTableRow(DataTableRow* row);

	String getAppearanceFilename() const;

	int getSaddleCapacity();

	float getValidScaleMin();

	float getValidScaleMax();

};
