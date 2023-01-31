/**
 * @file    Dio.h
 * @brief   **Specification of Dio Driver**
 *
 * This specification specifies the functionality, API and the configuration of the AUTOSAR Basic
 * Software module DIO Driver. This specification is applicable to drivers only for on chip DIO
 * pins and ports. The DIO Driver provides services for reading and writing to/from.
 *   - DIO Channels (Pins)
 *   - DIO Ports
 *   - DIO Channel Groups The behavior of those services is synchronous.
 *
 * This module works on pins and ports which are configured by the PORT driver for this purpose.
 * For this reason, there is no configuration and initialization of this port structure in the DIO Driver
 */
#ifndef DIO_H
#define DIO_H

#include "Dio_Defines.h"

/**
 * @brief  Defines the Dio_ChannelType data type.
 *
 * The Dio_ChannelType data type contains the numeric ID of a DIO channel. The less significan bits
 * indicate pin while the most significan bits indicates Mcu Port. The Dio's user must use the
 * symbolic names provided by the configuration description in file Dio_Cfg.h to specify the parameter
 * values of type Dio_ChannelType.
 */
typedef uint8 Dio_ChannelType;

/**
 * @brief  Numeric ID of a DIO port
 *
 * The Dio's user must use the symbolic names provided by the configuration description in file
 * Dio_Cfg.h
 */
typedef uint8 Dio_PortType;


/**
 * @brief  Type for the definition of a channel group,
 *
 * A channel group is a formal logical combination of several adjoining DIO channels within a DIO port
 */
typedef struct Dio_ChannelGroupType_Tag
{
    uint32 Mask; /**< This element mask which defines the positions of the channel group */

    uint32 Offset; /**< This element shall be the position of the Channel Group on the port,
                        counted from the LSB */

    Dio_PortType Port; /**< This shall be the port on which the Channel group is defined. */
} Dio_ChannelGroupType;

/**
 * @brief  These are the possible levels a DIO channel can have (input or output)
 */
typedef uint8 Dio_LevelType;

/**
 * @brief   Defines the data that can be pass or read into a port
 *
 * The data type should be use every time a complete port should be written at once. If the μC owns
 * ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the
 * largest port.
 */
typedef uint32 Dio_PortLevelType;

/* cppcheck-suppress misra-c2012-20.1 ; it is necesary to include here after the Dio types definition */
#include "Dio_Cfg.h"

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId );
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType *ChannelGroupIdPtr );
void Dio_WriteChannelGroup( const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level );
void Dio_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask );

#endif /* DIO_H */
