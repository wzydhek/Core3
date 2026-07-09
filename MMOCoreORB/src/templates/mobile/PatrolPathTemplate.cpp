#include "PatrolPathTemplate.h"

PatrolPathTemplate::PatrolPathTemplate() {
	pathMap.setNoDuplicateInsertPlan();
}

PatrolPathTemplate::PatrolPathTemplate(const PatrolPathTemplate& tmp) : Object() {
	pathMap = tmp.pathMap;
}

PatrolPathTemplate& PatrolPathTemplate::operator=(const PatrolPathTemplate& tmp) {
	if (this == &tmp)
		return *this;

	pathMap = tmp.pathMap;

	return *this;
}

void PatrolPathTemplate::readObject(LuaObject* luaObject) {
	for (int i = 1; i <= luaObject->getTableSize(); ++i) {
		lua_rawgeti(luaObject->getLuaState(), -1, i);
		LuaObject node(luaObject->getLuaState());

		if (node.isValidTable()) {
			PatrolPathNode pathNode;
			pathNode.readObject(&node);

			pathMap.put(pathNode.getId(), pathNode);
		}

		node.pop();
	}
}