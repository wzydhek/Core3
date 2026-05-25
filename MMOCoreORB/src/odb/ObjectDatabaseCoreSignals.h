/**
 * @author      : theanswer (theanswer@Victors-MacBook-Pro.local)
 * @file        : ObjectDatabaseCoreSignals
 * @created     : Tuesday Mar 19, 2019 19:49:39 CET
 */

#pragma once

#include "engine/engine.h"
#include "system/lang/SignalException.h"

template<uint32 signal>
class ODB3SignalHandler {
	public:
		static void SignalHandler(int cause) {
			ObjectDatabaseManager::instance()->closeDatabases();

			exit(cause);
		}

		static int GetSignalNumber() {
			return signal;
		}
};
