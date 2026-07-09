#include "SuiCreatePageMessage.h"

SuiCreatePageMessage::SuiCreatePageMessage(SuiPageData* sui) : optionOffset(0), optionCount(0) {
	insertShort(0x02);
	insertInt(0xD44B7259);

	sui->toBinaryStream(this);

	setCompression(true);
}

SuiCreatePageMessage::SuiCreatePageMessage(uint32 pageID, const String& scriptClass) : BaseMessage() {
	optionOffset = 0;
	optionCount = 2; // Header and footer

	insertShort(0x02);
	insertInt(0xD44B7259); // CRC
	insertInt(pageID);
	insertAscii(scriptClass);
	insertInt(0); // option count

	// Calculate the offset for the optionCount (priority+crc+pageid+asciiSize+ascii+4):
	optionOffset = 16 + scriptClass.length();

	setCompression(true);
}

/**
 * Insert's a UI-Body option into the packet. Should only be accessed by methods in SuiBoxImplementation
 * See packet trac docs for more info.
 * \param optionType Type of UI option to add
 * \param value Value to set the setting to.
 * \param variable SWG-UI Classpath to access
 * \param setting SWG-UI setting within the UI class to modify
 */
void SuiCreatePageMessage::insertOption(uint8 optionType, const String& value, const String& variable, const String& setting) {
	insertByte(optionType); // Option Type. 1=Data Container Option. 3=Data Value Option. 4=Container Data Header Option
	optionCount++;

	// System::out << "Adding Option, OptCount[" << optionCount << "]." << variable << "." << setting << "=" << value << endl;
	// Data Value Option and Header Option are the same
	if ((optionType == 3) || (optionType == 4)) {
		insertInt(1); // number of Unicodes
		UnicodeString val = UnicodeString(value);
		insertUnicode(val);

		insertInt(2); // number of ASCIIS
		insertAscii(variable.toCharArray());
		insertAscii(setting.toCharArray());

	} else {								 // For type #1, Data Container Option (used to delcare a list of options, like in dataList)
		insertInt(0);						 // 0 unicodes
		insertInt(1);						 // 1 ascii
		insertAscii(variable.toCharArray()); // ex. List.dataList
	}

	// Update the option count
	insertInt(optionOffset, optionCount);
}

/**
 * Insert's a UI-Header option into the packet. Should only be accessed by methods in SuiBoxImplementation
 * See packet trac docs for more info
 * \param variable SWG-UI Class var to access
 * \param type Datatype of the UI var
 * \param noCount Internal packet variable used to determine weather or not to count the option towards the total packet options
 */
void SuiCreatePageMessage::insertHeaderOption(const String& variable, const String& type) {
	// System::out << "Adding Header Option, OptCount[" << optionCount << "]." << variable << " with type " << type << endl;

	insertAscii(variable.toCharArray());
	insertAscii(type.toCharArray());
}

/**
 * Insert's a UI-Footer option into the packet. Should only be accessed by methods in SuiBoxImplementation
 * \param type Type of footer to insert.
 */
void SuiCreatePageMessage::insertFooter(uint64 usingObjectID, float distance, int type) {
	insertLong(usingObjectID);
	if (type == 0) {
		insertFloat(distance);
		insertLong(0);
	} else if (type == 1) {
		insertInt(0x7F7FFFFF);
		insertInt(0x7F7FFFFF);
		insertInt(0x7F7FFFFF);
		insertInt(0);
	}
}

void SuiCreatePageMessage::setOptionCount(int optCnt) {
	optionCount = optCnt;
}

int SuiCreatePageMessage::getOptionCount() {
	return optionCount;
}
