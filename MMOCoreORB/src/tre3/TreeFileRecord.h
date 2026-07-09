/*
 * TreeFileRecord.h
 *
 *  Created on: Apr 6, 2011
 *      Author: crush
 */

#pragma once

#include "TreeDataBlock.h"

namespace tre3 {
class TreeFileRecord : public Object, public Logger {
	String recordName;
	String treeFilePath;

	uint32 checksum;
	uint32 uncompressedSize;
	uint32 fileOffset;
	uint32 compressionType;
	uint32 compressedSize;
	uint32 nameOffset;

	byte md5Sum[16];

public:
	TreeFileRecord();

	TreeFileRecord(const TreeFileRecord& tfr);

	TreeFileRecord& operator=(const TreeFileRecord& tfr);

	int compareTo(const TreeFileRecord& tfr) const;

	int compareTo(const String& fileName) const;

	void read(FileInputStream* fileStream);

	uint32 readFromBuffer(const byte* buffer);

	byte* getBytes();

	String toString() const;

	void setMD5Sum(byte sum[16]);

	uint32 getNameOffset() const;

	uint32 getCompressionType() const;

	uint32 getUncompressedSize() const;

	void setRecordName(const String& name);

	const String& getRecordName() const;

	void setTreeFilePath(const String& path);
};
} // namespace tre3

using namespace tre3;