/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#ifndef WITH_SWGREALMS_API

#include "engine/engine.h"

namespace conf {
	class ConfigManager;
}

namespace server {
namespace db {

class ServerDatabase : public Logger {
	static Vector<Database*>* databases;
	static AtomicInteger currentDB;
	int dbSchemaVersion;

public:
	ServerDatabase(conf::ConfigManager* configManager);
	~ServerDatabase();

	static Database* instance();

	int getSchemaVersion() const;

private:
	void alterDatabase(int nextVersion, const String& alterSql);
	void updateDatabaseSchema();
};

} // namespace db
} // namespace server

using namespace server::db;

#endif // !WITH_SWGREALMS_API
