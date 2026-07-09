#include "AuctionTerminalDataComponent.h"

AuctionTerminalDataComponent::AuctionTerminalDataComponent() {
	uid = "";
	addSerializableVariables();
}

AuctionTerminalDataComponent::~AuctionTerminalDataComponent() {
}

void AuctionTerminalDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(uid);
}

void AuctionTerminalDataComponent::initializeTransientMembers() {
	ManagedReference<SceneObject*> strongParent = parent.get();
	if (strongParent != nullptr && strongParent->getZoneServer() != nullptr) {
		auctionMan = strongParent->getZoneServer()->getAuctionManager();
		if (uid.isEmpty())
			updateUID();
	}
}

void AuctionTerminalDataComponent::updateUID() {
	ManagedReference<SceneObject*> strongParent = parent.get();
	ManagedReference<AuctionManager*> auctionManager = auctionMan.get();

	if (auctionManager == nullptr || strongParent == nullptr || strongParent->getZone() == nullptr)
		return;

	String olduid = uid;

	uid = strongParent->getZone()->getZoneName() + ".";

	String region = "@planet_n:" + strongParent->getZone()->getZoneName();
	ManagedReference<CityRegion*> cityRegion = strongParent->getCityRegion().get();
	if (cityRegion != nullptr)
		region = cityRegion->getCityRegionName();

	uid += region + "." + strongParent->getDisplayedName() + ".";
	uid += String::valueOf(strongParent->getObjectID()) + "#";
	uid += String::valueOf(((int)strongParent->getWorldPositionX())) + "," + String::valueOf(((int)strongParent->getWorldPositionY()));

	if (olduid != uid)
		auctionManager->updateVendorUID(strongParent, olduid, uid);
}

String AuctionTerminalDataComponent::getUID() {
	return uid;
}

bool AuctionTerminalDataComponent::isAuctionTerminalData() {
	return true;
}

void AuctionTerminalDataComponent::addSerializableVariables() {
	addSerializableVariable("uid", &uid);
}