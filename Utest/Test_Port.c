#include "unity.h"
#include "Std_Types.h"
#include "Registers.h"

#define PORT_NUMBER_OF_PORT_PINS  1u
#define PORT_A0 0x00
#include "Port.h"

const Port_ConfigType ConfigArray[ PORT_NUMBER_OF_PORT_PINS ] =
{
{ .PortPinName        = PORT_A0,
  .PortPinInitialMode = PORT_PIN_MODE_DIO,
  .PortPinDirection   = PORT_PIN_IN,
  .PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
  .PortPinResistor    = PORT_PIN_NOPULL,
  .PortPinSpeed       = PORT_PIN_SPEED_LOW,
  .PortPinOuputDrive  = PORT_PIN_PUSH_PULL 
  } 
};

void test__Port_Init__dio_input(void)
{
    Port_Init( ConfigArray );

    TEST_ASSERT_EQUAL_HEX32_MESSAGE( 0x00000000, GPIOA->MODER, "" );
}

int main( void )
{
    UNITY_BEGIN( );
    RUN_TEST( test__Port_Init__dio_input );
    
    return UNITY_END( );
}

void setUp( void )
{
}

void tearDown( void )
{
}
