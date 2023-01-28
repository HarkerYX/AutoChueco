/**
 * @file    Port.h
 * @brief   **Specification of Port Driver**
 *
 * This PORT driver module shall complete the overall configuration and initialization of the port
 * structure which is used in the DIO driver module. Therefore, the DIO driver works on pins and
 * ports which are configured by the PORT driver.
 *
 * The PORT driver shall be initialized prior to the use of the DIO functions. Otherwise, DIO
 * functions will exhibit undefined behavior. The diagram below identifies the PORT driver functions
 * and the structure of the PORT driver and DIO driver within the MCAL software layer.
 */
#ifndef PORT_H
#define PORT_H

#include "Port_Defines.h"

/**
 * @brief   Data type for the symbolic name of a port pin.
 *
 * The value of this type is comprised of two parts, with the most significant bits indicating the
 * MCU port and the least significant bits indicating the assigned pin number (values ranging from
 * 0 to 15).
 */
typedef uint8 Port_PinType;

/**
 * @brief  Possible directions of a port pin when confired as Digital pins.
 *
 * The enum is only applicable when the Pin is configures as a digital pin
 */
typedef enum Port_PinDirectionType_Tag
{
    PORT_PIN_IN = 0u, /**< Indicates the pin is configured as digital input */
    PORT_PIN_OUT      /**< Indicates the pin is configured as digital output */
} Port_PinDirectionType;

/**
 * @brief   Data type for holding different port pin modes.
 *
 * This type holds the functionality adopted or to be adopted by the pin. The values are limited
 * by the capabilities of the microcontroller and the specific set of functions that each pin
 * supports. The value is comprised of two parts, with the most significant bits indicating the
 * pin mode (input/output, output, alternate, or analog) and the least significant bits indicating
 * the alternate function (values ranging from 0 to 7).
 */
typedef uint8 Port_PinModeType;

/**
 * @brief  Type of the external data structure containing the initialization data for this module.
 *
 * Each pin available in the microcontroller shall be assigned this structur, an array with the
 * initial values must be defined in the Port_Cfg.c file
 */
typedef struct Port_PortsConfigType_Tag
{
    uint8 PortNumber; /**< Pin name assigned with port and pin information embedded*/
    uint16 AvailablePins;
    uint32 PortPinInitialMode; /**< The fucntional mode wich will be configured */
    uint32 PortPinOuputDrive;  /**< Pin as push-pull or open collector */
    uint32 PortPinSpeed;       /**< Pin frequency configuration */
    uint32 PortPinLevelValue;  /**< Initial pin digital level value if applicable*/
    uint32 PortPinResistor;    /**< Internal resistor configuration, pullup, pulldown or none */
    uint32 PortPinAltH;
    uint32 PortPinAltL;
    uint16 DirectionChangeable;
    uint16 ModeChangeable;
} Port_PortsConfigType;

/**
 * @brief Definition of the external data structure containing the initialization data for the Port.
 *
 * The Port_PortsConfigType data structure holds the initialization information for each port available
 * on the microcontroller. An array of these structures must be defined in the Port_Cfg.c file, with
 * each entry representing a specific port.
 *
 * @note It is the responsibility of the user to ensure that the values defined in this structure are
 * valid and appropriate, as the Port Driver does not perform any validation. The values must be generated
 * and validated within the code generation tool.
 */
typedef struct Port_PortsConfigType_Tag
{
    uint8 PortNumber; /**< A microcontroller-specific port name assigned to each available
                          port, ranging from PORT_PA to PORT_PH.*/

    uint16 AvailablePins; /**< A bitwise representation of the implemented pins in the corresponding
                              microcontroller port, where each set bit indicates that the corresponding
                              pin is available.*/

    uint32 PortPinInitialMode; /**< The functional mode to be configured for each pin in the port,
                                   represented by two bits for each pin. The potential values are
                                   PORT_MODE_INPUT (00), PORT_MODE_OUTPUT (01), PORT_MODE_ALTERN (10),
                                   and PORT_MODE_ANALOG (11).*/

    uint32 PortPinOuputDrive; /**< The drive mode for the port pins, represented by a bit for each pin.
                                  The potential values are PORT_PUSH_PULL (0) and PORT_OPEN_COLECTOR (1).*/

    uint32 PortPinSpeed; /**< The frequency configuration for each pin in the port, represented
                             by two bits for each pin. The potential values are PORT_SPEED_FREQ_LOW (00),
                             PORT_SPEED_FREQ_MEDIUM (01), PORT_SPEED_FREQ_HIGH (10), and
                             PORT_SPEED_FREQ_VERY_HIGH (11) */

    uint32 PortPinLevelValue; /**< The initial digital level value for each pin in the port, represented
                                  by a bit for each pin. These values are only applicable when the port
                                  is configured as digital output.*/

    uint32 PortPinResistor; /**< The internal resistor configuration for each pin in the port, represented
                                by two bits for each pin. The potential values are PORT_RESISTOR_NOPULL (00),
                                PORT_RESISTOR_PULLUP (01), and PORT_RESISTOR_PULLDOWN (10)*/

    uint32 PortPinAltH; /**< The altern mode configuration for the most significant port pins,
                            represented by four bits for each pin and up to eight potential altern modes
                            that can be set, all of them microcontroller dependent.*/

    uint32 PortPinAltL; /**< The altern mode configuration for the most significant port pins,
                            represented by four bits for each pin and up to eight potential altern modes
                            that can be set, all of them microcontroller dependent.*/

    uint16 DirectionChangeable; /**< A bitwise representation of the port pins that can have their direction
                                    changed at runtime, where each set bit indicates that the corresponding
                                    pin direction can be changed.*/

    uint16 ModeChangeable; /**< A bitwise representation of the port pins that can have their mode
                               (and altern mode) changed at runtime, where each set bit indicates that
                               the corresponding pin mode can be changed.*/
} Port_PortsConfigType;

/**
 * @brief  Type of the external data structure containing the initialization data for this module.
 *
 * Each pin available in the microcontroller shall be assigned this structure, an array with the
 * initial values must be defined in the Port_Cfg.c file
 */
typedef struct Port_ConfigType_Tag
{
    uint8 PortNumbers;                 /**< the number of ports in the microcontroller*/
    Port_PortsConfigType *PortsConfig; /**< pointer to port configuration array*/
} Port_ConfigType;

/* cppcheck-suppress misra-c2012-20.1 ; it is necesary to include here after the Port_Config definition */
#include "Port_Cfg.h"

void Port_Init( const Port_ConfigType *ConfigPtr );
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
void Port_RefreshPortDirection( void );
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );

#endif /* PORT_H */
