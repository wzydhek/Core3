#include "ResourceListForSurveyMessage.h"

ResourceListForSurveyMessage::ResourceListForSurveyMessage() : BaseMessage() {
	/* Struct
	 * 04 00 // Operand
	 * D5 B1 64 8A // Opcode
	 * INT // Number of resources in list
	 * {
	 * SHORT // Size of String.
	 * Variable // A_STRING
	 * LONG // Resource ObjectID
	 * }
	 * SHORT // Size of String
	 * Variable // A_STRING of resource type (ex. "flora_resources")
	 * LONG // PlayerID
	 */

	insertShort(4);
	insertInt(0x8A64B1D5);
	insertInt(0);
	listSize = 0;
}

void ResourceListForSurveyMessage::addResource(String resourceName, String resourceType, uint64 objectID) {
	insertAscii(resourceName);
	insertLong(objectID);
	insertAscii(resourceType);
	++listSize;
}

void ResourceListForSurveyMessage::finish(String resourceType, long playerID) {
	insertAscii(resourceType);
	insertLong(playerID);
	insertInt(10, listSize);
}