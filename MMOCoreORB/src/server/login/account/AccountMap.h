/*
 * AccountMap.h
 *
 *  Created on: Oct 14, 2010
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"
#include "server/login/account/Account.h"

namespace server {
namespace login {
namespace account {

	class AccountMap : public VectorMap<uint32, ManagedReference<Account*> >, public ReadWriteLock {

	public:
		AccountMap();
	};

}
}
}
