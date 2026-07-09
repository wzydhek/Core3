#include "ItemSoldMessage.h"

ItemSoldMessage::ItemSoldMessage(uint64 objectid, int status) {
	insertShort(3);
	insertInt(0x0E61CC92);

	insertLong(objectid);
	insertInt(status);
}

String ItemSoldMessage::statusToString(int status) {
	switch (status) {
		case SUCCESS:
			return String("SUCCESS");
		case INVALIDAUCTIONER:
			return String("INVALIDAUCTIONER");
		case INVALIDITEM:
			return String("INVALIDITEM");
		case VENDORNOTWORKING:
			return String("VENDORNOTWORKING");
		case INVALIDSALEPRICE:
			return String("INVALIDSALEPRICE");
		case INVALIDSALEDURATION:
			return String("INVALIDSALEDURATION");
		case ALREADYFORSALE:
			return String("ALREADYFORSALE");
		case UNKNOWNERROR:
			return String("UNKNOWNERROR");
		case NOTOWN:
			return String("NOTOWN");
		case NOTENOUGHCREDITS:
			return String("NOTENOUGHCREDITS");
		case TOOMANYITEMS:
			return String("TOOMANYITEMS");
		case OVER20000:
			return String("OVER20000");
	}

	StringBuffer msg;
	msg << "ItemSoldMessage::Unknown(" << status << ")";
	return msg.toString();
}