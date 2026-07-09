#include "ResourceTreeEntry.h"
#include "ResourceTreeNode.h"

/**
 * Constructor
 * \param inType The type of resource this in in stfname
 */
ResourceTreeEntry::ResourceTreeEntry(const String& inType) {
	type = inType;

	recycled = false;
	children = false;
	jtl = false;

	maxtype = 0;
	mintype = 0;
	minpool = 0;
	maxpool = 0;

	resourceContainerType = "";
	randomNameClass = "";

	zoneRestriction = "";

	surveyToolType = -1;

	recycleToolType = -1;

	containerCRC = 0;

	attributeMap.setNullValue(nullptr);

	myNode = nullptr;
}

/**
 * Deconstructor
 */
ResourceTreeEntry::~ResourceTreeEntry() {
	for (int i = 0; i < attributeMap.size(); ++i)
		delete attributeMap.get(i);
}

/**
 * Sets the node this entry is on
 * \param node Tree Node
 */
void ResourceTreeEntry::setMyNode(ResourceTreeNode* node) {
	myNode = node;
}

/**
 * Gets the node this entry is on
 * \return Node this entry is on
 */
ResourceTreeNode* ResourceTreeEntry::getMyNode() {
	return myNode;
}

const ResourceTreeNode* ResourceTreeEntry::getMyNode() const {
	return myNode;
}

/**
 * Adds class to classList
 * \param newclass New class string to add
 */
void ResourceTreeEntry::addClass(const String newclass) {
	classList.add(newclass);
}

/**
 * Adds stfClass to stfClassList
 * \param newclass New class string to add
 */
void ResourceTreeEntry::addStfClass(const String newclass) {
	stfClassList.add(newclass);
}

/**
 * Gets class based in Vector index
 * \param index index
 * \return Class at index
 */
String ResourceTreeEntry::getClass(const int index) const {
	if (index <= classList.size())
		return classList.get(index);
	else
		return "";
}

/**
 * Gets stfClass based on vector index
 * \param index index
 * \return StfClass at index
 */
String ResourceTreeEntry::getStfClass(const int index) const {
	if (index <= stfClassList.size())
		return stfClassList.get(index);
	else
		return "";
}

/**
 * Gets size on classList
 * \return classList size
 */
int ResourceTreeEntry::getClassCount() const {
	return classList.size();
}

/**
 * Gets size of stfClassList
 * \return stfClassList size
 */
int ResourceTreeEntry::getStfClassCount() const {
	return stfClassList.size();
}

/**
 * Gets the Final Class name
 * \return Final name of entry
 */
String ResourceTreeEntry::getFinalClass() const {
	if (classList.size() > 0)
		return classList.get(classList.size() - 1);
	else
		return "";
}

/**
 * Denotes if entry is organic
 * \return Is value organic
 */
bool ResourceTreeEntry::isOrganic() const {
	if (classList.size() > 0)
		return classList.get(0) == "Organic";
	else
		return false;
}

/**
 * Adds an attribute to this entry
 * \param attrib ResourceAttribute to add
 */
void ResourceTreeEntry::addAttribute(ResourceAttribute* attrib) {
	attributeMap.put(attrib->getName(), attrib);
}

/**
 * Gets attribute
 * \param index index of attribute
 * \return ResourceAttibute at index
 */
const ResourceAttribute* ResourceTreeEntry::getAttribute(const String& attrib) const {
	return attributeMap.get(attrib);
}

/**
 * Gets attribute
 * \param index index of attribute
 * \return ResourceAttibute at index
 */
const ResourceAttribute* ResourceTreeEntry::getAttribute(const int index) const {
	return attributeMap.get(index);
}

/**
 * Gets number of attributes
 * \return Number of attributes
 */
int ResourceTreeEntry::getAttributeCount() const {
	return attributeMap.size();
}

/**
 * Gets maxpool
 * \return maxpool
 */
int ResourceTreeEntry::getMaxpool() const {
	return maxpool;
}

/**
 * Gets maxtype
 * \return maxtype
 */
int ResourceTreeEntry::getMaxtype() const {
	return maxtype;
}

/**
 * Gets minpool
 * \return minpool
 */
int ResourceTreeEntry::getMinpool() const {
	return minpool;
}

/**
 * Gets mintype
 * \return mintype
 */
int ResourceTreeEntry::getMintype() const {
	return mintype;
}

/**
 * Gets type
 * \return type
 */
const String& ResourceTreeEntry::getType() const {
	return type;
}

/**
 * Gets randomNameClass
 * \return randomNameClass
 */
const String ResourceTreeEntry::getRandomNameClass() const {
	return randomNameClass;
}

/**
 * Gets zoneRestriction
 * \return zoneRestriction
 */
const String& ResourceTreeEntry::getZoneRestriction() const {
	return zoneRestriction;
}

/**
 * Gets recycled
 * \return recycled
 */
bool ResourceTreeEntry::isRecycled() const {
	return recycled == true;
}

