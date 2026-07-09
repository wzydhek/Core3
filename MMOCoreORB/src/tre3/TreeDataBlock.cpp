#include "TreeDataBlock.h"

TreeDataBlock::TreeDataBlock() {
	compressionType = 0;
	compressedSize = 0;
	uncompressedSize = 0;
}

TreeDataBlock::TreeDataBlock(const TreeDataBlock& tdb) {
	compressionType = tdb.compressionType;
	compressedSize = tdb.compressedSize;
	uncompressedSize = tdb.uncompressedSize;
}

TreeDataBlock& TreeDataBlock::operator=(const TreeDataBlock& tdb) {
	if (this == &tdb)
		return *this;

	compressionType = tdb.compressionType;
	compressedSize = tdb.compressedSize;
	uncompressedSize = tdb.uncompressedSize;

	return *this;
}

void TreeDataBlock::read(FileInputStream* fileStream, int offset) {
}

/**
 * Uncompresses a block of data and returns it in a byte buffer.
 * @param fileStream FileInputStream that has been advanced to the position of the compressedData and will be read for the compressedSize
 */
byte* TreeDataBlock::uncompress(FileInputStream* fileStream) {
	byte* uncompressedData = new byte[uncompressedSize];

	switch (compressionType) {
		case 2: // Data is compressed
		{
			byte* compressedData = new byte[compressedSize];

			fileStream->read(compressedData, compressedSize);

			int result = zlib::uncompress(uncompressedData, &uncompressedSize, compressedData, compressedSize);

			delete[] compressedData;
		} break;
		case 0: // Data is uncompressed
		default:
			fileStream->read(uncompressedData, uncompressedSize);
			break;
	}

	return uncompressedData;
}

void TreeDataBlock::compress() {
}

void TreeDataBlock::setCompressionType(uint32 value) {
	compressionType = value;
}

void TreeDataBlock::setCompressedSize(uint32 value) {
	compressedSize = value;
}

void TreeDataBlock::setUncompressedSize(uint32 value) {
	uncompressedSize = value;
}

uint32 TreeDataBlock::getCompressedSize() const {
	return compressedSize;
}

uint32 TreeDataBlock::getUncompressedSize() const {
	return uncompressedSize;
}