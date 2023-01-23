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
 * @brief  Initializes the Port Driver module.
 *
 * The function initialize ALL ports and port pins with the configuration set pointed to by the parameter
 * **ConfigPtr**, by default port will be configured in Analog mode
 *
 * @param  ConfigPtr Pointer to configuration set.
 */
void Port_Init( const Port_ConfigType *ConfigPtr )
{
    (void)ConfigPtr;
}


/**
 * @brief  Sets the port pin direction.
 *
 * Set or change the pin direction previously configured, this fucntion is only applicable when
 * the pin is configured as GPIO, however the function does not validate if the pin has a different
 * function
 *
 * @param  Pin Port Pin ID number
 * @param  Direction Port Pin direction
 */
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
    (void)Pin;
    (void)Direction;
}


/**
 * @brief  Refreshes port direction.
 *
 * he function Port_RefreshPortDirection shall refresh the direction of all configured ports to the
 * configured direction only if the pins are not are configured as ’pin direction changeable during
 * runtime
 */
void Port_RefreshPortDirection( void )
{
}


/**
 * @brief  Sets the port pin mode.
 *
 * The function Port_SetPinMode shall set the port pin mode of the referenced pin during runtime.
 *
 * @param  Pin Port Pin ID number
 * @param  Mode New Port Pin mode to be set on port pin
 *
 * @retval None
 */
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
    (void)Pin;
    (void)Mode;
}
