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


/**
 * @brief   Data type for the symbolic name of a port pin.
 *
 * The value is segmented in two parts, th emost significan bytes indicate the Mcu Port while the
 * les significant bytes indicate the pin assigned (values from 0 - 15).
 */
typedef uint32 Port_PinType;

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
 * @brief  Possible pin configuration modes.
 *
 * Potential pin modes to configure each pin, by default each pin is configured in ADC mode
 * for power saving
 */
typedef enum Port_PinModesType_Tag
{
    PORT_PIN_MODE_ADC = 0u,
    PORT_PIN_MODE_CAN,
    PORT_PIN_MODE_DIO,
    PORT_PIN_MODE_DIO_GPT,
    PORT_PIN_MODE_DIO_WDG,
    PORT_PIN_MODE_FLEXRAY,
    PORT_PIN_MODE_ICU,
    PORT_PIN_MODE_LIN,
    PORT_PIN_MODE_MEM,
    PORT_PIN_MODE_PWM,
    PORT_PIN_MODE_SPI
} Port_PinModesType;

/**
 * @brief  Different port pin modes
 *
 * The type holds the pin functionality adopted or to adopt, it is limited by the microcontroller
 * itself since no each pin support all functionalities. The potential values to adopt are listed
 * in #Port_PinModesType enum
 */
typedef uint32 Port_PinModeType;

/**
 * @brief  Type of the external data structure containing the initialization data for this module.
 *
 * Each pin available in the microcontroller shall be assigned this structur, an array with the
 * initial values must be defined in the Port_Cfg.c file
 */
typedef struct Port_ConfigType_Tag
{
    Port_PinType PortPinName;               /**< Pin name assigned with port and pin information embedded*/
    Port_PinModeType PortPinInitialMode;    /**< The fucntional mode wich will be configured */
    Port_PinDirectionType PortPinDirection; /**< If config as GPIO set direction as input or output */
    uint8 PortPinLevelValue;                /**< Initial pin digital level value if applicable*/
    uint8 PortPinResistor;                  /**< Internal resistor configuration, pullup, pulldown or none */
    uint8 PortPinSpeed;                     /**< Pin frequency configuration */
    uint8 PortPinOuputDirve;                /**< Pin as push-pull or open collector */
} Port_ConfigType;

void Port_Init( const Port_ConfigType *ConfigPtr );
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
void Port_RefreshPortDirection( void );
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );

#endif /* PORT_H */
