/*
 * BitmapGroup.h
 *
 *  Created on: 06/09/2013
 *      Author: victor
 */

#pragma once

#include "BitmapFamily.h"
#include "TargaBitmap.h"

namespace terrain {

class BitmapGroup : public TemplateVariable<'MGRP'> {
	Vector<BitMapFamily*> mfams;
	VectorMap<uint32, TargaBitmap*> mfrcs;

public:
	BitmapGroup();

	~BitmapGroup();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);

	TargaBitmap* getBitmap(int index);

};

} // namespace terrain

using namespace terrain;