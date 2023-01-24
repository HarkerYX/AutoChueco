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
#include "Registers.h"
#include "Port.h"
#include "Port_Cfg.h"
#include "Bfx.h"

#ifndef PORT_NUMBER_OF_PORT_PINS
#define PORT_NUMBER_OF_PORT_PINS 0u
#endif

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
    uint8 Pins;
    uint8 Port;
    uint8 Pin;
    Port_RegisterType *PortsBaseAddr = GPIOA;

    /*Roll over all hte pins to configure*/
    for( Pins = 0u; Pins < PORT_NUMBER_OF_PORT_PINS; Pins++ )
    {
        /* Get the pin to configure */
        Pin = ConfigPtr[ Pins ].PortPinName;
        Bfx_ClrBitMask_u8u8( &Pin, 0xf0u );
        /* Get the port where the pin to configure is set */
        Port = ConfigPtr[ Pins ].PortPinName;
        Bfx_ShiftBitRt_u8u8( &Port, 4u );

        switch( ConfigPtr[ Pins ].PortPinInitialMode )
        {
            case PORT_PIN_MODE_DIO:
                /* Set direction */
                Bfx_PutBits_u32u8u8u32( (uint32 *)&PortsBaseAddr[ Port ].MODER, ( Pin << 2u ), 2u, ConfigPtr[ Pins ].PortPinDirection );
                /* Set Resistor */
                Bfx_PutBits_u32u8u8u32( (uint32 *)&PortsBaseAddr[ Port ].PUPDR, ( Pin << 2u ), 2u, ConfigPtr[ Pins ].PortPinResistor );

                if( ConfigPtr[ Pins ].PortPinDirection == PORT_PIN_OUT )
                {
                    /* Set Speed */
                    Bfx_PutBits_u32u8u8u32( (uint32 *)&PortsBaseAddr[ Port ].OSPEEDR, ( Pin << 2u ), 2u, ConfigPtr[ Pins ].PortPinSpeed );
                    /* Set OutputDriver (if output) */
                    Bfx_PutBit_u32u8u8( (uint32 *)&PortsBaseAddr[ Port ].OTYPER, Pin, ConfigPtr[ Pins ].PortPinOuputDrive );
                    /* Set intial value (if output)*/
                    Bfx_PutBit_u32u8u8( (uint32 *)&PortsBaseAddr[ Port ].ODR, Pin, ConfigPtr[ Pins ].PortPinLevelValue );
                }
                break;

            default:
                break;
        }
    }
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
    uint8 PortPin                    = Pin;
    uint8 Port                       = Pin;
    Port_RegisterType *PortsBaseAddr = GPIOA;

    /* Get the pin to configure */
    Bfx_ClrBitMask_u8u8( &PortPin, 0xf0u );
    /* Get the port where the pin to configure is set */
    Bfx_ShiftBitRt_u8u8( &Port, 4u );
    /*Set the new direction into the appropiate Mcu register*/
    Bfx_PutBits_u32u8u8u32( (uint32 *)&PortsBaseAddr[ Port ].MODER, ( Pin << 2u ), 2u, Direction );
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
