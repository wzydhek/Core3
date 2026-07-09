#include "ValidMountScaleRange.h"

ValidMountScaleRange::ValidMountScaleRange() {
	saddleCapacity = 0;
	validScaleMin = 1;
	validScaleMax = 1;
}

ValidMountScaleRange::~ValidMountScaleRange() {
}

void ValidMountScaleRange::parseDataTableRow(DataTableRow* row) {
	String filename;
	row->getValue(0, filename);
	appearanceFilename.setValue(filename);

	row->getValue(1, saddleCapacity);
	row->getValue(2, validScaleMin);
	row->getValue(3, validScaleMax);
}

String ValidMountScaleRange::getAppearanceFilename() const {
	return appearanceFilename;
}

int ValidMountScaleRange::getSaddleCapacity() {
	return saddleCapacity;
}

float ValidMountScaleRange::getValidScaleMin() {
	return validScaleMin;
}

float ValidMountScaleRange::getValidScaleMax() {
	return validScaleMax;
}