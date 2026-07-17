/*
 * NewbieTutorialEnableHudElement.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

/* Valid elements found:
 * radar
 * toolbar
 * buttonbar
 * hambar
 * chatbox
 * all
 */
class NewbieTutorialEnableHudElement : public BaseMessage {
public:

	/**
	 * Enables or disables a HUD element on the client.
	 * @param element String of element
	 * @param enable If true, element is visible, otherwise disables element
	 * @param binkCount times the element will blink
	 */
	NewbieTutorialEnableHudElement(const String& element, bool enable = true, float blinkCount = 0.f);

};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
