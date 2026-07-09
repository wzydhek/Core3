/*
 * TreeFile.h
 *
 *  Created on: Apr 5, 2011
 *      Author: crush
 */

#pragma once

#include "TreeFileRecord.h"
#include "TreeDataBlock.h"

namespace tre3 {
class TreeArchive;

class TreeFile : public Logger {
	TreeArchive* treeArchive;

	String filePath;
	int version;
	int totalRecords;
	int dataOffset;

	TreeDataBlock fileBlock;
	TreeDataBlock nameBlock;

	Vector<Reference<TreeFileRecord*> > records;

	void readHeader(FileInputStream* fileStream);
	void readFileBlock(FileInputStream* fileStream);
	void readNameBlock(FileInputStream* fileStream);
	void readMD5Sums(FileInputStream* fileStream);

public:
	TreeFile(TreeArchive* archive);
	~TreeFile();

	void read(const String& path);
};
} // namespace tre3

using namespace tre3;