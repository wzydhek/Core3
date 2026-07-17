/*
 * MantisDatabase.h
 *
 *  Created on: Nov 22, 2010
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"
#include "system/lang/ref/UniqueReference.h"

namespace conf {
	class ConfigManager;
}

namespace server {
namespace db {

class MantisDatabase {
	static UniqueReference<ArrayList<UniqueReference<Database*> >* > databases;
	static AtomicInteger currentDB;

	static String tablePrefix;

public:
	const static int DEFAULT_SERVERDATABASE_INSTANCES = 1;

	MantisDatabase(conf::ConfigManager* configManager);
	~MantisDatabase();

	static Database* instance();

	static const String& getTablePrefix();
};

} // namespace chat
} // namespace server

using namespace server::db;
