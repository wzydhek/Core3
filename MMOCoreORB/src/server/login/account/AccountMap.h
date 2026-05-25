/*
 * AccountMap.h
 *
 *  Created on: Oct 14, 2010
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace login {
namespace account {

	class AccountMap : public VectorMap<uint32, ManagedReference<Account*> >, public ReadWriteLock {

	public:
		AccountMap() : VectorMap<uint32, ManagedReference<Account*> >(), ReadWriteLock("AccountMap") {
			setInsertPlan(VectorMap<uint32, ManagedReference<Account*> >::NO_DUPLICATE);
			setNullValue(nullptr);
		}
	};

}
}
}
