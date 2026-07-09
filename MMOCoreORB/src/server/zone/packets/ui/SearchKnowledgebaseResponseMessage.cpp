#include "SearchKnowledgebaseResponseMessage.h"

SearchKnowledgebaseResponseMessage::SearchKnowledgebaseResponseMessage(bool success) : BaseMessage() {
	articleCount = 0;
	insertShort(0x03);
	insertInt(0x7CBC8F67); // CRC

	if (success == true)
		insertInt(0); // option.  1 = found nothing. 0 = found.
	else
		insertInt(1);

	insertInt(0); // List count articles found.
}

void SearchKnowledgebaseResponseMessage::addArticle(const UnicodeString& title, const String& articleid) {
	insertUnicode(title);
	insertAscii(articleid);
	insertShort(0);

	updateCount();
}

void SearchKnowledgebaseResponseMessage::updateCount() {
	insertInt(14, ++articleCount);
}

void SearchKnowledgebaseResponseMessage::updateFound(bool found) {
	if (found == true) {
		insertInt(10, 0);
	} else {
		insertInt(10, 1);
	}
}