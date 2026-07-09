#include "BaseAPIProxy.h"

BaseAPIProxy::BaseAPIProxy(const String& managerName) {
	mManagerName = managerName;
}

server::zone::ZoneServer* BaseAPIProxy::getZoneServer() {
	return ServerCore::getZoneServer();
}