/**
 * Gets resourceContainerType
 * \return resourceContainerType
 */
const String& ResourceTreeEntry::getResourceContainerType() const {
	return resourceContainerType;
}

/**
 * sets maxpool
 * \param maxpool
 */
void ResourceTreeEntry::setMaxpool(int maxpool) {
	this->maxpool = maxpool;
}

/**
 * sets maxtype
 * \param maxtype
 */
void ResourceTreeEntry::setMaxtype(int maxtype) {
	this->maxtype = maxtype;
}

/**
 * sets minpool
 * \param minpool
 */
void ResourceTreeEntry::setMinpool(int minpool) {
	this->minpool = minpool;
}

/**
 * sets mintype
 * \param mintype
 */
void ResourceTreeEntry::setMintype(int mintype) {
	this->mintype = mintype;
}

/**
 * sets type
 * \param type
 */
void ResourceTreeEntry::setType(const String& name) {
	this->type = name;
}

/**
 * sets randomNameClass
 * \param randomNameClass
 */
void ResourceTreeEntry::setRandomNameClass(const String& randomNameClass) {
	this->randomNameClass = randomNameClass;
}

/**
 * sets recycled
 * \param recycled
 */
void ResourceTreeEntry::setRecycled(bool recycled) {
	this->recycled = recycled;
}

/**
 * sets resourceContainerType
 * \param resourceContainerType
 */
void ResourceTreeEntry::setResourceContainerType(const String& resourceContainerType) {
	this->resourceContainerType = resourceContainerType;
	containerCRC = resourceContainerType.hashCode();
}

/**
 * Does entry have children
 * \return children
 */
bool ResourceTreeEntry::hasChildren() const {
	return children;
}

/**
 * sets children
 * \param child
 */
void ResourceTreeEntry::setChildren(bool child) {
	children = child;
}

/**
 * sets zoneRestriction
 * \param zone
 */
void ResourceTreeEntry::setZoneRestriction(const String& zone) {
	zoneRestriction = zone;
}

/**
 * Lets us know if it is zonerestricted type
 * \return isZoneRestricted
 */
bool ResourceTreeEntry::isZoneRestricted() const {
	return zoneRestriction != "";
}

/**
 * sets jtl
 * \param j
 */
void ResourceTreeEntry::setJTL(bool j) {
	jtl = j;
}

/**
 * Is JTL?
 * \return is Jtl resource
 */
bool ResourceTreeEntry::isJTL() const {
	return jtl;
}

/**
 * Sets surveyToolType
 * \param type
 */
void ResourceTreeEntry::setSurveyToolType(int type) {
	surveyToolType = type;
}

/**
 * Gets surveyToolType
 * \return surveyToolType
 */
int ResourceTreeEntry::getSurveyToolType() const {
	return surveyToolType;
}

/**
 * Sets recycleToolType
 * \param type
 */
void ResourceTreeEntry::setRecycleToolType(int type) {
	recycleToolType = type;
}

/**
 * Gets recycleToolType
 * \return recycleToolType
 */
int ResourceTreeEntry::getRecycleToolType() const {
	return recycleToolType;
}

/**
 * Gets containerCRC
 * \return containerCRC
 */
uint32 ResourceTreeEntry::getContainerCRC() const {
	return containerCRC;
}

/**
 * Tells us is Entry if of type
 * \param type
 */
bool ResourceTreeEntry::isType(const String& type) const {
	for (int i = 0; i < stfClassList.size(); ++i) {
		if (stfClassList.get(i) == type)
			return true;
	}
	for (int i = 0; i < classList.size(); ++i) {
		if (classList.get(i) == type)
			return true;
	}
	return false;
}

/**
 * Outputs visual representation of class
 */
void ResourceTreeEntry::toString() const {
	System::out << "************ Resource Tree Entry ********************\n";
	System::out << "Type = " << type << endl;
	for (int i = 0; i < classList.size(); ++i)
		System::out << "Class" << i << " = " << classList.get(i) << endl;

	for (int i = 0; i < stfClassList.size(); ++i)
		System::out << "STFClass" << i << " = " << stfClassList.get(i) << endl;

	System::out << "Max Types = " << maxtype << endl;
	System::out << "Min Types = " << mintype << endl;
	System::out << "Min Pools = " << minpool << endl;
	System::out << "Max Pools = " << maxpool << endl;

	for (int i = 0; i < attributeMap.size(); ++i)
		System::out << attributeMap.get(i)->getName() << ": " << attributeMap.get(i)->getMinimum() << " - " << attributeMap.get(i)->getMaximum() << endl;

	System::out << "Recycled = " << recycled << endl;
	System::out << "Resource Container Type = " << resourceContainerType << endl;
	System::out << "Random Name Class = " << randomNameClass << endl;
	System::out << "Zone Restriction = " << zoneRestriction << endl;
	System::out << "Survey Tool Type = " << surveyToolType << endl;
}