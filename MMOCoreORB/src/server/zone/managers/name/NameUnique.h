#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace name {

class NameUnique : public Object {

protected:
	String word, root, type;

public:
	NameUnique();

	~NameUnique();

	NameUnique(const NameUnique& obj);

	NameUnique(String uWord, String uRoot, String uType);

	String getWord();

	String getRoot();

	String getType();
};

} // namespace name
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::name;
