#include "GetArticleResponseMessage.h"

GetArticleResponseMessage::GetArticleResponseMessage(bool success) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x934BAEE0); // CRC

	if (success == true)
		insertInt(0); // option.  1 = couldnt retrieve. 0 = show article.
	else {
		insertInt(1);
		insertInt(0); // Blank Unicode string.
	}

	setCompression(true);
}

void GetArticleResponseMessage::insertArticle(const UnicodeString& article) {
	insertUnicode(article);
}