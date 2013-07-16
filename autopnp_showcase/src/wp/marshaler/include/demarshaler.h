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
 *
 * \brief  Waypoint that demarshals topic data.
 *
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

#ifndef _WP_DEMARSHALER_H
#define _WP_DEMARSHALER_H

/**
 * \defgroup wp_demarshal Demarshaling waypoint.
 * @{
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/component.h"
#include "xme/core/dataManagerTypes.h"

#include "xme/wp/waypoint.h"

#include <stdbool.h>
#include <stdint.h>

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/
XME_EXTERN_C_BEGIN

/**
 * \brief  Initialize this waypoint.
 *
 * \retval XME_STATUS_SUCCESS if the waypoint has been initialized successfully.
 * \retval XME_STATUS_INTERNAL_ERROR if an error occurred.
 */
xme_status_t
_wp_demarshaler_init(void);

/**
 * \brief  Execute this waypoint.
 *
 * \details Before calling this, you must once add a configuration for the given instanceId, via
 *          _wp_demarshaler_addConfig.
 *          Executing this function will get the marshaled data from the inputPort of the associated
 *          configuration and demarshal the data. The result will be written to the output port of
 *          the associated configuration.
 *
 * \param  instanceId Id of the configuration for which to execute the waypoint, as returned by
 *                    _wp_marshaler_addConfig.
 *
 * \retval XME_STATUS_SUCCESS if the demarshaling was performed successfully.
 * \retval XME_STATUS_INVALID_HANDLE if no configuration has been added for the given
 *         instanceId.
 * \retval XME_STATUS_INTERNAL_ERROR if there was an error reading from the input port
 *         or writing to the output port. When this value is returned the output port value
 *         must be considered invalid.
 */
xme_status_t
_wp_demarshaler_run
(
	xme_wp_waypoint_instanceId_t instanceId
);

/**
 * \brief  Add a new configuration for this waypoint.
 *
 * \param  instanceId Pointer where id for the newly added configuration is written to.
 *                    Only valid when XME_STATUS_SUCCESS has been returned, else undefined.
 * \param  topic      Topic of the data that is stored at inputPort.
 * \param  inputPort  Port identifier for the input port.
 *                    Denotes where the marshaled topic data is located at.
 *                    No check is performed whether the port is valid.
 * \param  outputPort Port identifier for the output port.
 *                    Denotes the port where the demarshaled data will be written to.
 *                    No check is performed whether the port is valid.
 *
 * \retval XME_STATUS_SUCCESS if the configuration has been added successfully.
 * \retval XME_STATUS_OUT_OF_RESOURCES if the configuration could not be added due
 *         to resource constraints (e.g. not enough memory to store entry).
 * \retval XME_STATUS_INVALID_PARAMETER if the given topic is not supported by this marshaler.
 */
xme_status_t
_wp_demarshaler_addConfig
(
	xme_wp_waypoint_instanceId_t* instanceId,
	xme_core_topic_t topic,
	xme_core_dataManager_dataPacketId_t inputPort,
	xme_core_dataManager_dataPacketId_t outputPort
);

/**
 * \brief  Checks whether a given topic can be handled by this demarshaler.
 *
 * \param  topic Topic to check.
 *
 * \return True when the given topic can be handled by this demarshaler, else false.
 */
bool
_wp_demarshaler_isSupported
(
	xme_core_topic_t topic
);

/**
 * \brief  Finalize this waypoint.
 *
 * \retval XME_STATUS_SUCCESS if the waypoint has been finalized successfully.
 * \retval XME_STATUS_INTERNAL_ERROR if an error occurred.
 */
xme_status_t
_wp_demarshaler_fini(void);

XME_EXTERN_C_END

/**@}*/

#endif // #ifndef _WP_DEMARSHALER_H
