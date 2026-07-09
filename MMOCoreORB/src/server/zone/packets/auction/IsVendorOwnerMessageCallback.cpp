#include "IsVendorOwnerMessageCallback.h"
#include "IsVendorOwnerResponseMessage.h"
#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/Zone.h"

IsVendorOwnerMessageCallback::IsVendorOwnerMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	oid = 0;
}

void IsVendorOwnerMessageCallback::parse(Message* message) {
	oid = message->parseLong();
}

void IsVendorOwnerMessageCallback::run() {
	ManagedReference<SceneObject*> sceno = server->getZoneServer()->getObject(oid);

	if (sceno == nullptr)
		return;

	Zone* zone = sceno->getZone();

	if (zone == nullptr)
		return;

	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	String planetString = zone->getZoneName();
	String vendorRegion = zone->getZoneName();

	ManagedReference<CityRegion*> cityRegion = sceno->getCityRegion().get();
	if (cityRegion != nullptr)
		vendorRegion = cityRegion->getCityRegionName();

	IsVendorOwnerResponseMessage* msg = new IsVendorOwnerResponseMessage(sceno, player, planetString, vendorRegion);
	client->sendMessage(msg);
}