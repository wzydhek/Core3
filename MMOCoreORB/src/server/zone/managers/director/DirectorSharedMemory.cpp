#include "DirectorSharedMemory.h"

uint64 DirectorSharedMemory::get(const String& k) const {
	return hashTable.get(k);
}

const String& DirectorSharedMemory::getString(const String& k) const {
	return stringTable.get(k);
}

Vector3 DirectorSharedMemory::getVector3(const String& k) const {
	return vector3Table.get(k);
}

Vector<String> DirectorSharedMemory::getStringVector(const String& k) const {
	return stringVectorTable.get(k);
}

void DirectorSharedMemory::put(const String& k, uint64 v) {
	hashTable.put(k, v);
}

void DirectorSharedMemory::putString(const String& k, const String& v) {
	stringTable.put(k, v);
}

void DirectorSharedMemory::putVector3(const String& k, const Vector3& v) {
	vector3Table.put(k, v);
}

void DirectorSharedMemory::putStringVector(const String& k, const Vector<String>& v) {
	stringVectorTable.put(k, v);
}

void DirectorSharedMemory::remove(const String& k) {
	hashTable.remove(k);
}

void DirectorSharedMemory::removeString(const String& k) {
	stringTable.remove(k);
}

void DirectorSharedMemory::removeVector3(const String& k) {
	vector3Table.remove(k);
}

void DirectorSharedMemory::removeStringVector(const String& k) {
	stringVectorTable.remove(k);
}

void DirectorSharedMemory::setNullValue(uint64 o) {
	hashTable.setNullValue(o);
}

Object* DirectorSharedMemory::clone() {
	return ObjectCloner<DirectorSharedMemory>::clone(this);
}

Object* DirectorSharedMemory::clone(void* object) {
	return TransactionalObjectCloner<DirectorSharedMemory>::clone(this);
}