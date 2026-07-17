/*
 * TargaBitmap.h
 *
 *  Created on: 06/09/2013
 *      Author: victor
 */

#pragma once

namespace terrain {

class TargaHeader {
public:
	char  idlength;
	char  colourmaptype;
	char  datatypecode;
	short int colourmaporigin;
	short int colourmaplength;
	char  colourmapdepth;
	short int x_origin;
	short int y_origin;
	short width;
	short height;
	char  bitsperpixel;
	char  imagedescriptor;

	TargaHeader();

	void readData(ObjectInputStream* fileReader);

};

class TargaPixel {
public:
	TargaPixel() {

	}

	virtual ~TargaPixel() {

	}

	virtual void read(ObjectInputStream* data, int bytes) = 0;
	virtual void clear() = 0;
};

class TargaBitmap {
protected:
	TargaHeader header;
	TargaPixel** pixelData;

public:
	TargaBitmap();

	~TargaBitmap();

	void readObject(ObjectInputStream* stream);

	int getWidth() const;

	int getHeight() const;

	unsigned char getData(int offset) const;
};

} // namespace terrain

using namespace terrain;
