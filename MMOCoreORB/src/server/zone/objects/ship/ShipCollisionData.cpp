#include "server/zone/objects/ship/ShipCollisionData.h"
#include "templates/manager/DataArchiveStore.h"

ShipCollisionData::ShipCollisionData(SharedShipObjectTemplate* shipTemplate, const ShipChassisData* chassisData) : Object() {
	setLoggingName("ShipCollisionData " + chassisData->getName());

	hardpointMap.setNoDuplicateInsertPlan();
	slotWeights.setNoDuplicateInsertPlan();
	slotWeights.setNullValue(0);
	volumeType = INVALID;

	setCollisionData(shipTemplate);
	setClientData(shipTemplate);
	setComponentData(shipTemplate, chassisData);
	setSlotWeights(shipTemplate, chassisData);

	for (int i = 0; i < hardpointMap.size(); ++i) {
		hardpointSize += hardpointMap.elementAt(i).getValue().size();
	}
}

void ShipCollisionData::setCollisionData(SharedShipObjectTemplate* templateData) {
	appearance = templateData->getAppearanceTemplate();

	if (appearance == nullptr || templateData->getAppearanceFilename() == "") {
		auto portalLayout = templateData->getPortalLayout();

		if (portalLayout != nullptr && portalLayout->getAppearanceTemplatesSize() > 0) {
			appearance = portalLayout->getAppearanceTemplate(0);
		}
	}

	if (appearance == nullptr) {
		return;
	}

	auto boundingVolume = appearance->getBoundingVolume();

	if (boundingVolume == nullptr) {
		return;
	}

	auto collisionVolume = appearance->getCollisionVolume();

	if (collisionVolume == nullptr) {
		collisionVolume = boundingVolume;
	}

	boundingSphere = getChassisBoundingSphere(boundingVolume);
	chassisSphere = collisionVolume->getBoundingSphere();
	chassisBox = collisionVolume->getBoundingBox();
	volumeType = getBoundingVolumeType(collisionVolume);
}

void ShipCollisionData::setClientData(SharedShipObjectTemplate* shipTemplate) {
	auto clientDataPath = shipTemplate->getClientDataFile();

	if (clientDataPath == "") {
		return;
	}

	IffStream* iffStream = DataArchiveStore::instance()->openIffFile(clientDataPath.toLowerCase());

	if (iffStream == nullptr || iffStream->getNextFormType() != 'CLDF') {
		return;
	}

	try {

	iffStream->openForm('CLDF');

	if (iffStream->getNextFormType() == '0000') {
		iffStream->openForm('0000');

		for (int i = 0; i < iffStream->getSubChunksNumber(); ++i) {
			auto chunk = iffStream->openChunk();
			if (chunk == nullptr) {
				break;
			}

			uint32 chunkID = chunk->getChunkID();

			if (chunkID == 'HOBJ') {
				String attachmentName = chunk->readString();
				String hardpointName = chunk->readString();

				addCollisionHardpoint(shipTemplate, "chassis", attachmentName, hardpointName, Components::CHASSIS, 1.f);
			}

			iffStream->closeChunk();
		}

		iffStream->closeForm('0000');
	}

	} catch (Exception& e) {
		error() << e.what();
		e.printStackTrace();
	}

	iffStream->closeForm('CLDF');
	delete iffStream;
}

void ShipCollisionData::setComponentData(SharedShipObjectTemplate* templateData, const ShipChassisData* chassisData) {
	auto appearance = templateData->getAppearanceTemplate();

	if (appearance == nullptr) {
		return;
	}

	const auto& hardpointTransforms = appearance->getHardpoints();

	if (hardpointTransforms.size() == 0) {
		return;
	}

	for (uint32 slot = 0; slot <= Components::CAPITALSLOTMAX; ++slot) {
		auto slotData = chassisData->getComponentSlotData(slot);

		if (slotData == nullptr) {
			continue;
		}

		const auto& compData = slotData->getComponentHardpoints();

		for (int i = 0; i < compData.size(); ++i) {
			const auto& componentName = compData.elementAt(i).getKey();
			const auto& componentEntry = compData.elementAt(i).getValue();

			for (int ii = 0; ii < componentEntry.size(); ++ii) {
				auto componentHardpoint = componentEntry.get(ii);

				if (componentHardpoint == nullptr) {
					continue;
				}

				const auto& attachmentName = componentHardpoint->getTemplateName();
				const auto& hardpointName = componentHardpoint->getHardpointName();
				float hardpointRadius = componentHardpoint->getRange();

				String attachmentFileName = "";

				if (attachmentName != "") {
					String attachmentPath = getAttachmentTemplatePath(attachmentName, slot);
					auto attachmentTemplate = TemplateManager::instance()->getTemplate(attachmentPath.hashCode());

					if (attachmentTemplate != nullptr) {
						attachmentFileName = attachmentTemplate->getAppearanceFilename();
					}
				}

				if (attachmentFileName != "") {
					addCollisionHardpoint(templateData, componentName, attachmentFileName, hardpointName, slot, hardpointRadius);
				} else if (hardpointRadius > 0.f){
					addCollisionHardpoint(templateData, componentName, hardpointName, slot, hardpointRadius);
				}
			}
		}
	}
}

