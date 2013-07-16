/*
 * Copyright (c) 2011-2013, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id$
 */

/**
 * \file
 *         Component wrapper - implements interface of a component
 *              to the data handler
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "autopnp/adv/cleaningGui/include/cleaningGuiComponentWrapper.h"

#include "xme/core/component.h"
#include "xme/core/dataHandler/include/dataHandler.h"

/******************************************************************************/
/***   Type definitions                                                     ***/
/******************************************************************************/
/**
 * \enum   Defines constants used in this file.
 */
enum
{
	PORT_COUNT = 1 ///< Size of ports array.
};

/******************************************************************************/
/***   Static variables                                                     ***/
/******************************************************************************/
/**
 * \brief  Stores dataPacketIds for each port of this component.
 *         For the mapping of index to port see autopnp_adv_cleaningGui_cleaningGuiComponentWrapper_receivePort.
 *
 * \see    autopnp_adv_cleaningGui_cleaningGuiComponentWrapper_receivePort
 */
static xme_core_dataManager_dataPacketId_t ports[PORT_COUNT];

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
void
autopnp_adv_cleaningGui_cleaningGuiComponentWrapper_completeReadOperations(void)
{
	uint8_t portIndex;
	
	for (portIndex = 0; portIndex < PORT_COUNT; portIndex++)
	{
		xme_core_dataHandler_completeReadOperation(ports[portIndex]);
	}
}

xme_status_t
autopnp_adv_cleaningGui_cleaningGuiComponentWrapper_receivePort
(
	xme_core_dataManager_dataPacketId_t portId,
	autopnp_adv_cleaningGui_cleaningGuiComponentWrapper_interalPortId_t componentInternalPortId
)
{
	XME_CHECK
	(
		(autopnp_adv_cleaningGui_cleaningGuiComponentWrapper_interalPortId_t) PORT_COUNT > componentInternalPortId, 
		XME_STATUS_INVALID_PARAMETER
	);
	
	ports[componentInternalPortId] = portId;
 	
 	return XME_STATUS_SUCCESS;
}

xme_status_t
autopnp_adv_cleaningGui_cleaningGuiComponentWrapper_readPortImageIn
(
	autopnp_topic_image_t* data
)
{
	uint8_t portIndex;
	unsigned int bytesRead;
	xme_status_t returnValue;
	
	portIndex = 0;
	
	returnValue = xme_core_dataHandler_readData
	(
		ports[portIndex],
		(void*) data, 
		sizeof(autopnp_topic_image_t),
		&bytesRead
	);
    
    return returnValue;
}

