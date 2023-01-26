#include "unity.h"
#include "Std_Types.h"
#include "Registers.h"

#include "Bfx_bit8.h"
#include "Bfx_bit32.h"

#define PORT_NUMBER_OF_PORT_PINS 1u
#define PORT_A0                  0x00

Port_RegisterType GPIOA_BASE = { 0xEBFFFFFF, 0x00, 0x0C000000, 0x24000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType GPIOB_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType GPIOC_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType GPIOD_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType GPIOE_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType GPIOF_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };

Port_RegisterType *GPIOA = &GPIOA_BASE;
Port_RegisterType *GPIOB = &GPIOB_BASE;
Port_RegisterType *GPIOC = &GPIOC_BASE;
Port_RegisterType *GPIOD = &GPIOD_BASE;
Port_RegisterType *GPIOE = &GPIOE_BASE;
Port_RegisterType *GPIOF = &GPIOF_BASE;

#include "Port.h"

const Port_ConfigType ConfigArray[ PORT_NUMBER_OF_PORT_PINS ] =
{
{ .PortPinName        = PORT_A0,
  .PortPinInitialMode = PORT_PIN_MODE_DIO,
  .PortPinDirection   = PORT_PIN_IN,
  .PortPinLevelValue  = 0,
  .PortPinResistor    = 0,
  .PortPinSpeed       = 0,
  .PortPinOuputDrive  = 0 } };

void setUp( void )
{
}

void tearDown( void )
{
}

void test__Port_Init__dio_input( void )
{
    Port_Init( ConfigArray );

    TEST_ASSERT_EQUAL_HEX32_MESSAGE( GPIOA->MODER, 0xEBFFFFFC, "MODER register is not 0xEBFFFFFC as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( GPIOA->PUPDR, 0x24000000, "PUPDR register is not 0x00000000 as suposed to be" );
}