void ShipCollisionData::setSlotWeights(SharedShipObjectTemplate* templateData, const ShipChassisData* chassisData) {
	for (uint32 slot = 0; slot <= Components::CAPITALSLOTMAX; ++slot) {
		auto slotData = chassisData->getComponentSlotData(slot);

		if (slotData == nullptr) {
			continue;
		}

		int slotWeight = slotData->getHitWeight();

		if (slotData->getHitWeight() != 0) {
			slotWeights.put(slot, slotWeight);
		}
	}
}

void ShipCollisionData::addCollisionHardpoint(SharedShipObjectTemplate* shipTemplate, const String& componentName, const String& hardpointName, int slot, float radius) {
	auto shipAppearance = shipTemplate->getAppearanceTemplate();

	if (shipAppearance == nullptr || hardpointName == "") {
		return;
	}

	const auto& hardpointTransforms = shipAppearance->getHardpoints();

	Matrix4 hardpointRotation = hardpointTransforms.get(hardpointName);
	Vector3 hardpointPosition = Vector3(hardpointRotation[3][0], hardpointRotation[3][1], hardpointRotation[3][2]);
	hardpointRotation.setTranslation(0,0,0);

	Sphere hardpointSphere = getHardpointBoundingSphere(Sphere(Vector3::ZERO, radius), hardpointPosition, hardpointRotation);
	const auto& slotName = Components::shipComponentSlotToString(slot);

	if (!hardpointMap.contains(slotName)) {
		auto hardPoints = VectorMap<uint32, ShipCollisionHardpoint>();
		hardPoints.setAllowDuplicateInsertPlan();
		hardpointMap.put(slotName, std::move(hardPoints));
	}

	auto collisionEntry = ShipCollisionHardpoint(componentName, hardpointName);
	collisionEntry.setPosition(hardpointPosition);
	collisionEntry.setSphere(hardpointSphere);
	collisionEntry.setVolumeType(RADIUS);
	collisionEntry.setRadius(radius);
	collisionEntry.setSlot(slot);
	collisionEntry.setTargetable(radius > 0.f);

	auto hardPointEntry = &hardpointMap.get(slotName);
	hardPointEntry->put(componentName.hashCode(), std::move(collisionEntry));

	if (collisionEntry.isTargetable() && !targetableSlots.contains(slot)) {
		targetableSlots.add(slot);
	}
}

