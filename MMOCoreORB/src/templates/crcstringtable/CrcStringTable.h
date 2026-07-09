#pragma once

#include "templates/IffTemplate.h"

class CrcStringTable : public IffTemplate {
	VectorMap<uint32, String> tableData;

public:
	CrcStringTable();
	~CrcStringTable();

	void readObject(IffStream* iffStream);

	VectorMap<uint32, String> getTableData();
};
