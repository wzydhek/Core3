#include "HarvesterObjectMessage7.h"
#include "server/zone/managers/resource/ResourceManager.h"
#include "server/zone/Zone.h"

HarvesterObjectMessage7::HarvesterObjectMessage7(InstallationObject* hino) : BaseLineMessage(hino->getObjectID(), 0x48494E4F, 7, 0x05) {
	insertByte(1);

	Vector<ManagedReference<ResourceSpawn*>> resourceList;

	ResourceManager* resourceManager = hino->getZoneServer()->getResourceManager();
	resourceManager->getResourceListByType(resourceList, hino->getInstallationType(), hino->getZone()->getZoneName());

	insertHopperSpawnObjects(&resourceList, hino);

	insertResourceIDList(&resourceList);
	insertResourceNameList(&resourceList);
	insertResourceTypeList(&resourceList);

	/*insertLong(hino->getActiveResourceID());
	insertByte(hino->isActive());
	insertFloat(hino->getActualRate());
	insertFloat(hino->getSpecRate());
	insertFloat(hino->getTotalHopperQuantity());
	insertFloat(hino->getCapacity());

	insertInt(hino->getHopperSize());*/

	insertLong(hino->getActiveResourceSpawnID());
	insertByte(hino->isActive());
	insertInt((int)hino->getExtractionRate()); // Extraction Rate Displayed
	insertFloat(hino->getExtractionRate());	   // Extract Rate Max

	insertFloat(hino->getActualRate()); // Current Extract Rate

	insertFloat(hino->getHopperSize());
	insertInt((int)hino->getHopperSizeMax());

	insertHopperItems(hino);
	insertByte(100); // Percentage of Condition

	setSize();
}

void HarvesterObjectMessage7::insertHopperSpawnObjects(Vector<ManagedReference<ResourceSpawn*>>* resourceList, InstallationObject* hino) {
	HopperList* list = hino->getHopperList();

	for (int i = 0; i < list->size(); ++i) {
		ResourceSpawn* spawn = list->get(i)->getSpawnObject();

		if (!spawn->inShift())
			resourceList->add(spawn);
	}
}

void HarvesterObjectMessage7::insertResourceIDList(const Vector<ManagedReference<ResourceSpawn*>>* hino) {
	for (int x = 0; x < 2; x++) {
		insertInt(hino->size());
		insertInt(hino->size());
		for (int i = 0; i < hino->size(); i++) {
			insertLong(hino->get(i)->getObjectID());
		}
	}
}

void HarvesterObjectMessage7::insertResourceNameList(const Vector<ManagedReference<ResourceSpawn*>>* hino) {
	insertInt(hino->size());
	insertInt(hino->size());
	for (int i = 0; i < hino->size(); i++) {
		insertAscii(hino->get(i)->getName());
	}
}

void HarvesterObjectMessage7::insertResourceTypeList(const Vector<ManagedReference<ResourceSpawn*>>* hino) {
	insertInt(hino->size());
	insertInt(hino->size());
	for (int i = 0; i < hino->size(); i++) {
		insertAscii(hino->get(i)->getType());
	}
}

void HarvesterObjectMessage7::insertHopperItems(InstallationObject* hino) {
	HopperList* hopperList = hino->getHopperList();

	if (hopperList->size() == 0)
		insertByte(0);
	else
		insertByte(hopperList->size() + 1);

	hopperList->insertToMessage(this);
}