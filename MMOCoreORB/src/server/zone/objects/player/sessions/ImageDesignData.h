/*
 * ImageDesignData.h
 *
 *  Created on: Feb 16, 2011
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/variables/CustomizationVariables.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {

class ImageDesignData : public Object {
protected:
	String hairTemplate;
	CustomizationVariables hairCustomizationVariables;

	uint32 sessionID;
	uint32 timestamp;

	uint32 requiredPayment;
	uint32 offeredPayment;

	uint8 designerAccepted;
	uint32 targetAccepted;

	uint8 statMigrationRequested;

	uint32 bodySkillMod;
	uint32 faceSkillMod;
	uint32 markingsSkillMod;
	uint32 hairSkillMod;

	VectorMap<String, float> bodyAttributes;
	VectorMap<String, uint32> colorAttributes;

	String holoEmote;

public:
	ImageDesignData();

	ImageDesignData(const ImageDesignData& idd);

	ImageDesignData& operator=(const ImageDesignData& idd);

	void parse(Message* message);

	void insertToMessage(Message* message);

	bool isAcceptedByDesigner();

	bool isAcceptedByTarget();

	bool isStatMigrationRequested();

	uint32 getRequiredPayment();

	uint32 getOfferedPayment();

	String getHairTemplate();

	void setHairAttribute(const String& attr, int val);

	String getHairCustomizationString();

	VectorMap<String, float>* getBodyAttributesMap();

	VectorMap<String, uint32>* getColorAttributesMap();

	String getHoloEmote();
};

} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions;
