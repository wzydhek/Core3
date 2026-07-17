/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class SearchKnowledgebaseResponseMessage : public BaseMessage {
	int articleCount;
public:
	SearchKnowledgebaseResponseMessage(bool success);

	void addArticle(const UnicodeString& title, const String& articleid);

	void updateCount();

	void updateFound(bool found);


};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
