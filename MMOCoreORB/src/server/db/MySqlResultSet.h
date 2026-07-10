/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#pragma once

#include <mysql.h>
#include "system/lang/Long.h"
#include "engine/db/ResultSet.h"

namespace server {
  namespace db {
    namespace mysql {

	class MySqlResultSet : public engine::db::ResultSet {
		MYSQL *mysql;

		MYSQL_RES *result;
		MYSQL_ROW row;

	public:
		MySqlResultSet(MYSQL *db, MYSQL_RES *res);

		virtual ~MySqlResultSet();

		bool next();

		bool getBoolean(int index);

		int getInt(int index);

		sys::uint32 getUnsignedInt(int index);

		sys::int64 getLong(int index);

		sys::uint64 getUnsignedLong(int index);

		float getFloat(int index);

		char *getString(int index);

		sys::uint64 getRowsAffected();

		sys::uint64 getLastAffectedRow();

		sys::uint64 size();
	};

    } // namespace mysql
  } // namespace db
} // namespace engine

using namespace server::db::mysql;
