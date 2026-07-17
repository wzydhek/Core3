/*
 * ComponentMap.h
 *
 *  Created on: Apr 1, 2015
 *      Author: swgemu
 */

#pragma once

#include "engine/log/Logger.h"
#include "engine/util/iffstream/IffStream.h"
#include "engine/util/Singleton.h"
#include "templates/manager/TemplateManager.h"
#include "templates/datatables/DataTableIff.h"
#include "templates/datatables/DataTableRow.h"
#include "system/util/VectorMap.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace crafting {

class ComponentMapEntry : public Object {
	uint32 id;
	String templateFilename;
	String hardpoint;

public:

	ComponentMapEntry();

	ComponentMapEntry(const ComponentMapEntry& e);

	ComponentMapEntry& operator=(const ComponentMapEntry& e);

	ComponentMapEntry(uint32 _id, String _templateFilename, String _hardpoint);

	const String& getHardpoint() const;

	void setHardpoint(const String& hardpoint);

	uint32 getId() const;

	void setId(uint32 id);

	const String& getTemplateFilename() const;

	void setTemplateFilename(const String& templateFilename);
};

class ComponentMap : public VectorMap<uint32, ComponentMapEntry>, public Singleton<ComponentMap>, public Logger {
	VectorMap<uint32, VectorMap<uint32, VectorMap<uint32, uint32> > > visibleComponentMap;

public:
	ComponentMap();

	ComponentMapEntry getFromID(uint32 id);

	void loadVisibleComponentsFile();

	const VectorMap<uint32, uint32>& getVisibleCRC(uint32 tempCRC, uint32 slotCRC) const;
};

} // namespace crafting
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::crafting;
