/*
 * TreeArchive.h
 *
 *  Created on: Apr 7, 2011
 *      Author: crush
 */

#pragma once

#include "TreeFile.h"
#include "TreeDirectory.h"

namespace tre3 {
class TreeArchive : public Logger {
	HashTable<String, Reference<TreeDirectory*>> nodeMap;

public:
	TreeArchive();

	void unpackFile(const String& file);

	void addRecord(const String& path, TreeFileRecord* record);

	const TreeDirectory* getTreeDirectory(const String& path) const;

	/**
	 * Gets a byte buffer from the specified path.
	 * Don't forget to delete the pointer when finished.
	 */
	byte* getBytes(const String& recordPath, int& size) const;

	const TreeDirectory* getDirectory(const String& path) const;

	Vector<String>* getFilesAndSubDirectoryFiles(const String& directory) const;
};
} // namespace tre3

using namespace tre3;