#include "TreeFileRecord.h"

TreeFileRecord::TreeFileRecord() : Object(), Logger(), checksum(0), uncompressedSize(0), fileOffset(0), compressionType(0), compressedSize(0), nameOffset(0) {
	setLoggingName("TreeFileRecord");
	setLogging(false);

	memset(md5Sum, 0, 16);
}

TreeFileRecord::TreeFileRecord(const TreeFileRecord& tfr) : Object(), Logger() {
	recordName = tfr.recordName;
	treeFilePath = tfr.treeFilePath;
	checksum = tfr.checksum;
	uncompressedSize = tfr.uncompressedSize;
	fileOffset = tfr.fileOffset;
	compressionType = tfr.compressionType;
	compressedSize = tfr.compressedSize;
	nameOffset = tfr.nameOffset;
	memcpy(md5Sum, tfr.md5Sum, 16);

	setLoggingName("TreeFileRecord " + recordName);
	setLogging(false);
}

TreeFileRecord& TreeFileRecord::operator=(const TreeFileRecord& tfr) {
	if (this == &tfr)
		return *this;

	recordName = tfr.recordName;
	treeFilePath = tfr.treeFilePath;
	checksum = tfr.checksum;
	uncompressedSize = tfr.uncompressedSize;
	fileOffset = tfr.fileOffset;
	compressionType = tfr.compressionType;
	compressedSize = tfr.compressedSize;
	nameOffset = tfr.nameOffset;
	memcpy(md5Sum, tfr.md5Sum, 16);

	setLoggingName("TreeFileRecord " + recordName);

	return *this;
}

int TreeFileRecord::compareTo(const TreeFileRecord& tfr) const {
	return recordName.compareTo(tfr.recordName);
}

int TreeFileRecord::compareTo(const String& fileName) const {
	return recordName.compareTo(fileName);
}

void TreeFileRecord::read(FileInputStream* fileStream) {
	fileStream->read((byte*)&checksum, 4);
	fileStream->read((byte*)&uncompressedSize, 4);
	fileStream->read((byte*)&fileOffset, 4);
	fileStream->read((byte*)&compressionType, 4);
	fileStream->read((byte*)&compressedSize, 4);
	fileStream->read((byte*)&nameOffset, 4);
}

uint32 TreeFileRecord::readFromBuffer(const byte* buffer) {
	uint32 bufferOffset = 0;

	checksum = *(uint32*)(buffer + bufferOffset);
	bufferOffset += sizeof(checksum);

	uncompressedSize = *(uint32*)(buffer + bufferOffset);
	bufferOffset += sizeof(uncompressedSize);

	fileOffset = *(uint32*)(buffer + bufferOffset);
	bufferOffset += sizeof(fileOffset);

	compressionType = *(uint32*)(buffer + bufferOffset);
	bufferOffset += sizeof(compressionType);

	compressedSize = *(uint32*)(buffer + bufferOffset);
	bufferOffset += sizeof(compressedSize);

	nameOffset = *(uint32*)(buffer + bufferOffset);
	bufferOffset += sizeof(nameOffset);

	return bufferOffset;
}

byte* TreeFileRecord::getBytes() {
	File file(treeFilePath);
	FileInputStream fileStream(&file);

	if (!file.exists()) {
		error("Tree File does not exist: " + treeFilePath);
		return nullptr;
	}

	fileStream.skip(fileOffset);

	TreeDataBlock db;
	db.setCompressedSize(compressedSize);
	db.setUncompressedSize(uncompressedSize);
	db.setCompressionType(compressionType);

	byte* buffer = db.uncompress(&fileStream);

	fileStream.close();

	return buffer;
}

String TreeFileRecord::toString() const {
	StringBuffer str;
	str << "Checksum: " << checksum;
	str << " UncompressedSize: " << uncompressedSize;
	str << " FileOffset: " << fileOffset;
	str << " CompressionType: " << compressionType;
	str << " FileSize: " << compressedSize;
	str << " NameOffset: " << nameOffset;

	return str.toString();
}

void TreeFileRecord::setMD5Sum(byte sum[16]) {
	memcpy(&md5Sum, sum, 16);
}

uint32 TreeFileRecord::getNameOffset() const {
	return nameOffset;
}

uint32 TreeFileRecord::getCompressionType() const {
	return compressionType;
}

uint32 TreeFileRecord::getUncompressedSize() const {
	return uncompressedSize;
}

void TreeFileRecord::setRecordName(const String& name) {
	recordName = name;
}

const String& TreeFileRecord::getRecordName() const {
	return recordName;
}

void TreeFileRecord::setTreeFilePath(const String& path) {
	treeFilePath = path;
}