/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file ResourceTreeEntry.h
 * \author Kyle Burkhardt
 * \date 5-03-10
 */

#pragma once

#include "ResourceAttribute.h"

/**
 * The ResourceTreeEntry class represents an
 * entry on the ResourceTree node tree
 */
class ResourceTreeNode;

class ResourceTreeEntry {
private:

	/// Node that this entry is on
	ResourceTreeNode* myNode;

	/// Stf type
	String type;

	/// List of Class names in plain english Format
	Vector<String> classList;

	/// List of Class names in swg stfname
	Vector<String> stfClassList;

	/// List of Attributes
	VectorMap<String, ResourceAttribute* > attributeMap;

	/// Maximum of this type that can spawn
	int maxtype;
	/// Minimum of this type that can spawn
	int mintype;

	/// Minimum number of resource pools this spawns in
	int minpool;

	/// Maximum number of resource pools this spawns in
	int maxpool;

	/// If type is a recycled type
	bool recycled;

	/// Notates if this entry has children
	bool children;

	/// Notates id this resource is restricted to a zone
	String zoneRestriction;

	/// Lets us know if this resource was a JTL resource
	bool jtl;

	/// The script that explains the resource container type
	String resourceContainerType;

	/// Used in resource name generation
	String randomNameClass;

	/// The type of survey tool that can survey this
	int surveyToolType;

	/// The recyler setting that can recycle this
	int recycleToolType;

	/// CRC of resourceContainerType
	uint32 containerCRC;

public:
	/**
	 * Constructor
	 * \param inType The type of resource this in in stfname
	 */
	ResourceTreeEntry(const String& inType);

	/**
	 * Deconstructor
	 */
	~ResourceTreeEntry();

	/**
	 * Sets the node this entry is on
	 * \param node Tree Node
	 */
	void setMyNode(ResourceTreeNode* node);

	/**
	 * Gets the node this entry is on
	 * \return Node this entry is on
	 */
	ResourceTreeNode* getMyNode();

	const ResourceTreeNode* getMyNode() const;

	/**
	 * Adds class to classList
	 * \param newclass New class string to add
	 */
	void addClass(const String newclass);

	/**
	 * Adds stfClass to stfClassList
	 * \param newclass New class string to add
	 */
	void addStfClass(const String newclass);

	/**
	 * Gets class based in Vector index
	 * \param index index
	 * \return Class at index
	 */
	String getClass(const int index) const;

	/**
	 * Gets stfClass based on vector index
	 * \param index index
	 * \return StfClass at index
	 */
	String getStfClass(const int index) const;

	/**
	 * Gets size on classList
	 * \return classList size
	 */
	int getClassCount() const;

	/**
	 * Gets size of stfClassList
	 * \return stfClassList size
	 */
	int getStfClassCount() const;

	/**
	 * Gets the Final Class name
	 * \return Final name of entry
	 */
	String getFinalClass() const;

	/**
	 * Denotes if entry is organic
	 * \return Is value organic
	 */
	bool isOrganic() const;

	/**
	 * Adds an attribute to this entry
	 * \param attrib ResourceAttribute to add
	 */
	void addAttribute(ResourceAttribute* attrib);

	/**
	 * Gets attribute
	 * \param index index of attribute
	 * \return ResourceAttibute at index
	 */
	const ResourceAttribute* getAttribute(const String& attrib) const;

	/**
	 * Gets attribute
	 * \param index index of attribute
	 * \return ResourceAttibute at index
	 */
	const ResourceAttribute* getAttribute(const int index) const;

	/**
	 * Gets number of attributes
	 * \return Number of attributes
	 */
	int getAttributeCount() const;

	/**
	 * Gets maxpool
	 * \return maxpool
	 */
	int getMaxpool() const;

	/**
	 * Gets maxtype
	 * \return maxtype
	 */
	int getMaxtype() const;

	/**
	 * Gets minpool
	 * \return minpool
	 */
	int getMinpool() const;

	/**
	 * Gets mintype
	 * \return mintype
	 */
	int getMintype() const;

	/**
	 * Gets type
	 * \return type
	 */
	const String& getType() const;

	/**
	 * Gets randomNameClass
	 * \return randomNameClass
	 */
	const String getRandomNameClass() const;

	/**
	 * Gets zoneRestriction
	 * \return zoneRestriction
	 */
	const String& getZoneRestriction() const;

	/**
	 * Gets recycled
	 * \return recycled
	 */
	bool isRecycled() const;

	/**
	 * Gets resourceContainerType
	 * \return resourceContainerType
	 */
	const String& getResourceContainerType() const;

	/**
	 * sets maxpool
	 * \param maxpool
	 */
	void setMaxpool(int maxpool);

	/**
	 * sets maxtype
	 * \param maxtype
	 */
	void setMaxtype(int maxtype);

	/**
	 * sets minpool
	 * \param minpool
	 */
	void setMinpool(int minpool);

	/**
	 * sets mintype
	 * \param mintype
	 */
	void setMintype(int mintype);

	/**
	 * sets type
	 * \param type
	 */
	void setType(const String& name);

	/**
	 * sets randomNameClass
	 * \param randomNameClass
	 */
	void setRandomNameClass(const String& randomNameClass);

	/**
	 * sets recycled
	 * \param recycled
	 */
	void setRecycled(bool recycled);

	/**
	 * sets resourceContainerType
	 * \param resourceContainerType
	 */
	void setResourceContainerType(const String& resourceContainerType);

	/**
	 * Does entry have children
	 * \return children
	 */
	bool hasChildren() const;

	/**
	 * sets children
	 * \param child
	 */
	void setChildren(bool child);

	/**
	 * sets zoneRestriction
	 * \param zone
	 */
	void setZoneRestriction(const String& zone);

	/**
	 * Lets us know if it is zonerestricted type
	 * \return isZoneRestricted
	 */
	bool isZoneRestricted() const;

	/**
	 * sets jtl
	 * \param j
	 */
	void setJTL(bool j);

	/**
	 * Is JTL?
	 * \return is Jtl resource
	 */
	bool isJTL() const;

	/**
	 * Sets surveyToolType
	 * \param type
	 */
	void setSurveyToolType(int type);

	/**
	 * Gets surveyToolType
	 * \return surveyToolType
	 */
	int getSurveyToolType() const;

	/**
	 * Sets recycleToolType
	 * \param type
	 */
	void setRecycleToolType(int type);

	/**
	 * Gets recycleToolType
	 * \return recycleToolType
	 */
	int getRecycleToolType() const;

	/**
	 * Gets containerCRC
	 * \return containerCRC
	 */
	uint32 getContainerCRC() const;

	/**
	 * Tells us is Entry if of type
	 * \param type
	 */
	bool isType(const String& type) const;

	/**
	 * Outputs visual representation of class
	 */
	void toString() const;
};
