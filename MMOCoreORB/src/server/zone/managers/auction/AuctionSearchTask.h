#pragma once

#include "server/zone/managers/auction/AuctionManager.h"

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionSearchTask : public Task {
	ManagedWeakReference<AuctionManager*> auctionManager;
	ManagedWeakReference<CreatureObject*> player;
	ManagedWeakReference<SceneObject*> vendorInUse;
	ManagedWeakReference<SceneObject*> vendor;
	String planet, region;
	int screen, minPrice, maxPrice, clientCounter, offset;
	bool includeEntranceFee;
	int32 category;
	UnicodeString filterText;

public:
	AuctionSearchTask(AuctionManager* manager, CreatureObject* play, SceneObject* uVendor, const String& plnt, const String& reg, SceneObject* vend, int scr, uint32 cat, const UnicodeString& filter, int minP, int maxP, bool entFee, int counter, int off);

	void run();
};

}
}
}
}
