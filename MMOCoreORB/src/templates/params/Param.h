/*
 * Param.h
 *
 *  Created on: 23-feb-2009
 *      Author: TheAnswer
 */

#pragma once

#include "system/lang.h"
#include "engine/util/iffstream/IffStream.h"

class Param {
	uint32 type;

public:
	const static uint32 BOOL = 0x01;
	const static uint32 FLOAT = 0x02;
	const static uint32 INTEGER = 0x04;
	const static uint32 STRING = 0x08;
	const static uint32 STRINGID = 0x10;
	const static uint32 VECTOR = 0x12;
	const static uint32 DYNAMICVARIABLE = 0x014;
	const static uint32 TRIGGERVOLUME = 0x16;
	const static uint32 PALETTECOLORCUSTOMIZATION = 0x18;
	const static uint32 RANGEDINTCUSTOMIZATIONVARIABLE = 0x20;
	const static uint32 CUSTOMIZATIONVARIABLEMAP = 0x22;
public:
	Param();

	virtual ~Param();

	virtual bool parse(engine::util::Chunk* source) = 0;

	virtual String toString() const = 0;

	uint32 getType() const;

	void setType(uint32 tp);

	bool isBool() const;

	bool isFloat() const;

	bool isInteger() const;

	bool isString() const;

	bool isStringId() const;
};
