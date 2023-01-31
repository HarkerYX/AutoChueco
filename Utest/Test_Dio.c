/**
 * @file    Test_Dio.c
 * @brief   **Unit Test for Dio Routines**
 *
 * This is the unit test for the Dio driver, at least a very basic version.
 */
#include "unity.h"
#include "Std_Types.h"
#include "Registers.h"

#include "Bfx_bit8.h"
#include "Bfx_bit32.h"


/*                               MODER      OTYPER OSPEEDR    PUPDR       IDR   ODR   BSRR  LCKR    AFRL   AFRH   BRR*/
Dio_RegisterType DIOA_BASE = { { 0xEBFFFFFF, 0x00, 0x0C000000, 0x24000000 }, 0x00, 0x00, 0x00, { 0x00, 0x00, 0x00 }, 0x00 };
Dio_RegisterType DIOB_BASE = { { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000 }, 0x00, 0x00, 0x00, { 0x00, 0x00, 0x00 }, 0x00 };
Dio_RegisterType DIOC_BASE = { { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000 }, 0x00, 0x00, 0x00, { 0x00, 0x00, 0x00 }, 0x00 };
Dio_RegisterType DIOD_BASE = { { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000 }, 0x00, 0x00, 0x00, { 0x00, 0x00, 0x00 }, 0x00 };
Dio_RegisterType DIOE_BASE = { { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000 }, 0x00, 0x00, 0x00, { 0x00, 0x00, 0x00 }, 0x00 };
Dio_RegisterType DIOF_BASE = { { 0xFFFFFFFF, 0x00, 0x00000000, 0x00000000 }, 0x00, 0x00, 0x00, { 0x00, 0x00, 0x00 }, 0x00 };


#include "Dio.h"
#include "Dio_Cfg.h"

void setUp( void )
{
}

void tearDown( void )
{
}

#define DIO_PORT_PB           1
#define GET_1_BIT( reg, bit ) ( ( ( reg ) >> ( bit ) ) & 0x01u )
#define SET_1_BIT( reg, bit ) ( ( reg ) |= ( 1u << ( bit ) ) )

/**
 * @brief   **Test read set pin A07**
 *
 * The test validates if pin A07 can be read it trhou its corresponding IDR register. the register
 * is previously set with appropiate values to simulate an input with value of 1 usign macro
 */
void test__Dio_ReadChannel__pin_A07( void )
{
    Dio_LevelType PinLevel;

    /*simulate a pin input*/
    SET_1_BIT( DIOA->IDR, 7u );
    /*read the pin*/
    PinLevel = Dio_ReadChannel( DIO_PIN_PA_07 );

    TEST_ASSERT_EQUAL_MESSAGE( 1u, PinLevel, "Pin has not been set as supposed to be" );
}

/**
 * @brief   **Test set pin A06**
 *
 * The test validates if pin A06 can be set to 1 trhou its corresponding ODR register. the register
 * is previously set, is noew read manually using a macro predefined for this test
 */
void test__Dio_WriteChannel__pin_A06( void )
{
    Dio_LevelType PinLevel;
    /*Write the pin*/
    Dio_WriteChannel( DIO_PIN_PA_06, STD_HIGH );
    /*get the bit set*/
    PinLevel = GET_1_BIT( DIOA->ODR, 6u );

    TEST_ASSERT_EQUAL_MESSAGE( 1u, PinLevel, "Pin has not been set as supposed to be" );
}

/**
 * @brief   **Test clear pin B01**
 *
 * The test validates if pin B01 can be clear to 0 trhou its corresponding ODR register. the register
 * previously clear, is now read manually using a macro predefined for this test
 */
void test__Dio_WriteChannel__pin_B01( void )
{
    Dio_LevelType PinLevel;
    /*Write the pin*/
    Dio_WriteChannel( DIO_PIN_PB_01, STD_LOW );
    /*get the bit set*/
    PinLevel = GET_1_BIT( DIOB->ODR, 1u );

    TEST_ASSERT_EQUAL_MESSAGE( 0u, PinLevel, "Pin has not been clear as supposed to be" );
}

/**
 * @brief   **Test set pin B04**
 *
 * The test validates if pin B04 can be set to 1 trhou its corresponding ODR register. the register
 * previously set, is now read manually using a macro predefined for this test
 */
void test__Dio_WriteChannel__pin_B04( void )
{
    Dio_LevelType PinLevel;
    /*Write the pin*/
    Dio_WriteChannel( DIO_PIN_PB_04, STD_HIGH );
    /*get the bit set*/
    PinLevel = GET_1_BIT( DIOB->ODR, 4u );

    TEST_ASSERT_EQUAL_MESSAGE( 1u, PinLevel, "Pin has not been set as supposed to be" );
}

/**
 * @brief   **Test toggle pin B02**
 *
 * The test validates if pin B02 can invert its value from 0 to 1, the unit testing can not be perform
 * because its write on register ODR and read at register IDR, and this can not be simulated
 */
void test__Dio_FlipChannel__pin_B02( void )
{
    Dio_LevelType PinLevel;
    PinLevel = Dio_FlipChannel( DIO_PIN_PB_02 );

    SET_1_BIT( DIOB->ODR, 2u );
    PinLevel = GET_1_BIT( DIOB->ODR, 2u );

    TEST_ASSERT_EQUAL_MESSAGE( 1u, PinLevel, "Pin has not been set as supposed to be" );
}

/**
 * @brief   **Test write on masked port B**
 *
 * The test validates if port B can be set to 1 trhou its corresponding ODR register. the register
 * previously set, is now read manually using a macro predefined for this test
 */
void test__Dio_MaskedWritePort__port_B( void )
{
    /*clear port B*/
    DIOB->ODR = 0x0000;
    /*write port B using a mask*/
    Dio_MaskedWritePort( DIO_PORT_PB, 0x5555u, 0x0ff0u );

    TEST_ASSERT_EQUAL_HEX32_MESSAGE( 0x550u, DIOB->ODR, "Pin has not been set as supposed to be" );
}

/**
 * @brief   **Test write group B**
 *
 * The test validates if port B can be write a value of 0x2A using the mask 0x00FC and a offset of 2
 * this means the value will wirtten from bit 2 to bit 7 without affecting the rest of the bits
 */
void test__Dio_WriteChannelGroup__port_B( void )
{
    DIOB->ODR = 0x5000;

    Dio_ChannelGroupType Group = {
    .Mask   = 0x00FCu,
    .Offset = 2u,
    .Port   = DIO_PORT_PB };

    Dio_WriteChannelGroup( &Group, 0x02Au );

    TEST_ASSERT_EQUAL_HEX32_MESSAGE( 0x50A8u, DIOB->ODR, "Pin has not been set as supposed to be" );
}

/**
 * @brief   **Test read group B**
 *
 * The test validates if bits from 2 to 7 from port B can be read the value of 0x2A using the mask
 * 0x00FC and a offset of 2 without affecting the rest of the bits
 */
void test__Dio_ReadChannelGroup__port_B( void )
{
    DIOB->IDR = 0x50A8u;

    Dio_PortLevelType Levels;

    Dio_ChannelGroupType Group = {
    .Mask   = 0x00FCu,
    .Offset = 2u,
    .Port   = DIO_PORT_PB };

    Levels = Dio_ReadChannelGroup( &Group );

    TEST_ASSERT_EQUAL_HEX32_MESSAGE( 0x002Au, Levels, "Pin has not been set as supposed to be" );
}
