/*
 * MapGroup.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "MapFractal.h"
#include "MapFamily.h"

class MapGroup : public TemplateVariable<'MGRP'> {
	Vector<MapFamily*> mfams;
	VectorMap<uint32, MapFractal*> mfrcs;

public:

	MapGroup();

	~MapGroup();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);

	MapFractal* getMfrc(int index);

	const MapFractal* getMfrc(int index) const;


};
