#include "NameUnique.h"

NameUnique::NameUnique() {
}

NameUnique::~NameUnique() {
}

NameUnique::NameUnique(const NameUnique& obj) : Object() {
	word = obj.word;
	root = obj.root;
	type = obj.type;
}

NameUnique::NameUnique(String uWord, String uRoot, String uType) : Object() {
	word = uWord;
	root = uRoot;
	type = uType;
}

String NameUnique::getWord() {
	return word;
}

String NameUnique::getRoot() {
	return root;
}

String NameUnique::getType() {
	return type;
}