/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#pragma once

#include <mysql.h>

namespace server {
  namespace db {
    namespace mysql {

	class Row {
		MYSQL_ROW row;

	public:
		Row() {
		}

	};

} // namespace mysql
} // namespace db
} // namespace server

using namespace server::db::mysql;
