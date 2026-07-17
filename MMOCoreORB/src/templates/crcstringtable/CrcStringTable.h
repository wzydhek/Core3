#pragma once

#include "templates/IffTemplate.h"

namespace templates {
namespace crcstringtable {

class CrcStringTable : public IffTemplate {
	VectorMap<uint32, String> tableData;

public:
	CrcStringTable();
	~CrcStringTable();

	void readObject(IffStream* iffStream);

	VectorMap<uint32, String> getTableData();
};

} // namespace crcstringtable
} // namespace templates

using namespace templates::crcstringtable;
