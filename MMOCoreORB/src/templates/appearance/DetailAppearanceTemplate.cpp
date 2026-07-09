
/*
 * DetailAppearanceTemplate.cpp
 *
 *  Created on: 10/12/2010
 *      Author: victor
 */

#include "DetailAppearanceTemplate.h"
#include "templates/manager/TemplateManager.h"

DetailAppearanceTemplate::DetailAppearanceTemplate() {
	firstMesh = nullptr;
}

DetailAppearanceTemplate::~DetailAppearanceTemplate() {
}

uint32 DetailAppearanceTemplate::getType() const {
	return 'DTAL';
}

void DetailAppearanceTemplate::readObject(IffStream* templateData) {
	parse(templateData);
}

void DetailAppearanceTemplate::parse(IffStream* iffStream) {
	iffStream->openForm('DTLA');

	uint32 version = iffStream->getNextFormType();
	iffStream->openForm(version);

	AppearanceTemplate::readObject(iffStream);

	//if (iffStream->getNextFormType() == 'PIVT') {

	if (version != '0005') {
		iffStream->openChunk('PIVT');
		iffStream->closeChunk('PIVT');
	}
	//}

	Chunk* infoChunk = iffStream->openChunk('INFO');
	
	iffStream->closeChunk('INFO');

	Chunk* dataChunk = iffStream->openForm('DATA');

	int subChunks = dataChunk->getChunksSize();

	//loading last child only
	for (int i = 0; i < subChunks; ++i) {
		iffStream->openChunk('CHLD');

		int var1 = iffStream->getInt();

		String meshFile;
		iffStream->getString(meshFile);

		if (i == subChunks - 1) {
			AppearanceTemplate* templ = TemplateManager::instance()->getAppearanceTemplate("appearance/" + meshFile);
			firstMesh = templ;
		}

		iffStream->closeChunk('CHLD');
	}

	iffStream->closeForm('DATA');

	iffStream->closeForm(version);
	iffStream->closeForm('DTLA');
}

bool DetailAppearanceTemplate::testCollide(const Sphere& testsphere) const {
	return firstMesh->testCollide(testsphere);
}

/**
 * Checks for intersection against ray, stops on any intersection
 * @return intersectionDistance, triangle which it intersects
 */
bool DetailAppearanceTemplate::intersects(const Ray& ray, float distance, float& intersectionDistance, Triangle*& triangle, bool checkPrimitives) const {
	return firstMesh->intersects(ray, distance, intersectionDistance, triangle, checkPrimitives);
}

/**
 * Checks for all intersections
 */
int DetailAppearanceTemplate::intersects(const Ray& ray, float maxDistance, SortedVector<IntersectionResult>& result) const {
	return firstMesh->intersects(ray, maxDistance, result);
}

Vector<Reference<MeshData*>> DetailAppearanceTemplate::getTransformedMeshData(const Matrix4& parentTransform) const {
	Vector<Reference<MeshData*>> meshes;
	if (firstMesh != nullptr)
		meshes.addAll(firstMesh->getTransformedMeshData(parentTransform));
	return meshes;
}