/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class GetArticleResponseMessage : public BaseMessage {
public:
	GetArticleResponseMessage(bool success);

   void insertArticle(const UnicodeString& article);
};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
