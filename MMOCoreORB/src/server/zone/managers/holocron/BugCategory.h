/*
 * BugCategory.h
 *
 *  Created on: Nov 22, 2010
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"

class BugCategory : public Object {
	UnicodeString categoryName;
	uint32 categoryId;
	byte unk1;
	byte unk2;

	Vector<BugCategory> children;

public:
	BugCategory();

	BugCategory(const UnicodeString& name, uint32 id, byte u1 = 1, byte u2 = 1);

	BugCategory(const BugCategory& cat);

	BugCategory& operator=(const BugCategory& cat);

	void addCategory(const BugCategory& cat);

	int compareTo(const BugCategory& cat) const;

	void insertToMessage(Message* message);

	void setCategoryName(const UnicodeString& name);

	void setCategoryId(uint32 id);

	void setUnk1(byte u1);

	void setUnk2(byte u2);
};
