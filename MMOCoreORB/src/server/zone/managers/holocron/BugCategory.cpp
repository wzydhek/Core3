#include "BugCategory.h"

BugCategory::BugCategory() {
	categoryId = 0;
	unk1 = 0;
	unk2 = 0;
}

BugCategory::BugCategory(const UnicodeString& name, uint32 id, byte u1, byte u2) {
	categoryName = name;
	categoryId = id;
	unk1 = u1;
	unk2 = u2;
}

BugCategory::BugCategory(const BugCategory& cat) : Object() {
	categoryName = cat.categoryName;
	categoryId = cat.categoryId;
	unk1 = cat.unk1;
	unk2 = cat.unk2;

	children = cat.children;
}

BugCategory& BugCategory::operator=(const BugCategory& cat) {
	if (this == &cat)
		return *this;

	categoryName = cat.categoryName;
	categoryId = cat.categoryId;
	unk1 = cat.unk1;
	unk2 = cat.unk2;

	children = cat.children;

	return *this;
}

void BugCategory::addCategory(const BugCategory& cat) {
	children.add(cat);
}

int BugCategory::compareTo(const BugCategory& cat) const {
	if (categoryId < cat.categoryId)
		return 1;
	else if (categoryId > cat.categoryId)
		return -1;
	else
		return 0;
}

void BugCategory::insertToMessage(Message* message) {
	message->insertUnicode(categoryName);
	message->insertInt(categoryId);

	message->insertInt(children.size());

	for (int i = 0; i < children.size(); ++i) {
		BugCategory* category = &children.get(i);

		if (category == nullptr)
			continue;

		category->insertToMessage(message);
	}

	message->insertByte(unk1);
	message->insertByte(unk2);
}

void BugCategory::setCategoryName(const UnicodeString& name) {
	categoryName = name;
}

void BugCategory::setCategoryId(uint32 id) {
	categoryId = id;
}

void BugCategory::setUnk1(byte u1) {
	unk1 = u1;
}

void BugCategory::setUnk2(byte u2) {
	unk2 = u2;
}