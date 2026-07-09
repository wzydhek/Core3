/*
 * TreeDataBlock.h
 *
 *  Created on: Apr 6, 2011
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"

namespace zlib {
	#include <zlib.h>
}

namespace tre3 {
class TreeDataBlock {
	uint32 compressionType;

	unsigned long compressedSize;
	unsigned long uncompressedSize;

	//md5sum

public:
	const static int SIZE = 6 * sizeof(int);

public:
	TreeDataBlock();

	TreeDataBlock(const TreeDataBlock& tdb);

	TreeDataBlock& operator=(const TreeDataBlock& tdb);

	void read(FileInputStream* fileStream, int offset);

	/**
	 * Uncompresses a block of data and returns it in a byte buffer.
	 * @param fileStream FileInputStream that has been advanced to the position of the compressedData and will be read for the compressedSize
	 */
	byte* uncompress(FileInputStream* fileStream);

	void compress();

	void setCompressionType(uint32 value);

	void setCompressedSize(uint32 value);

	void setUncompressedSize(uint32 value);

	uint32 getCompressedSize() const;

	uint32 getUncompressedSize() const;
};
} // namespace tre3

using namespace tre3;