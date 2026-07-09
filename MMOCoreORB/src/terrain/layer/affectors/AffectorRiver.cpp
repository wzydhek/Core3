#include "AffectorRiver.h"

Point2D::Point2D() : x(0), y(0) {
}

Point2D::Point2D(float xPos, float yPos) {
	x = xPos;
	y = yPos;
}

float Point2D::getX() const {
	return x;
}

float Point2D::getY() const {
	return y;
}

AffectorRiver::AffectorRiver() : var1(0), var2(0), var3(0), var4(0), var5(0), var6(0), var7(0), var8(0), var9(0), var10(0), var11(0), var12(0) {
}

AffectorRiver::~AffectorRiver() {
	for (int i = 0; i < positions.size(); ++i)
		delete positions.get(i);
}

void AffectorRiver::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0005':
			parseFromIffStream(iffStream, Version<'0005'>());
			break;
		default:
			System::out << "unknown AffectorRiver version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorRiver::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0005'>) {
	informationHeader.readObject(iffStream);

	iffStream->openForm('DATA');

	uint32 type = iffStream->getNextFormType();

	switch (type) {
		case ('ROAD'):
			road.readObject(iffStream);
			break;
		case ('HDTA'):
			hdta.readObject(iffStream);
			break;
		default:
			System::out << "Unknown type in AffectorRiver, expecting ROAD or HDTA!\n";
			break;
	}

	iffStream->openChunk('DATA');

	var1 = iffStream->getInt();

	for (int i = 0; i < var1; i++) {
		Point2D* pos = new Point2D();
		pos->x = iffStream->getFloat();
		pos->y = iffStream->getFloat();

		positions.add(pos);
	}

	var2 = iffStream->getFloat();
	var3 = iffStream->getInt();
	var4 = iffStream->getInt();
	var5 = iffStream->getInt();
	var6 = iffStream->getFloat();
	var7 = iffStream->getFloat();
	var8 = iffStream->getFloat();
	var9 = iffStream->getInt();
	var10 = iffStream->getFloat();
	var11 = iffStream->getFloat();
	var12 = iffStream->getFloat();

	iffStream->getString(var15);

	iffStream->closeChunk('DATA');

	iffStream->closeForm('DATA');
}