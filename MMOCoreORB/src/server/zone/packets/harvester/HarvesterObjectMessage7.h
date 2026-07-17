#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/installation/InstallationObject.h"
#include "server/zone/objects/resource/ResourceSpawn.h"

namespace server {
namespace zone {
namespace packets {
namespace harvester {

class HarvesterObjectMessage7 : public BaseLineMessage {
public:
	HarvesterObjectMessage7(InstallationObject* hino);

	void insertHopperSpawnObjects(Vector<ManagedReference<ResourceSpawn*>>* resourceList, InstallationObject* hino);

	void insertResourceIDList(const Vector<ManagedReference<ResourceSpawn*>>* hino);

	void insertResourceNameList(const Vector<ManagedReference<ResourceSpawn*>>* hino);

	void insertResourceTypeList(const Vector<ManagedReference<ResourceSpawn*>>* hino);

	void insertHopperItems(InstallationObject* hino);
};

} // namespace harvester
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::harvester;
