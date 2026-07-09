#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

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
