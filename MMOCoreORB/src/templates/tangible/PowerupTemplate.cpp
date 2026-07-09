#include "PowerupTemplate.h"

PowerupTemplate::PowerupTemplate() {
}

PowerupTemplate::~PowerupTemplate() {
}

PowerupStat PowerupTemplate::getRandomPrimaryAttribute() {
	return primaryAttributes.get(System::random(primaryAttributes.size() - 1));
}

bool PowerupTemplate::hasPrimaryAttribute() {
	return primaryAttributes.size() > 0;
}

Vector<PowerupStat> PowerupTemplate::getSecondaryAttributes() {
	return secondaryAttributes;
}

int PowerupTemplate::getTotalSecondaryAttributes() {
	return secondaryAttributes.size();
}

bool PowerupTemplate::hasSecondaryAttribute() {
	return secondaryAttributes.size() > 0;
}

String& PowerupTemplate::getBaseName() {
	return baseName;
}

String& PowerupTemplate::getType() {
	return pupType;
}

void PowerupTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	lua_State* L = templateData->getLuaState();

	if (!templateData->isValidTable()) {
		return;
	}

	lua_pushnil(L);
	while (lua_next(L, -2) != 0) {
		int type = lua_type(L, -2);

		if (type == LUA_TSTRING) {
			size_t len = 0;
			const char* varName = lua_tolstring(L, -2, &len);

			parseVariableData(varName, templateData);
		} else
			lua_pop(L, 1);
	}
}

void PowerupTemplate::parseVariableData(const String& varName, LuaObject* data) {
	lua_State* state = data->getLuaState();

	if (varName == "primary") {
		primaryAttributes.removeAll();
		LuaObject primary(state);
		for (int i = 1; i <= primary.getTableSize(); ++i) {
			lua_rawgeti(state, -1, i);
			LuaObject mod(state);

			String attributeToMod = mod.getStringAt(1);
			String name = mod.getStringAt(2);
			String pupAttrib = mod.getStringAt(3);

			PowerupStat stat(attributeToMod, name, pupAttrib);

			primaryAttributes.add(stat);

			mod.pop();
		}
		data->pop();
	} else if (varName == "secondary") {
		secondaryAttributes.removeAll();
		LuaObject secondary(state);
		for (int i = 1; i <= secondary.getTableSize(); ++i) {
			lua_rawgeti(state, -1, i);
			LuaObject mod(state);

			String attributeToMod = mod.getStringAt(1);
			String name = mod.getStringAt(2);
			String pupAttrib = mod.getStringAt(3);

			PowerupStat stat(attributeToMod, name, pupAttrib);

			secondaryAttributes.add(stat);

			mod.pop();
		}
		data->pop();
	} else if (varName == "baseName") {
		baseName = Lua::getStringParameter(state);

	} else if (varName == "pupType") {
		pupType = Lua::getStringParameter(state);

	} else {
		data->pop();
	}
}