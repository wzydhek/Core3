/*
 * HopperMap.h
 *
 *  Created on: 11/06/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/scene/variables/DeltaVector.h"
#include "server/zone/objects/resource/ResourceContainer.h"

class HopperList : public DeltaVector<ManagedReference<ResourceContainer*> > {
public:

	ManagedReference<ResourceContainer*> set(int idx, const ManagedReference<ResourceContainer*>& newValue, DeltaMessage* message = nullptr, int updates = 1) override;

	bool add(const ManagedReference<ResourceContainer*>& element, DeltaMessage* message = nullptr, int updates = 1) override;

	void insertToMessage(BaseMessage* msg) const override;
};
