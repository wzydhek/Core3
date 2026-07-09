/*
 * Mfrc.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"
#include "Random.h"
#include "PerlinNoise.h"

class MapFractal : public TemplateVariable<'MFRC'> {
	PerlinNoise* noise;
	trn::ptat::Random* rand;

	int bias;
	float biasValue;
	int gainType;
	float gainValue;
	int octaves;
	float octavesParam;
	float amplitude;
	float xFrequency;
	float yFrequency;
	float xOffset;
	float zOffset;
	int combination;

	bool unkown;

	static double log05;

	float offset32;

public:
	MapFractal();

	~MapFractal();

	void parseFromIffStream(engine::util::IffStream* iffStream);
	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);

	float getNoise(float x, float y, int i = 0, int  j = 0);
	float getNoise(float x, int i = 0, int j = 0);

	double calculateCombination1(float v39);
	double calculateCombination1(float xfreq, float yfreq);
	double calculateCombination2(float xfreq, float yfreq);
	double calculateCombination3(float xfreq, float yfreq);
	double calculateCombination4(float xfreq, float yfreq);
	double calculateCombination5(float xfreq, float yfreq);

	void setSeed(int seed);

	void setBias(int bias);

	void setBiasValue(float value);

	void setGainType(int type);

	void setGainValue(float val);

	void setOctaves(int octaves);

	void setOctavesParam(float param);

	void setAmplitude(float ampl);

	void setXFreq(float xfreq);

	void setYFreq(float yfreq);

	void setZOffset(float offset);

	void setXOffset(float offset);

	void setCombination(int comb);
};