void ShipCollisionData::addCollisionHardpoint(SharedShipObjectTemplate* shipTemplate, const String& componentName, const String& attachmentName, const String& hardpointName, int slot, float radius) {
	auto shipAppearance = shipTemplate->getAppearanceTemplate();

	if (shipAppearance == nullptr || attachmentName == "" || hardpointName == "") {
		return;
	}

	auto hardpointAppearance = TemplateManager::instance()->getAppearanceTemplate(attachmentName.replaceAll("shared_", ""));

	if (hardpointAppearance == nullptr) {
		return;
	}

	auto boundingVolume = hardpointAppearance->getBoundingVolume();

	if (boundingVolume == nullptr) {
		return;
	}

	auto collisionVolume = hardpointAppearance->getCollisionVolume();

	if (collisionVolume == nullptr) {
		collisionVolume = boundingVolume;
	}

	const AABB& box = collisionVolume->getBoundingBox();
	const Sphere& boundingSphere = collisionVolume->getBoundingSphere();
	const Vector3& boundingPosition = boundingSphere.getCenter();
	float boundingRadius = boundingSphere.getRadius();

	const auto& hardpointTransforms = shipAppearance->getHardpoints();

	Matrix4 hardpointRotation = hardpointTransforms.get(hardpointName);
	Vector3 hardpointPosition = Vector3(hardpointRotation[3][0], hardpointRotation[3][1], hardpointRotation[3][2]);

	hardpointRotation.setTranslation(0,0,0);

	const auto& attachmentTransforms = hardpointAppearance->getHardpoints();

	if (attachmentTransforms.contains("turretpitch1")) {
		auto attachmentRotation = attachmentTransforms.get("turretpitch1");
		auto attachmentPosition = Vector3(attachmentRotation[3][0], attachmentRotation[3][1], attachmentRotation[3][2]);

		attachmentRotation.setTranslation(0,0,0);
		hardpointRotation = hardpointRotation * attachmentRotation;
	}

	Sphere hardpointSphere = getHardpointBoundingSphere(Sphere(Vector3::ZERO, boundingRadius), hardpointPosition, hardpointRotation);
	AABB hardpointBox = getHardpointBoundingBox(box, hardpointPosition, hardpointRotation);
	int hardpointType = getBoundingVolumeType(collisionVolume);
	float hardpointRadius = Math::max(boundingRadius, radius);

	if (hardpointType == BOX) {
		hardpointSphere = getHardpointBoundingSphere(box, hardpointPosition, hardpointRotation);
	}

	const auto& slotName = Components::shipComponentSlotToString(slot);

	if (!hardpointMap.contains(slotName)) {
		auto hardPoints = VectorMap<uint32, ShipCollisionHardpoint>();
		hardPoints.setAllowDuplicateInsertPlan();
		hardpointMap.put(slotName, std::move(hardPoints));
	}

	auto collisionEntry = ShipCollisionHardpoint(componentName, hardpointName);
	collisionEntry.setAppearanceTemplate(hardpointAppearance);
	collisionEntry.setPosition(hardpointPosition);
	collisionEntry.setSphere(hardpointSphere);
	collisionEntry.setBox(hardpointBox);
	collisionEntry.setVolumeType(hardpointType);
	collisionEntry.setRadius(hardpointRadius);
	collisionEntry.setSlot(slot);
	collisionEntry.setTargetable(radius > 0.f);

	if (!isIdentityMatrix(hardpointRotation)) {
		collisionEntry.setRotation(new Matrix4(hardpointRotation));
	}

	auto hardPointEntry = &hardpointMap.get(slotName);
	hardPointEntry->put(componentName.hashCode(), std::move(collisionEntry));

	if (collisionEntry.isTargetable() && !targetableSlots.contains(slot)) {
		targetableSlots.add(slot);
	}
}

int ShipCollisionData::getBoundingVolumeType(const BaseBoundingVolume* volume) const {
	if (volume->isBoundingSphere()) {
		return SPHERE;
	}
	if (volume->isBoundingBox()) {
		return BOX;
	}
	return MESH;
}

bool ShipCollisionData::isIdentityMatrix(const Matrix4& matrix) const {
	return matrix[0][0] == 1.f && matrix[1][1] == 1.f && matrix[2][2] == 1.f && matrix[3][3] == 1.f && matrix[0][1] == 0.f && matrix[0][2] == 0.f && matrix[0][3] == 0.f && matrix[1][0] == 0.f && matrix[1][2] == 0.f && matrix[1][3] == 0.f && matrix[2][0] == 0.f && matrix[2][1] == 0.f && matrix[2][3] == 0.f &&
		   matrix[3][0] == 0.f && matrix[3][1] == 0.f && matrix[3][2] == 0.f;
}

Sphere ShipCollisionData::getChassisBoundingSphere(const BaseBoundingVolume* volume) const {
	const auto& sphere = volume->getBoundingSphere();
	float radius = sphere.getCenter().length() + sphere.getRadius();

	return Sphere(Vector3::ZERO, radius);
}

Sphere ShipCollisionData::getHardpointBoundingSphere(const Sphere& sphere, const Vector3& position, const Matrix4& rotation) const {
	Vector3 spherePosition = position + (sphere.getCenter() * rotation);

	return Sphere(spherePosition, sphere.getRadius());
}

Sphere ShipCollisionData::getHardpointBoundingSphere(const AABB& box, const Vector3& position, const Matrix4& rotation) const {
	const Vector3& boxCenter = box.center();
	float radius = (boxCenter - *box.getMinBound()).length();
	Vector3 transformedCenter = position + (boxCenter * rotation);

	return Sphere(transformedCenter, radius);
}

