/*
 * DataTableCell.cpp
 *
 *  Created on: Apr 21, 2011
 *      Author: crush
 */

#include "templates/datatables/DataTableCell.h"

DataTableCell::DataTableCell() {
}

DataTableCell::~DataTableCell() {
}

void DataTableCell::getValue(Vector<String>& out) const {
	throw Exception(String("No valid type specified. Correct type is ").concat((char)getType()));
}

void DataTableCell::getValue(SortedVector<String>& out) const {
	throw Exception(String("No valid type specified. Correct type is ").concat((char)getType()));
}

void DataTableCell::getValue(String& out) const {
	throw Exception(String("No valid type specified. Correct type is ").concat((char)getType()));
}

void DataTableCell::getValue(int& out) const {
	throw Exception(String("No valid type specified. Correct type is ").concat((char)getType()));
}

void DataTableCell::getValue(uint32& out) const {
	throw Exception(String("No valid type specified. Correct type is ").concat((char)getType()));
}

void DataTableCell::getValue(float& out) const {
	throw Exception(String("No valid type specified. Correct type is ").concat((char)getType()));
}

void DataTableCell::getValue(bool& out) const {
	throw Exception(String("No valid type specified. Correct type is ").concat((char)getType()));
}

DataTableCellString::DataTableCellString() {
}

/**
 * Parses the string as a comma delimited vector into a SortedVector of Strings.
 */
void DataTableCellString::getValue(SortedVector<String>& out) const {
	String tokenizedString;
	getValue(tokenizedString);

	StringTokenizer tokenizer(tokenizedString);
	tokenizer.setDelimeter(",");

	while (tokenizer.hasMoreTokens()) {
		String token;
		tokenizer.getStringToken(token);

		out.put(token);
	}
}

void DataTableCellString::getValue(Vector<String>& out) const {
	String tokenizedString;
	getValue(tokenizedString);

	StringTokenizer tokenizer(tokenizedString);
	tokenizer.setDelimeter(",");

	while (tokenizer.hasMoreTokens()) {
		String token;
		tokenizer.getStringToken(token);

		out.add(token);
	}
}

void DataTableCellString::parse(Chunk* chunk) {
	chunk->readString(value);
}

void DataTableCellString::getValue(String& out) const {
	out = value;
}

byte DataTableCellString::getType() const {
	return 's';
}

String DataTableCellString::toString() const {
	return value;
}

DataTableCellInt::DataTableCellInt() {
	value = 0;
}

void DataTableCellInt::parse(Chunk* chunk) {
	value = chunk->readSignedInt();
}

void DataTableCellInt::getValue(int& out) const {
	out = value;
}

byte DataTableCellInt::getType() const {
	return 'i';
}

String DataTableCellInt::toString() const {
	return String::valueOf(value);
}

DataTableCellHex::DataTableCellHex() {
	value = 0;
}

void DataTableCellHex::parse(Chunk* chunk) {
	value = chunk->readInt();
}

void DataTableCellHex::getValue(uint32& out) const {
	out = value;
}

byte DataTableCellHex::getType() const {
	return 'h';
}

String DataTableCellHex::toString() const {
	return String::valueOf(value);
}

DataTableCellFloat::DataTableCellFloat() {
	value = 0.f;
}

void DataTableCellFloat::parse(Chunk* chunk) {
	value = chunk->readFloat();
}

void DataTableCellFloat::getValue(float& out) const {
	out = value;
}

byte DataTableCellFloat::getType() const {
	return 'f';
}

String DataTableCellFloat::toString() const {
	return String::valueOf(value);
}

DataTableCellBinary::DataTableCellBinary() {
	value = false;
}

void DataTableCellBinary::parse(Chunk* chunk) {
	value = (bool)chunk->readInt();
}

void DataTableCellBinary::getValue(bool& out) const {
	out = value;
}

byte DataTableCellBinary::getType() const {
	return 'b';
}

String DataTableCellBinary::toString() const {
	return String::valueOf(value);
}