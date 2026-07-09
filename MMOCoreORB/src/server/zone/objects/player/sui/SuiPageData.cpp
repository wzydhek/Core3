/*
 * SuiPageData.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: crush
 */


#include "SuiPageData.h"
#include "SuiCommand.h"
#include "server/zone/ZoneClientSession.h"
#include "server/zone/packets/ui/SuiCreatePageMessage.h"
#include "server/zone/packets/ui/SuiUpdatePageMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

SuiPageData::SuiPageData(const String& rootPage) : Object() {
	init(rootPage, 0, 0);
}

SuiPageData::SuiPageData(const String& rootPage, const uint64& targetNetworkId, const float& forceCloseDistance) : Object() {
	init(rootPage, targetNetworkId, forceCloseDistance);
}

void SuiPageData::setProperty(const String& widget, const String& property, const UnicodeString& value) {
	SuiCommand* command = new SuiCommand(SuiCommand::SCT_setProperty);
	command->addWideParameter(value);
	command->addNarrowParameter(widget);
	command->addNarrowParameter(property);

	commands.add(command);
}

UnicodeString SuiPageData::getPropertyValue(const String& widget, const String& property) {
	UnicodeString value = "";

	for (int i = 0; i < commands.size(); i++) {
		SuiCommand* cmd = commands.get(i);

		if (cmd != nullptr && cmd->getCommandType() == SuiCommand::SCT_setProperty && cmd->getNarrowParameter(0) == widget && cmd->getNarrowParameter(1) == property)
			value = cmd->getWideParameter(0);
	}

	return value;
}

void SuiPageData::addDataItem(const String& widget, const String& property, const UnicodeString& value) {
	SuiCommand* command = new SuiCommand(SuiCommand::SCT_addDataItem);
	command->addWideParameter(value);
	command->addNarrowParameter(widget);
	command->addNarrowParameter(property);

	commands.add(command);
}

void SuiPageData::clearDataSource(const String& dataSource) {
	SuiCommand* command = new SuiCommand(SuiCommand::SCT_clearDataSource);
	command->addNarrowParameter(dataSource);

	commands.add(command);
}

void SuiPageData::addDataSourceContainer(const String& parent, const String& name) {
	SuiCommand* command = new SuiCommand(SuiCommand::SCT_addDataSourceContainer);
	command->addNarrowParameter(parent);
	command->addNarrowParameter(name);

	commands.add(command);
}

void SuiPageData::clearDataSourceContainer(const String& dataSourceContainer) {
	SuiCommand* command = new SuiCommand(SuiCommand::SCT_clearDataSourceContainer);
	command->addNarrowParameter(dataSourceContainer);

	commands.add(command);
}

void SuiPageData::addChildWidget(const String& parent, const String& type, const String& name) {
	SuiCommand* command = new SuiCommand(SuiCommand::SCT_addChildWidget);
	command->addNarrowParameter(parent);
	command->addNarrowParameter(type);
	command->addNarrowParameter(name);

	commands.add(command);
}

void SuiPageData::subscribeToEvent(const byte& eventType, const String& parent, const String& callback) {
	if (callbacks.contains(eventType))
		callbacks.drop(eventType);

	SuiCommand* command = new SuiCommand(SuiCommand::SCT_subscribeToEvent);
	command->addNarrowParameter(parent);

    StringBuffer eventTypeBuffer;
    eventTypeBuffer.append((char)eventType);

    command->addNarrowParameter(eventTypeBuffer.toString());
	command->addNarrowParameter(callback);

	callbacks.put(eventType, command);
	commands.add(command);
}

void SuiPageData::subscribeToPropertyForEvent(const byte& eventType, const String& widget, const String& property) {
	Reference<SuiCommand*> command = callbacks.get(eventType);

	if (command == nullptr) {
		warning("Attempted to add properties for event without subscribing a callback first.");
		return;
	}

	command->addNarrowParameter(widget);
	command->addNarrowParameter(property);
}

bool SuiPageData::toBinaryStream(ObjectOutputStream* stream) {
	stream->writeInt(id);
	rootPage.toBinaryStream(stream);
	stream->writeInt(commands.size());

	for (int i = 0; i < commands.size(); ++i)
		commands.get(i)->toBinaryStream(stream);

	stream->writeLong(targetNetworkId);
	stream->writeFloat(forceCloseDistance);
	stream->writeLong(unknownNetworkId);

	return true;
}

bool SuiPageData::parseFromBinaryStream(ObjectInputStream* stream) {
	id = stream->readInt();
	rootPage.parseFromBinaryStream(stream);

	int size = stream->readInt();

	for (int i = 0; i < size; ++i) {
		SuiCommand* command = new SuiCommand();
		command->parseFromBinaryStream(stream);

		if (command->getCommandType() == SuiCommand::SCT_subscribeToEvent) {
			//callbacks.put(); //TODO: Register subscribes again...
		}

		commands.add(command);
	}

	targetNetworkId = stream->readLong();
	forceCloseDistance = stream->readFloat();
	unknownNetworkId = stream->readLong();

	return true;
}

void SuiPageData::sendTo(CreatureObject* creo) {
	PlayerObject* playerObject = creo->getPlayerObject();

	if (playerObject != nullptr) {
		creo->getClient()->sendMessage(new SuiCreatePageMessage(this));
	}
}

void SuiPageData::sendUpdateTo(CreatureObject* creo) {
	PlayerObject* playerObject = creo->getPlayerObject();
	auto client = creo->getClient();

	if (playerObject != nullptr && client != nullptr) {
		client->sendMessage(new SuiUpdatePageMessage(this));
	}
}

void SuiPageData::setStoredData(const String& key, const String& value) {
	if (storedData.contains(key))
		storedData.drop(key);

	storedData.put(key, value);
}

void SuiPageData::deleteStoredData(const String& key) {
	storedData.drop(key);
}

String SuiPageData::getStoredData(const String& key) {
	if (!storedData.contains(key))
		return "";

	return storedData.get(key);
}

void SuiPageData::setPageId(int pageId) {
	id = pageId;
}

int32 SuiPageData::getPageId() {
	return id;
}

void SuiPageData::setForceCloseDistance(float dist) {
	forceCloseDistance = dist;
}

float SuiPageData::getForceCloseDistance() {
	return forceCloseDistance;
}

void SuiPageData::setTargetNetworkId(uint64 id) {
	targetNetworkId = id;
}

SuiCommand* SuiPageData::getCommand(int index) {
	return commands.get(index);
}

uint64 SuiPageData::getTargetNetworkId() {
	return targetNetworkId;
}

String& SuiPageData::getRootPage() {
	return rootPage;
}

void SuiPageData::init(const String& rootPage, const uint64& targetNetworkId, const float& forceCloseDistance) {
	this->id = 0;

	this->rootPage = rootPage;
	this->targetNetworkId = targetNetworkId;
	this->forceCloseDistance = forceCloseDistance;
	this->unknownNetworkId = 0;
}