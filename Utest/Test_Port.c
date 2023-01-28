#include "unity.h"
#include "Std_Types.h"
#include "Registers.h"

#include "Bfx_bit8.h"
#include "Bfx_bit32.h"


/*                               MODER      OTYPER OSPEEDR    PUPDR       IDR   ODR   BSRR  LCKR    AFRL   AFRH   BRR*/
Port_RegisterType PORTA_BASE = { 0xEBFFFFFF, 0x00, 0x0C000000, 0x24000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType PORTB_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType PORTC_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType PORTD_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType PORTE_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };
Port_RegisterType PORTF_BASE = { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000, 0x00, 0x00, 0x00, 0x00, { 0x00, 0x00 }, 0x00 };


#include "Port.h"
#include "Port_Cfg.h"

static Port_PortsConfigType testPortPortsConfig =
{
.PortNumber          = 0x00,
.AvailablePins       = 16,
.PortPinInitialMode  = 0xEBFFFFFF,
.PortPinOuputDrive   = 0x00000000,
.PortPinSpeed        = 0x0C000000,
.PortPinLevelValue   = 0x00000000,
.PortPinResistor     = 0x24000000,
.PortPinAltH         = 0x00000000,
.PortPinAltL         = 0x00000000,
.DirectionChangeable = 0x0000,
.ModeChangeable      = 0x0000 };

static Port_ConfigType testPortConfig =
{
.PortNumbers = 1u,
.PortsConfig = &testPortPortsConfig };

void setUp( void )
{
}

void tearDown( void )
{
}

#define PUT_4_BITS( var, pin, pat ) ( ( ( var ) & ~( 0x0f << ( ( pin ) << 4u ) ) ) | ( ( pat ) << ( ( pin ) << 4u ) ) )
#define PUT_2_BITS( var, pin, pat ) ( ( ( var ) & ~( 0x03 << ( ( pin ) << 2u ) ) ) | ( ( pat ) << ( ( pin ) << 2u ) ) )
#define PUT_1_BIT( var, pin, pat )  ( ( ( var ) & ~( 1u << ( pin ) ) ) | ( ( pat ) << ( pin ) ) )

#define SET_INITIAL_MODE            PUT_2_BITS
#define SET_OUTPUT_DRIVE            PUT_1_BIT
#define SET_SPEED                   PUT_2_BITS
#define SET_LEVEL                   PUT_1_BIT
#define SET_RESISTOR                PUT_2_BITS
#define SET_ALTH                    PUT_4_BITS
#define SET_ALTL                    PUT_4_BITS
#define SET_DC                      PUT_1_BIT
#define SET_MC                      PUT_1_BIT

/**
 * @brief **test Port Pin A00**
 *
 * the following test validates if the port pin A00 was configured correctly according to
 * the following configuration: Pin as output, pushpull, speed low, nopull, level high
 */
void test__Port_Init__port_A00( void )
{
    SET_INITIAL_MODE( testPortConfig.PortsConfig->PortPinInitialMode, 0u, PORT_MODE_INPUT );
    SET_OUTPUT_DRIVE( testPortConfig.PortsConfig->PortPinOuputDrive, 0u, PORT_PUSH_PULL );
    SET_SPEED( testPortConfig.PortsConfig->PortPinSpeed, 0u, PORT_SPEED_FREQ_LOW );
    SET_LEVEL( testPortConfig.PortsConfig->PortPinLevelValue, 0u, STD_LOW );
    SET_RESISTOR( testPortConfig.PortsConfig->PortPinResistor, 0u, PORT_RESISTOR_NOPULL );
    SET_ALTH( testPortConfig.PortsConfig->PortPinAltH, 0u, PORT_AF_DEFAULT );
    SET_ALTL( testPortConfig.PortsConfig->PortPinAltL, 0u, PORT_AF_DEFAULT );


    Port_Init( &testPortConfig );

    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinInitialMode, PORTA->MODER, "MODER register is not 0xEBFFFFFD as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinOuputDrive, PORTA->OTYPER, "PUPDR register is not 0x00000000 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinSpeed, PORTA->OSPEEDR, "PUPDR register is not 0x0C000000 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinResistor, PORTA->PUPDR, "PUPDR register is not 0x24000000 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinLevelValue, PORTA->ODR, "PUPDR register is not 0x00000001 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinAltH, PORTA->AFR[ 1u ], "PUPDR register is not 0x00000000 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinAltL, PORTA->AFR[ 0u ], "PUPDR register is not 0x00000000 as suposed to be" );
}

/**
 * @brief **test Port Pin A00**
 *
 * the following test validates if the port pin A00 was configured correctly according to
 * the following configuration: Pin as altern mode SPI2, pushpull, speed low, nopull
 */
void test__Port_Init__port_A00_altern( void )
{
    SET_INITIAL_MODE( testPortConfig.PortsConfig->PortPinInitialMode, 0u, PORT_MODE_ALTERN );
    SET_OUTPUT_DRIVE( testPortConfig.PortsConfig->PortPinOuputDrive, 0u, PORT_PUSH_PULL );
    SET_SPEED( testPortConfig.PortsConfig->PortPinSpeed, 0u, PORT_SPEED_FREQ_LOW );
    SET_LEVEL( testPortConfig.PortsConfig->PortPinLevelValue, 0u, STD_LOW );
    SET_RESISTOR( testPortConfig.PortsConfig->PortPinResistor, 0u, PORT_RESISTOR_NOPULL );
    SET_ALTH( testPortConfig.PortsConfig->PortPinAltH, 0u, PORT_AF_DEFAULT );
    SET_ALTL( testPortConfig.PortsConfig->PortPinAltL, 0u, GPIO_AF1_SPI2 );


    Port_Init( &testPortConfig );

    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinInitialMode, PORTA->MODER, "MODER register is not 0xEBFFFFFD as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinOuputDrive, PORTA->OTYPER, "PUPDR register is not 0x00000000 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinSpeed, PORTA->OSPEEDR, "PUPDR register is not 0x0C000000 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinResistor, PORTA->PUPDR, "PUPDR register is not 0x24000000 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinLevelValue, PORTA->ODR, "PUPDR register is not 0x00000001 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinAltH, PORTA->AFR[ 1u ], "PUPDR register is not 0x00000000 as suposed to be" );
    TEST_ASSERT_EQUAL_HEX32_MESSAGE( testPortConfig.PortsConfig->PortPinAltL, PORTA->AFR[ 0u ], "PUPDR register is not 0x00000000 as suposed to be" );
}


/**
 * @brief **test Port Pin A00**
 *
 * the following test validates if the port pin A00 chnage its direction to output
 */
void test__Port_SetPinDirection__output( void )
{
    Port_PinType Pin = 0x00;

    Port_SetPinDirection( Pin, PORT_PIN_OUT );

    TEST_ASSERT_EQUAL_HEX32_MESSAGE( 0xEBFFFFFD, PORTA->MODER, "MODER register is not 0xEBFFFFFD as suposed to be" );
}

/**
 * @brief **test Port Pin A00**
 *
 * the following test validates if the port pin A00 chnage its direction to input
 */
void test__Port_SetPinDirection__input( void )
{
    Port_PinType Pin = 0x00;

    Port_SetPinDirection( Pin, PORT_PIN_IN );

    TEST_ASSERT_EQUAL_HEX32_MESSAGE( 0xEBFFFFFC, PORTA->MODER, "MODER register is not 0xEBFFFFFD as suposed to be" );
}

