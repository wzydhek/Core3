/*
 * GuildMemberInfo.cpp
 *
 *  Created on: Nov 4, 2010
 *      Author: crush
 */

#include "GuildMemberInfo.h"
#include "server/zone/objects/guild/GuildObject.h"

GuildMemberInfo::GuildMemberInfo() {
	playerID = 0;
	permissions = 0;
	declaredAllegiance = 0;

	// addSerializableVariables();
}

GuildMemberInfo::GuildMemberInfo(uint64 playerid) : Object() {
	playerID = playerid;
	permissions = GuildObject::PERMISSION_NONE;
	declaredAllegiance = 0;

	//addSerializableVariables();
}

GuildMemberInfo::GuildMemberInfo(const GuildMemberInfo& gmi) : Object() {
	playerID = gmi.playerID;
	guildTitle = gmi.guildTitle;
	permissions = gmi.permissions;
	declaredAllegiance = gmi.declaredAllegiance;

	// addSerializableVariables();
}

int GuildMemberInfo::compareTo(const GuildMemberInfo& gmi) const {
	if (playerID < gmi.playerID)
		return 1;
	else if (playerID > gmi.playerID)
		return -1;
	else
		return 0;
}

GuildMemberInfo& GuildMemberInfo::operator=(const GuildMemberInfo& gmi) {
	if (this == &gmi)
		return *this;

	playerID = gmi.playerID;
	guildTitle = gmi.guildTitle;
	permissions = gmi.permissions;
	declaredAllegiance = gmi.declaredAllegiance;

	return *this;
}

bool GuildMemberInfo::toBinaryStream(ObjectOutputStream* stream) {
	stream->writeLong(playerID);
	guildTitle.toBinaryStream(stream);
	stream->writeByte(permissions);
	stream->writeLong(declaredAllegiance);

	return true;
}

bool GuildMemberInfo::parseFromBinaryStream(ObjectInputStream* stream) {
	playerID = stream->readLong();
	guildTitle.parseFromBinaryStream(stream);
	permissions = stream->readByte();
	declaredAllegiance = stream->readLong();

	return true;
}

uint64 GuildMemberInfo::getPlayerID() {
	return playerID;
}

void GuildMemberInfo::setPlayerID(uint64 playerid) {
	playerID = playerid;
}

String& GuildMemberInfo::getGuildTitle() {
	return guildTitle;
}

void GuildMemberInfo::setGuildTitle(const String& title) {
	guildTitle = title;
}

uint8 GuildMemberInfo::getPermissions() {
	return permissions;
}

void GuildMemberInfo::setPermissions(uint8 permission) {
	permissions = permission;
}

void GuildMemberInfo::addPermission(uint8 permission) {
	permissions |= permission;
}

void GuildMemberInfo::removePermission(uint8 permission) {
	permissions &= ~permission;
}

void GuildMemberInfo::togglePermission(uint8 permission) {
	permissions ^= permission;
}

bool GuildMemberInfo::hasPermission(uint8 permission) {
	return (permissions & permission);
}

void server::zone::objects::guild::to_json(nlohmann::json& j, const GuildMemberInfo& m) {
	j["playerID"] = m.playerID;
	j["guildTitle"] = m.guildTitle;
	j["permissions"] = m.permissions;
	j["declaredAllegiance"] = m.declaredAllegiance;
}
