/*
 * DataTableCell.h
 *
 *  Created on: Feb 11, 2011
 *      Author: crush
 */

#pragma once

#include "system/lang.h"
#include "engine/util/iffstream/chunks/Chunk.h"

namespace templates {
namespace datatables {

class DataTableCell {
public:
	DataTableCell();

	virtual ~DataTableCell();

	virtual void parse(Chunk* chunk) = 0;

	/*template<typename V>
	void getValue(V& out) {
		throw Exception("No valid type specified.");
	}*/

	virtual void getValue(Vector<String>& out) const;

	virtual void getValue(SortedVector<String>& out) const;

	virtual void getValue(String& out) const;

	virtual void getValue(int& out) const;

	virtual void getValue(uint32& out) const;

	virtual void getValue(float& out) const;

	virtual void getValue(bool& out) const;


	virtual byte getType() const = 0;

	virtual String toString() const = 0;
};

class DataTableCellString : public DataTableCell {
	String value;

public:
	DataTableCellString();

	void getValue(SortedVector<String>& out) const;
	void getValue(Vector<String>& out) const;

	void parse(Chunk* chunk);

	void getValue(String& out) const;

	byte getType() const;

	String toString() const;
};

class DataTableCellInt : public DataTableCell {
	int value;

public:
	DataTableCellInt();

	void parse(Chunk* chunk);

	void getValue(int& out) const;

	byte getType() const;

	String toString() const;
};

class DataTableCellHex : public DataTableCell {
	uint32 value;

public:
	DataTableCellHex();

	void parse(Chunk* chunk);

	void getValue(uint32& out) const;

	byte getType() const;

	String toString() const;
};

class DataTableCellFloat : public DataTableCell {
	float value;

public:
	DataTableCellFloat();

	void parse(Chunk* chunk);

	void getValue(float& out) const;

	byte getType() const;

	String toString() const;
};

class DataTableCellBinary : public DataTableCell {
	bool value;

public:
	DataTableCellBinary();

	void parse(Chunk* chunk);

	void getValue(bool& out) const;

	byte getType() const;

	String toString() const;
};

} // namespace datatables
} // namespace templates

using namespace templates::datatables;
