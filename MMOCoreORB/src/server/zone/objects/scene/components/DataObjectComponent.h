/*
 * DataObjectComponent.h
 *
 *  Created on: 18/03/2012
 *      Author: victor
 */

#pragma once

#include "SceneObjectComponent.h"
#include "engine/util/json_utils.h"

#define SERIALIZE_JSON_MEMBER(x) j[#x] = x;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

class DataObjectComponent : public SceneObjectComponent, public Serializable {
protected:
	ManagedWeakReference<SceneObject*> parent;

public:

	DataObjectComponent();

	~DataObjectComponent();

	friend void to_json(nlohmann::json& j, const DataObjectComponent& comp);

	virtual void writeJSON(nlohmann::json& j) const;

	virtual void initializeTransientMembers();

	virtual void notifyObjectDestroyingFromDatabase();

	void setParent(SceneObject* object);

	SceneObject* getParent();

	virtual bool isDiceData();

	virtual bool isFireworkShowData();

	virtual bool isVendorData();

	virtual bool isAuctionTerminalData();

	virtual bool isCreatureHabitatData();

	virtual bool isBuildingData();

	virtual bool isDestructibleBuildingData();

	virtual bool isTurretData();

	virtual bool isScannerData();

	virtual bool isGCWBaseData();

	virtual bool isSecurityTerminalData();

	virtual bool isMinefieldData();

	virtual bool isTurretControlTerminalData();

	virtual bool isDecoration();

	virtual bool isCoaMessageData();

	virtual bool isEventPerkData();

	virtual bool isFlagGameData();

	virtual bool isDataStorageUnitData();

	virtual bool isDroidModuleData();

	virtual bool isGamblingTerminalData();

};
