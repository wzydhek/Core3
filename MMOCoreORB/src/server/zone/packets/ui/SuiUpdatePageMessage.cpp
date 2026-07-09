#include "SuiUpdatePageMessage.h"

SuiUpdatePageMessage::SuiUpdatePageMessage(SuiPageData* sui) {
	insertShort(0x02);
	insertInt(0x5F3342F6);

	sui->toBinaryStream(this);

	setCompression(true);
}