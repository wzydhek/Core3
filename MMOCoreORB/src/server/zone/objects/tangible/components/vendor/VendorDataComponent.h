/*
 * VendorDataComponent.h
 *
 *  Created on: 5/27/2012
 *      Author: kyle
 */

#pragma once

#include "AuctionTerminalDataComponent.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/auction/AuctionsMap.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace vendor {

class VendorDataComponent: public AuctionTerminalDataComponent {
protected:
	uint64 ownerId;

	Reference<Task*> vendorCheckTask;

	bool initialized;
	bool vendorSearchEnabled;
	bool disabled;
	bool registered;

	SerializableTime lastSuccessfulUpdate;

	int maintAmount;

	SerializableTime lastXpAward;
	int awardUsageXP;

	bool adBarking;

	SerializableTime emptyTimer;
	SerializableTime inactiveTimer;

	bool mail1Sent;

	Vector<uint64> vendorBarks;
	uint64 lastBark;
	SerializableString barkMessage;
	SerializableString barkMood;
	SerializableString barkAnimation;

	float originalDirection;

	Mutex adBarkingMutex;

public:

	enum {
		USEXPINTERVAL       = 5, // 5 minutes

		VENDORCHECKINTERVAL = 60, // 60 Minutes
		VENDORCHECKDELAY    = 20, // 20 Minutes

		EMPTYWARNING        = 60 * 60 * 24 * 14, // 14 days
		EMPTYDELETE         = 60 * 60 * 24 * 28, // 28 days

		DELETEWARNING       = 60 * 60 * 24 * 100, // 100 days

		BARKRANGE           = 15, // 15 Meters
		BARKINTERVAL        = 60 * 2 // 2 Minutes
	};

public:
	VendorDataComponent();

	virtual ~VendorDataComponent();

	void initializeTransientMembers();

	void notifyObjectDestroyingFromDatabase();

	void runVendorUpdate();

	void writeJSON(nlohmann::json& j) const;

	void setOwnerId(uint64 id);

	uint64 getOwnerId();

	bool isVendorData();

	void setInitialized(bool val);

	void setVendorSearchEnabled(bool enabled);

	void setDisabled(bool isDisabled);

	void setRegistered(bool reg);

	int getOwnershipRightsOf(CreatureObject* player);

	bool isVendorOwner(CreatureObject* player);

	bool isInitialized();

	bool isVendorSearchEnabled();

	bool isDisabled();

	bool isRegistered();

	void awardUseXP();

	bool isAdBarkingEnabled();

	void setAdBarking(bool value);

	bool isEmpty();

	void setEmpty();

	int getMaint();

	bool isOnStrike();

	void setAdPhrase(const String& message);

	void setAdMood(const String& mood);

	void setAdAnimation(const String& animation);

	String getAdPhrase();

	String getAdMood();

	String getAdAnimation();

	bool hasBarkTarget(uint64 targetID);

	void addBarkTarget(uint64 targetID);

	bool canBark();

	void resetLastBark();

	void removeBarkTarget(uint64 targetID);

	void removeAllVendorBarks();

	float getOriginalDirection();

	float getMaintenanceRate();

	void payMaintanence();

	void withdrawMaintanence();

	void handlePayMaintanence(int value);

	void handleWithdrawMaintanence(int value);

	void performVendorBark(SceneObject* target);

	void scheduleVendorCheckTask(int delay); // In minutes

	void cancelVendorCheckTask();

private:
	void addSerializableVariables();
};

} // namespace vendor
} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components::vendor;
