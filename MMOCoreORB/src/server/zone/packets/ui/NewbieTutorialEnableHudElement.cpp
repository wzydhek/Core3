#include "NewbieTutorialEnableHudElement.h"

NewbieTutorialEnableHudElement::NewbieTutorialEnableHudElement(const String& element, bool enable, float blinkCount) : BaseMessage() {
	insertShort(0x04);
	insertInt(0xCA375124); // CRC

	insertAscii(element); // see elements above.
	insertBoolean(enable);
	insertFloat(blinkCount); // times the element blinks
}