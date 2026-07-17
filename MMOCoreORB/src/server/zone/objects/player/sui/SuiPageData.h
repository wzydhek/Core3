/*
 * SuiPageData.h
 *
 *  Created on: Nov 7, 2013
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"
#include "SuiCommand.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {

class SuiPageData : public Logger, public Object {
	int32 id;
	String rootPage;
	uint64 targetNetworkId;
	float forceCloseDistance;
	uint64 unknownNetworkId;

	Vector<Reference<SuiCommand*> > commands;
	VectorMap<String, String> storedData;
	VectorMap<byte, Reference<SuiCommand*> > callbacks;

public:
	SuiPageData(const String& rootPage);

	SuiPageData(const String& rootPage, const uint64& targetNetworkId, const float& forceCloseDistance);

	void setProperty(const String& widget, const String& property, const UnicodeString& value);
	UnicodeString getPropertyValue(const String& widget, const String& property);
	void addDataItem(const String& widget, const String& property, const UnicodeString& value);
	void clearDataSource(const String& dataSource);
	void addDataSourceContainer(const String& parent, const String& name);
	void clearDataSourceContainer(const String& dataSourceContainer);
	void addChildWidget(const String& parent, const String& type, const String& name);
	void subscribeToEvent(const byte& eventType, const String& parent, const String& callback);
	void subscribeToPropertyForEvent(const byte& eventType, const String& widget, const String& property);

	bool toBinaryStream(ObjectOutputStream* stream);
	bool parseFromBinaryStream(ObjectInputStream* stream);

	void sendTo(CreatureObject* creo);
	void sendUpdateTo(CreatureObject* creo);

	void setStoredData(const String& key, const String& value);

	void deleteStoredData(const String& key);

	String getStoredData(const String& key);

	void setPageId(int pageId);

	int32 getPageId();

	void setForceCloseDistance(float dist);

	float getForceCloseDistance();

	void setTargetNetworkId(uint64 id);

	SuiCommand* getCommand(int index);

	uint64 getTargetNetworkId();

	String& getRootPage();

private:
	void init(const String& rootPage, const uint64& targetNetworkId, const float& forceCloseDistance);

};

} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui;
