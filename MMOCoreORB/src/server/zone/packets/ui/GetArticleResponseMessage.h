/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class GetArticleResponseMessage : public BaseMessage {
public:
	GetArticleResponseMessage(bool success);

   void insertArticle(const UnicodeString& article);
};
