/*
 * OnlineZoneClientMap.h
 *
 *  Created on: 11/06/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/ZoneClientSession.h"
#include "server/db/ServerDatabase.h"
#include "server/ServerCore.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class OnlineZoneClientMap : public HashTable<uint32, Vector<Reference<ZoneClientSession*> > >, private Logger {
protected:
	HashTable<String, Reference<SortedVector<uint32>*> > ip_list;
	ReadWriteLock mutex;

	using self_table_type = HashTable<uint32, Vector<Reference<ZoneClientSession*> > >;

public:
	OnlineZoneClientMap();

	void accountLoggedIn(const String& ip, uint32 accountId, int galaxyId);

	void accountLoggedOut(const String& ip, uint32 accountId, int galaxyId);

	SortedVector<uint32> getAccountsLoggedIn(const String& ip);

	int getDistinctIps() const;

private:
#ifndef WITH_SWGREALMS_API
	void insertLogEntry(uint32 accountId, int galaxyId, const String& ipAddress, int logout, int onlineCount);
#endif // !WITH_SWGREALMS_API
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;
