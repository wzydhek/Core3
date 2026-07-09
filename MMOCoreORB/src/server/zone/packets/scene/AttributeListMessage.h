/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
 namespace zone {
  namespace packets {
   namespace scene {

class AttributeListMessage : public BaseMessage {
	int listcount;
	int countLocation;

public:
	AttributeListMessage(SceneObject* object);

	AttributeListMessage(uint64 objectID, int listCount);

	AttributeListMessage(uint64 objectID);

	// For bazaar/vendor items
	AttributeListMessage(uint64 objectid, UnicodeString& description);

	void insertAttribute(const String& attribute, UnicodeString& value);

	void insertAttribute(const String& attribute, String& value);

	void insertAttribute(const String& attribute, const String& value);

	void insertAttribute(const String& attribute, StringBuffer& value);

	void insertAttribute(const String& attribute, float value);

	void insertAttribute(const String& attribute, int value);

	void insertAttribute(const String& attribute, int value, bool asInt);

	void updateListCount();

};

   }
  }
 }
}

using namespace server::zone::packets::scene;
