/*
 * ObjectController.cpp
 *
 *  Created on: Sep 6, 2009
 *      Author: theanswer
 */

#include "ObjectController.h"

#include "zone/Zone.h"
#include "zone/objects/scene/SceneObject.h"

#include "zone/packets/object/ObjectControllerMessage.h"

ObjectController::ObjectController(Zone* zn) {
	zone = zn;
}

