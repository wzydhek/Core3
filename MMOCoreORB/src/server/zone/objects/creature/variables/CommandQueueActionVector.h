/*
 * CommandQueueActionVector.h
 *
 *  Created on: May 30, 2011
 *      Author: theanswer
 */

#pragma once

#include "engine/engine.h"
#include "CommandQueueAction.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace variables {

template <class O>
class CommandReference : public Reference<O> {
public:
	CommandReference() : Reference<O>() {

	}

	CommandReference(const CommandReference& ref) : Reference<O>(ref) {

	}

	CommandReference(O obj) : Reference<O>(obj) {

	}

	CommandReference& operator=(const CommandReference& val) {
		if (this == &val) {
			return *this;
		}

		Reference<O>::operator=(val);

		return *this;
	}

	int compareTo(const CommandReference& val) const {
		return Reference<O>::get()->compareTo(val.get());
	}

};

class CommandQueueActionVector : public SortedVector<CommandReference<CommandQueueAction*> > {
public:
	CommandQueueActionVector();

	CommandQueueActionVector(const CommandQueueActionVector& v);

	CommandQueueActionVector& operator=(const CommandQueueActionVector& v);

	Object* clone();

	Object* clone(void* object);
};

} // namespace variables
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::variables;
