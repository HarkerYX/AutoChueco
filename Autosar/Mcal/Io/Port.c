/**
 * @file    Port.c
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
#include "Std_Types.h"
#include "Port.h"


/**
 * @brief   Initializes the Port Driver module with the configuration set pointed to by ConfigPtr.
 *
 * The function initializes all ports and port pins using the configuration set specified by the input 
 * parameter ConfigPtr. By default, each port pin will be configured in analog mode. The function will 
 * configure all the microcontroller pins defined on each port according to what was set by the 
 * configuration tool.
 *
 * @param[in]  ConfigPtr  Pointer to the configuration set to be used for initialization.
 *
 * @code
 *      Port_Init( &PortsConfiguration );
 * @endcode
 */
void Port_Init( const Port_ConfigType *ConfigPtr )
{
    (void)ConfigPtr;
}


/**
 * @brief  Sets the port pin direction.
 *
 * This function sets or changes the direction of a previously configured port pin. It is only applicable 
 * for pins configured as GPIO and if the DirectionChangeable flag for the pin is set to TRUE. However, 
 * the function does not perform any validation to check if the pin has the correct configuration.
 *
 * @param  Pin Pin Port pin identifier.
 * @param  Direction Direction Desired direction for the port pin.
 * 
 * @note The function does not perform any validation to ensure that the provided Pin parameter is 
 *      valid or that the direction change is allowed. The responsibility to ensure the validity of the 
 *      input lies with the caller.
 * 
 * @code
 *      Port_SetPinDirection( PORT_PIN_CHIP_SELECT, PORT_PIN_OUT );
 * @endcode
 */
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
    (void)Pin;
    (void)Direction;
}


/**
 * @brief  Refreshes the direction of all the configured ports.
 * 
 * This function updates the direction of all the ports to their configured direction, but only for
 * the pins that are not configured as changeable during runtime. The function ensures that the direction
 * of the port is updated to its intended state, especially after a system reset or power-up scenario.
 * 
 * @code
 *      Port_RefreshPortDirection( );
 * @endcode
 */
void Port_RefreshPortDirection( void )
{
}

/**
 * @brief  Sets the port pin mode.
 *
 * The function sets the mode of the specified pin during runtime, but only if the pin is configured
 * to allow mode changes at runtime. The new mode must be defined in the auto-generated file Port_Cfg.h,
 * otherwise unexpected behavior may occur.
 *
 * @param  Pin Port Pin ID number
 * @param  Mode New Port Pin mode to be set on port pin
 *
 * @code
 *      Port_SetPinMode( PORT_PIN_CHIP_SELECT, PORT_PIN_CHIP_SELECT_MODE_GPIO_OUT );
 * @endcode
 *      
 */
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
    (void)Pin;
    (void)Mode;
}
