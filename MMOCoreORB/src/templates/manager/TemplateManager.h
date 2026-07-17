/*
 * TemplateManager.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "engine/util/ObjectFactory.h"
#include "system/util/SynchronizedVectorMap.h"
#include "templates/SharedObjectTemplate.h"
#include "templates/footprint/StructureFootprint.h"
#include "templates/slots/SlotId.h"
#include "templates/slots/SlotDescriptor.h"
#include "templates/slots/ArrangementDescriptor.h"
#include "templates/manager/PlanetMapCategoryList.h"
#include "templates/manager/PlanetMapCategory.h"
#include "templates/manager/PlanetMapSubCategoryList.h"
#include "templates/manager/PlanetMapSubCategory.h"
#include "templates/manager/PortalLayoutMap.h"
#include "templates/appearance/PaletteTemplate.h"

namespace templates {

class TemplateCRCMap;
class ClientTemplateCRCMap;

class TemplateManager : public Singleton<TemplateManager>, public Logger, public Object {
	TemplateCRCMap* templateCRCMap;

	ObjectFactory<SharedObjectTemplate* (), uint32> templateFactory;
	ClientTemplateCRCMap* clientTemplateCRCMap;
	PortalLayoutMap* portalLayoutMap;
	FloorMeshMap* floorMeshMap;
	AppearanceMap* appearanceMap;
	InteriorMap* interiorMap;

	PlanetMapCategoryList planetMapCategoryList;
	PlanetMapSubCategoryList planetMapSubCategoryList;

	SynchronizedVectorMap<String, Reference<StructureFootprint*> > structureFootprints;

	SynchronizedVectorMap<String, Reference<SlotId*> > slotDefinitions;
	SynchronizedVectorMap<String, Reference<SlotDescriptor*> > slotDescriptors;
	SynchronizedVectorMap<String, Reference<ArrangementDescriptor*> > arrangementDescriptors;

	ReadWriteLock appearanceMapLock;

	void loadTreArchive();
	void loadSlotDefinitions();
	void loadPlanetMapCategories();
	void loadAssetCustomizationManager();

public:
	static Lua* luaTemplatesInstance;
	static AtomicInteger loadedTemplatesCount;
	static int ERROR_CODE;

#ifdef PLATFORM_WIN
#undef NO_ERROR
#endif

	enum TEMPLATE_ERROR_CODE { NO_ERROR = 0, GENERAL_ERROR, NO_TRE_PATH, NO_TRE_FILES,
		LOAD_TRES_ERROR, SLOT_DEFINITION_FILE_NOT_FOUND,
		ASSETCUSTOMIZATIONMANAGER_FILE_NOT_FOUND,
		CUSTOMIZATION_ID_MANAGER_FILE_NOT_FOUND,
		PALLETE_COLUMNS_FILE_NOT_FOUND, HAIR_ASSETS_FILE_NOT_FOUND,
		PLANET_CAT_FILE_NOT_FOUND, LOAD_LUA_TEMPLATE_ERROR};

protected:
	//this is only to be used when loading client dervs
	LuaObject* getLuaObject(const String& iffTemplateName);

public:
	TemplateCRCMap& getTemplateCRCMap() const;

	TemplateManager();
	~TemplateManager();

	virtual void registerTemplateObjects();

	virtual void loadLuaTemplates();

	/**
	 * Attempts to get the slot descriptor. If the slot descriptor isn't loaded, attempt to load it.
	 */
	Reference<SlotDescriptor*> getSlotDescriptor(const String& filename);
	Reference<ArrangementDescriptor*> getArrangementDescriptor(const String& filename);

	/**
	 * Attempts to load a Structure Footprint file from the TRE, and places it in the map.
	 * If the structure footprint already exists in the map, then it is simply returned.
	 * If the structure footprint cannot be found, then a warning is displayed, and nullptr is returned
	 * @param filePath The TRE path to the Structure Footprint file from the root directory.
	 * @return Returns nullptr if not found, else returns the StructureFootprint.
	 */
	const StructureFootprint* loadStructureFootprint(const String& filePath);

	void addTemplate(uint32 key, const String& fullName, LuaObject* templateData);

	const String& getTemplateFile(uint32 key) const;

	SharedObjectTemplate* getTemplate(uint32 key) const;

	IffStream* openIffFile(const String& fileName);

	ObjectInputStream* openTreFile(const String& filePath);

	bool containsTemplateType(uint32 type) const;

	FloorMesh* getFloorMesh(const String& fileName);
	PortalLayout* getPortalLayout(const String& fileName);
	InteriorLayoutTemplate* getInteriorLayout(const String& fileName);
	AppearanceTemplate* getAppearanceTemplate(const String& fileName);
	AppearanceTemplate* instantiateAppearanceTemplate(IffStream* iffStream);
	PaletteTemplate* getPaletteTemplate(const String& fileName);

	bool existsTemplate(uint32 key) const;

	// LUA
	void registerFunctions();
	void registerGlobals();
	static int includeFile(lua_State* L);
	static int crcString(lua_State* L);
	static int addTemplateCRC(lua_State* L);
	static int addClientTemplate(lua_State* L);

	void addClientTemplate(uint32 crc, const String& templateName);

	// Primary Planet Map Categories
	const PlanetMapCategory* getPlanetMapCategoryByName(const String& name) const;

	const PlanetMapCategory* getPlanetMapCategoryByCrc(int crc) const;

	const PlanetMapCategory* getPlanetMapCategoryById(int index) const;

	// Planet Map Sub Categories
	const PlanetMapSubCategory* getPlanetMapSubCategoryByName(const String& name) const;

	const PlanetMapSubCategory* getPlanetMapSubCategoryByCrc(int crc) const;

	const PlanetMapSubCategory* getPlanetMapSubCategoryById(int index) const;

	/**
	 * This method should only be called after Templates have been loaded.
	 * It attempts to return the StructureFootprint that resides at the specified filepath, but requires
	 * that it has been loaded previously.
	 * @param filePath The TRE path of the desired Structure Footprint file.
	 * @return Returns the StructureFootprint object, or nullptr if it does not exist.
	 */
	const StructureFootprint* getStructureFootprint(const String& filePath) const;

	bool structureFootprintExists(const String& filePath) const;

	const SlotId* getSlotId(const String& slotName) const;

	friend class SharedObjectTemplate;
};

} // namespace templates

using namespace templates;
