/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \class SuiCreatePageMessage
 * Packet. See trac documentation for detailed variable information.
 * Manipulated and built heavily in SuiBoxImplementation
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/player/sui/SuiPageData.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class SuiCreatePageMessage : public BaseMessage {
	int optionOffset;
	int optionCount;

public:
	SuiCreatePageMessage(SuiPageData* sui);

   SuiCreatePageMessage(uint32 pageID, const String& scriptClass);

	/**
	 * Insert's a UI-Body option into the packet. Should only be accessed by methods in SuiBoxImplementation
	 * See packet trac docs for more info.
	 * \param optionType Type of UI option to add
	 * \param value Value to set the setting to.
	 * \param variable SWG-UI Classpath to access
	 * \param setting SWG-UI setting within the UI class to modify
	 */
   void insertOption(uint8 optionType, const String& value, const String& variable, const String& setting);

	/**
	 * Insert's a UI-Header option into the packet. Should only be accessed by methods in SuiBoxImplementation
	 * See packet trac docs for more info
	 * \param variable SWG-UI Class var to access
	 * \param type Datatype of the UI var
	 * \param noCount Internal packet variable used to determine weather or not to count the option towards the total packet options
	 */
   void insertHeaderOption(const String& variable, const String& type);

	/**
	 * Insert's a UI-Footer option into the packet. Should only be accessed by methods in SuiBoxImplementation
	 * \param type Type of footer to insert.
	 */
   void insertFooter(uint64 usingObjectID, float distance = 10, int type = 0);

	void setOptionCount(int optCnt);

	int getOptionCount();

};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
