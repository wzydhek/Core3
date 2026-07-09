#include "PathEdge.h"

PathEdge::PathEdge() : from(0), to(0), laneWidthRight(0), laneWidthLeft(0) {
}

void PathEdge::readObject(IffStream* iffStream) {
	from = iffStream->getInt();
	to = iffStream->getInt();
	laneWidthRight = iffStream->getFloat();
	laneWidthLeft = iffStream->getFloat();
}

int PathEdge::getFromConnection() const {
	return from;
}

int PathEdge::getToConnection() const {
	return to;
}

float PathEdge::getLaneWidthRight() const {
	return laneWidthRight;
}

float PathEdge::getLaneWidthLeft() const {
	return laneWidthLeft;
}

bool PathEdge::toBinaryStream(ObjectOutputStream* stream) {
	return false;
}

bool PathEdge::parseFromBinaryStream(ObjectInputStream* stream) {
	return false;
}