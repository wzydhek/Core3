/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class SearchKnowledgebaseResponseMessage : public BaseMessage {
	int articleCount;
public:
	SearchKnowledgebaseResponseMessage(bool success);

	void addArticle(const UnicodeString& title, const String& articleid);

	void updateCount();

	void updateFound(bool found);


};
