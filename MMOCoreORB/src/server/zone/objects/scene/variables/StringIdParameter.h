/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "StringId.h"

namespace server {
namespace chat {
	class StringIdChatParameter;
}
}

using namespace server::chat;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

namespace variables {

class StringIdParameter : public Serializable {
protected:
	uint64 pointerParameter = 0;
	StringId stringID;
	UnicodeString customName;

	StringIdParameter();

private:
	void addSerializableVariables();

public:
	StringIdParameter(const StringIdParameter& par);

#ifdef CXX11_COMPILER
	StringIdParameter(StringIdParameter&& par);
#endif

	StringIdParameter& operator=(const StringIdParameter& par);

#ifdef CXX11_COMPILER
	StringIdParameter& operator=(StringIdParameter&& par);
#endif


	void set(const StringId* sid);
	void set(const StringId& sid);

	void clear();

	void set(uint64 oid);

	void set(const String& file, const String& id);

	void set(const UnicodeString& us);

	void set(const String& cs);

	void set(const char* cstr);

	uint32 size() const;

	uint64 getPointerParameter() const;

	const UnicodeString& getUnicodeParameter() const;

	String getDisplayedName() const;

	const String& getFileParameter() const;

	const String& getStringIDParameter() const;

	friend void to_json(nlohmann::json& j, const StringIdParameter& p);

	friend class server::chat::StringIdChatParameter;
};

void to_json(nlohmann::json& j, const StringIdParameter& p);
}
}
}
}
}

using namespace server::zone::objects::scene::variables;
