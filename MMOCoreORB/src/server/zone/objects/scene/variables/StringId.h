/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {
namespace variables {

class StringId : public virtual Object {
protected:
	String file;
	int filler;
	String stringID;

public:
	StringId();
	StringId(const StringId& id);
	StringId(const char * cstr);
	StringId(const String& fullPath);
	StringId(const String& fil, const String& stringId);
	StringId(StringId&& id);

	StringId& operator=(const StringId& id);

	StringId& operator=(StringId&& id);

	bool operator==(const StringId& id) const;

	int compareTo(const StringId& id) const;

	void clear();

	void getFullPath(String& str) const;

	String getFullPath() const;

	const String& getFile() const;

	const String& getStringID() const;

	uint32 size() const;

	bool isEmpty() const;

	int getFiller() const;

	void setStringId(const String& fullPath);

	void setStringId(const String& file, const String& id);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	String toString() const;
};

void to_json(nlohmann::json& k, const server::zone::objects::scene::variables::StringId& str);

}
}
}
}
}

using namespace server::zone::objects::scene::variables;
