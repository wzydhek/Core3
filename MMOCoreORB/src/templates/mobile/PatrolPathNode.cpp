#include "PatrolPathNode.h"

PatrolPathNode::PatrolPathNode() {
	cellid = 0;
	pause = 0;
}

PatrolPathNode::PatrolPathNode(const PatrolPathNode& node) : Object() {
	id = node.id;
	link = node.link;
	position = node.position;
	cellid = node.cellid;
	command = node.command;
	arguments = node.arguments;
	pause = node.pause;
}

PatrolPathNode& PatrolPathNode::operator=(const PatrolPathNode& node) {
	if (this == &node)
		return *this;

	id = node.id;
	link = node.link;
	position = node.position;
	cellid = node.cellid;
	command = node.command;
	arguments = node.arguments;
	pause = node.pause;

	return *this;
}

void PatrolPathNode::readObject(LuaObject* luaObject) {
	id = luaObject->getStringField("id");
	link = luaObject->getStringField("link");
	position.set(luaObject->getFloatField("x"), luaObject->getFloatField("z"), luaObject->getFloatField("y"));
	cellid = luaObject->getIntField("cellid");
	pause = luaObject->getIntField("pause");
	command = luaObject->getStringField("command");
	arguments = luaObject->getStringField("arguments");
}

String PatrolPathNode::getArguments() const {
	return arguments;
}

uint32 PatrolPathNode::getCellid() const {
	return cellid;
}

String PatrolPathNode::getCommand() const {
	return command;
}

String PatrolPathNode::getId() const {
	return id;
}

Vector3 PatrolPathNode::getPosition() const {
	return position;
}

void PatrolPathNode::setArguments(const String& arguments) {
	this->arguments = arguments;
}

void PatrolPathNode::setCellid(uint32 cellid) {
	this->cellid = cellid;
}

void PatrolPathNode::setCommand(const String& command) {
	this->command = command;
}

void PatrolPathNode::setId(String id) {
	this->id = id;
}

void PatrolPathNode::setPosition(Vector3 position) {
	this->position = position;
}