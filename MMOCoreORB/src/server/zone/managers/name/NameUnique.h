#pragma once

class NameUnique : public Object {

protected:
	String word, root, type;

public:
	NameUnique() {
	}

	~NameUnique() {
	}

	NameUnique(const NameUnique& obj) : Object() {
		word = obj.word;
		root = obj.root;
		type = obj.type;
	}

	NameUnique(String uWord, String uRoot, String uType) : Object() {
		word = uWord;
		root = uRoot;
		type = uType;
	}

	String getWord() {
		return word;
	}

	String getRoot() {
		return root;
	}

	String getType() {
		return type;
	}
};
