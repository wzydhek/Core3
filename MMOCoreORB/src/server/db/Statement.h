/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#pragma once

#include "system/lang.h"

namespace server {
  namespace db {
    namespace mysql {

	#define quote '\''

  	class Statement {
  		char* data;

  	public:
  		Statement();

	};

    } // namespace mysql
  } // namespace db
} // namespace engine

using namespace server::db::mysql;
