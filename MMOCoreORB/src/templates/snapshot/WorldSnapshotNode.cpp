#include "WorldSnapshotNode.h"

WorldSnapshotNode::WorldSnapshotNode() : Object(), objectID(0), parentID(0), nameID(0), cellid(0), gameObjectType(0), unknown2(0) {
}

WorldSnapshotNode::WorldSnapshotNode(const WorldSnapshotNode& wsn) : Object() {
	childNodes = wsn.childNodes;
	objectID = wsn.objectID;
	parentID = wsn.parentID;
	nameID = wsn.nameID;
	cellid = wsn.cellid;
	direction = wsn.direction;
	position = wsn.position;
	gameObjectType = wsn.gameObjectType;
	unknown2 = wsn.unknown2;
}

WorldSnapshotNode& WorldSnapshotNode::operator=(const WorldSnapshotNode& wsn) {
	if (this == &wsn)
		return *this;

	childNodes = wsn.childNodes;
	objectID = wsn.objectID;
	parentID = wsn.parentID;
	nameID = wsn.nameID;
	cellid = wsn.cellid;
	direction = wsn.direction;
	position = wsn.position;
	gameObjectType = wsn.gameObjectType;
	unknown2 = wsn.unknown2;

	return *this;
}

void WorldSnapshotNode::parse(IffStream* iffStream) {
	iffStream->openForm('NODE');

	uint32 version = iffStream->getNextFormType();
	Chunk* versionForm = iffStream->openForm(version);

	switch (version) {
		case '0000': {
			Chunk* data = iffStream->openChunk('DATA');
			objectID = data->readInt();
			parentID = data->readInt();
			nameID = data->readInt();
			cellid = data->readInt();

			float qw = data->readFloat();
			float qx = data->readFloat();
			float qy = data->readFloat();
			float qz = data->readFloat();

			float x = data->readFloat();
			float z = data->readFloat();
			float y = data->readFloat();

			direction.set(qw, qx, qy, qz);
			position.set(x, z, y);

			gameObjectType = data->readFloat();
			unknown2 = data->readInt();

			iffStream->closeChunk('DATA');
		} break;
		default:
			break;
	}

	for (int i = 0; i < versionForm->getChunksSize() - 1; ++i) {
		WorldSnapshotNode childNode;
		childNode.parse(iffStream);

		childNodes.add(childNode);
	}

	iffStream->closeForm(version);
	iffStream->closeForm('NODE');
}

Quaternion WorldSnapshotNode::getDirection() const {
	return direction;
}

float WorldSnapshotNode::getGameObjectType() const {
	return gameObjectType;
}

uint32 WorldSnapshotNode::getNameID() const {
	return nameID;
}

uint32 WorldSnapshotNode::getObjectID() const {
	return objectID;
}

uint32 WorldSnapshotNode::getParentID() const {
	return parentID;
}

Vector3 WorldSnapshotNode::getPosition() const {
	return position;
}

uint32 WorldSnapshotNode::getCellID() const {
	return cellid;
}

uint32 WorldSnapshotNode::getUnknown2() const {
	return unknown2;
}

int WorldSnapshotNode::getNodeCount() {
	return childNodes.size();
}

WorldSnapshotNode* WorldSnapshotNode::getNode(int idx) {
	return &childNodes.get(idx);
}