AABB ShipCollisionData::getHardpointBoundingBox(const AABB& box, const Vector3& position, const Matrix4& rotation) const {
	auto maxBound = position + (*box.getMaxBound() * rotation);
	auto minBound = position + (*box.getMinBound() * rotation);

	float maxX = Math::max(minBound.getX(), maxBound.getX());
	float maxY = Math::max(minBound.getY(), maxBound.getY());
	float maxZ = Math::max(minBound.getZ(), maxBound.getZ());

	float minX = Math::min(minBound.getX(), maxBound.getX());
	float minY = Math::min(minBound.getY(), maxBound.getY());
	float minZ = Math::min(minBound.getZ(), maxBound.getZ());

	return AABB(Vector3(minX, minY, minZ), Vector3(maxX, maxY, maxZ));
}

String ShipCollisionData::getAttachmentTemplatePath(const String& attachmentName, int slot) const {
	switch (slot) {
		case Components::CHASSIS:
			return "object/tangible/ship/attachment/wing/" + attachmentName + ".iff";
		case Components::ENGINE:
			return "object/tangible/ship/attachment/engine/" + attachmentName + ".iff";
		case Components::SHIELD0:
		case Components::SHIELD1:
			return "object/tangible/ship/attachment/shield/" + attachmentName + ".iff";
		case Components::BOOSTER:
			return "object/tangible/ship/attachment/booster/" + attachmentName + ".iff";
		case Components::BRIDGE:
			return "object/tangible/ship/attachment/bridge/" + attachmentName + ".iff";
		case Components::HANGAR:
			return "object/tangible/ship/attachment/hangar/" + attachmentName + ".iff";
		default: {
			if (slot >= Components::WEAPON_START) {
				return "object/tangible/ship/attachment/weapon/" + attachmentName + ".iff";
			}
		}
	}

	return "";
}

String ShipCollisionData::getShipFileName(const String& shipName) const {
	String chassisName = shipName.replaceAll("shared_", "");

	if (!chassisName.contains(".iff")) {
		String path = chassisName.contains("player_") ? "object/ship/player/" : "object/ship/";
		chassisName = path + chassisName + ".iff";
	}

	return chassisName;
}

const VectorMap<uint32, ShipCollisionHardpoint>& ShipCollisionData::getHardpoints(const String& slotName) const {
	return hardpointMap.get(slotName);
}

const VectorMap<uint32, ShipCollisionHardpoint>& ShipCollisionData::getHardpoints(uint32 slot) const {
	return hardpointMap.get(Components::shipComponentSlotToString(slot));
}

const Vector<uint32>& ShipCollisionData::getTargetableSlots() const {
	return targetableSlots;
}

int ShipCollisionData::getSlotWeight(uint32 slot) const {
	return slotWeights.get(slot);
}

const AppearanceTemplate* ShipCollisionData::getAppearanceTemplate() const {
	return appearance;
}

const Sphere& ShipCollisionData::getBoundingSphere() const {
	return boundingSphere;
}

const Sphere& ShipCollisionData::getChassisSphere() const {
	return chassisSphere;
}

const AABB& ShipCollisionData::getChassisBox() const {
	return chassisBox;
}

int ShipCollisionData::getVolumeType() const {
	return volumeType;
}

int ShipCollisionData::getHardpointSize() const {
	return hardpointSize;
}

String ShipCollisionData::toDebugString(bool includeHardpoints) const {
	StringBuffer msg;

	msg << "  apearanceName:  " << (appearance ? appearance->getFileName() : "") << endl
		<< "  boundingSphere: " << boundingSphere.getCenter().toString() << endl
		<< "  boundingRadius: " << boundingSphere.getRadius() << endl
		<< "  chassisSphere:  " << chassisSphere.getCenter().toString() << endl
		<< "  chassisRadius:  " << chassisSphere.getRadius() << endl
		<< "  chassisBox:     " << chassisBox.getMinBound()->toString() << " " << chassisBox.getMaxBound()->toString() << endl
		<< "  volumeType:     " << volumeType << endl
		<< "--------------------------------" << endl;

	if (includeHardpoints) {
		for (int i = 0; i < hardpointMap.size(); ++i) {
			auto harpdoints = hardpointMap.elementAt(i).getValue();

			for (int ii = 0; ii < harpdoints.size(); ++ii) {
				msg << harpdoints.elementAt(ii).getValue().toDebugString() << endl;
			}
		}
	}

	return msg.toString();
}