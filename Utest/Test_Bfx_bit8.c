/**
 * @file    Test_Bfx_bit8.c
 * @brief   **Unit Test for the 8 Bit Handling Routines**
 *
 * AUTOSAR Library routines are the part of system services in AUTOSAR architecture and below figure
 * shows position of AUTOSAR library in layered architecture.
 */
#include "unity.h"
#include "Std_Types.h"
#include "Bfx_bit8.h"

/**
 * @brief   **Test set bit 2**
 *
 * The test validates if bit 2 is set over a varible with value 0x00, to pass data tested should be
 * value 0x04.
 */
void test__Bfx_SetBit_u8u8__bit2( void )
{
    uint8 Data = 0u;
    Bfx_SetBit_u8u8( &Data, 2u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0x04, "Bit 2 was not set as supposed to be" );
}

/**
 * @brief   **Test set bit 7**
 *
 * The test validates if bit 7 is set over a varible with value 0x00, to pass data tested should be
 * value 0x80.
 */
void test__Bfx_SetBit_u8u8__bit7( void )
{
    uint8 Data = 0u;
    Bfx_SetBit_u8u8( &Data, 7u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0x80, "Bit 7 was not set as supposed to be" );
}

/**
 * @brief   **Test clear bit 2**
 *
 * The test validates if bit 2 is clear over a varible with value 0xFF, to pass data tested should be
 * value 0xFB.
 */
void test__Bfx_ClrBit_u8u8__bit2( void )
{
    uint8 Data = 0xFFu;
    Bfx_ClrBit_u8u8( &Data, 2u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0xFB, "Bit 2 was not clear as supposed to be" );
}

/**
 * @brief   **Test clear bit 7**
 *
 * The test validates if bit 7 is clear over a varible with value 0xFF, to pass data tested should be
 * value 0xEF.
 */
void test__Bfx_ClrBit_u8u8__bit7( void )
{
    uint8 Data = 0xFFu;
    Bfx_ClrBit_u8u8( &Data, 7u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0x7F, "Bit 2 was not clear as supposed to be" );
}

/**
 * @brief   **Test get bit 3**
 *
 * The test validates if we get bit 3 over a varible with value 0x8A, to pass the return value
 * should be TRUE.
 */
void test__Bfx_GetBit_u8u8_u8__true( void )
{
    uint8 Data  = 0x8Au;
    boolean Bit = Bfx_GetBit_u8u8_u8( Data, 3u );
    TEST_ASSERT_MESSAGE( Bit == TRUE, "Bit is not TRUE as supposed to be" );
}

/**
 * @brief   **Test get bit 4**
 *
 * The test validates if we get bit 4 over a varible with value 0x8A, to pass the return value
 * should be FALSE.
 */
void test__Bfx_GetBit_u8u8_u8__false( void )
{
    uint8 Data  = 0x8Au;
    boolean Bit = Bfx_GetBit_u8u8_u8( Data, 4u );
    TEST_ASSERT_MESSAGE( Bit == FALSE, "Bit is not FALSE as supposed to be" );
}

/**
 * @brief   **Test setting multiple bits**
 *
 * The test validates if we can set 3 bits starting at bit 4 over a varible with value 0x8A, to pass
 * data tested should be value 0xFA.
 */
void test__Bfx_SetBits_u8u8u8u8__mask1( void )
{
    uint8 Data = 0x8Au;
    Bfx_SetBits_u8u8u8u8( &Data, 4u, 3u, 1u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0xFAu, "Value is not 0xFA as supposed to be" );
}

/**
 * @brief   **Test clearing multiple bits**
 *
 * The test validates if we can clear 3 bits starting at bit 4 over a varible with value 0xFA, to pass
 * data tested should be value 0x8A.
 */
void test__Bfx_SetBits_u8u8u8u8__mask0( void )
{
    uint8 Data = 0xFAu;
    Bfx_SetBits_u8u8u8u8( &Data, 4u, 3u, 0u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0x8Au, "Value is not 0x8A as supposed to be" );
}

/**
 * @brief   **Test getting multiple bits**
 *
 * The test validates if we can get 3 bits starting at bit 4 over a varible with value 0x67, to pass
 * data tested should be value 0x06.
 */
void test__Bfx_GetBits_u8u8u8_u8__3bits( void )
{
    uint8 Data = 0x67u;
    Data       = Bfx_GetBits_u8u8u8_u8( Data, 4u, 3u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0x06u, "Value is not 0x06 as supposed to be" );
}

/**
 * @brief   **Test getting multiple bits**
 *
 * The test validates if we can get 4 bits starting at bit 1 over a varible with value 0x7A, to pass
 * data tested should be value 0x0D.  0110 0111
 */
void test__Bfx_GetBits_u8u8u8_u8__4bits( void )
{
    uint8 Data = 0x67u;
    Data       = Bfx_GetBits_u8u8u8_u8( Data, 1u, 4u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( 0x03u, Data, "Value is not 0x0D as supposed to be" );
}

/**
 * @brief   **Test setting multiple bits**
 *
 * The test validates if we can set a mask of bits with a value of 0xF0 over a varible with value
 * 0x67, to pass data tested should be value 0xF7.
 */
void test__Bfx_SetBitMask_u8u8__4bits( void )
{
    uint8 Data = 0x67u;
    Bfx_SetBitMask_u8u8( &Data, 0xF0u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0xF7u, "Value is not 0xF7 as supposed to be" );
}

/**
 * @brief   **Test clearing multiple bits**
 *
 * The test validates if we can clear a mask of bits with a value of 0xF0 over a varible with value
 * 0x67, to pass data tested should be value 0x07.
 */
void test__Bfx_ClrBitMask_u8u8__4bits( void )
{
    uint8 Data = 0x67u;
    Bfx_ClrBitMask_u8u8( &Data, 0xF0u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0x07u, "Value is not 0x07 as supposed to be" );
}

/**
 * @brief   **Test Mask of bits to true**
 *
 * The test validates if all the bit set of mask of with a value of 0x90 over a varible with value
 * 0xB3, to pass returned value should be TRUE.
 */
void test__Bfx_TstBitMask_u8u8_u8__true( void )
{
    uint8 Data  = 0xB3u;
    boolean Tst = Bfx_TstBitMask_u8u8_u8( Data, 0x90u );
    TEST_ASSERT_MESSAGE( Tst == TRUE, "Value is not TRUE as supposed to be" );
}

/**
 * @brief   **Test Mask of bits to false**
 *
 * The test validates if all the bit set of mask of with a value of 0xF0 over a varible with value
 * 0xB3, to pass returned value should be FALSE.
 */
void test__Bfx_TstBitMask_u8u8_u8__false( void )
{
    uint8 Data  = 0xB3u;
    boolean Tst = Bfx_TstBitMask_u8u8_u8( Data, 0xF0u );
    TEST_ASSERT_MESSAGE( Tst == FALSE, "Value is not FALSE as supposed to be" );
}

/**
 * @brief   **Test at least one bit Mask to true**
 *
 * The test validates if at least one the bit set of mask with a value of 0xF0 over a varible with value
 * 0xB3, to pass returned value should be TRUE.
 */
void test__Bfx_TstBitLnMask_u8u8_u8__true( void )
{
    uint8 Data  = 0xB3u;
    boolean Tst = Bfx_TstBitLnMask_u8u8_u8( Data, 0xF0u );
    TEST_ASSERT_MESSAGE( Tst == TRUE, "Value is not TRUE as supposed to be" );
}

/**
 * @brief   **Test at least one bit Mask to false**
 *
 * The test validates if none of the the bits set of mask with a value of 0x48 over a varible with value
 * 0xB3, to pass returned value should be FALSE.
 */
void test__Bfx_TstBitLnMask_u8u8_u8__false( void )
{
    uint8 Data  = 0xB3u;
    boolean Tst = Bfx_TstBitLnMask_u8u8_u8( Data, 0x48u );
    TEST_ASSERT_MESSAGE( Tst == FALSE, "Value is not FALSE as supposed to be" );
}

/**
 * @brief   **Test Parity**
 *
 * The test validates if parity to one is TRUE over a variable with value 0xAA, to pass the returned
 * variable should be TRUE
 */
void test__Bfx_TstParityEven_u8_u8__true( void )
{
    uint8 Data  = 0xAAu;
    boolean Tst = Bfx_TstParityEven_u8_u8( Data );
    TEST_ASSERT_MESSAGE( Tst == TRUE, "Value is not TRUE as supposed to be" );
}

/**
 * @brief   **Test Non-Parity**
 *
 * The test validates if parity to one is FALSE over a variable with value 0xA1, to pass the returned
 * variable should be FALSE
 */
void test__Bfx_TstParityEven_u8_u8__false( void )
{
    uint8 Data  = 0xA1u;
    boolean Tst = Bfx_TstParityEven_u8_u8( Data );
    TEST_ASSERT_MESSAGE( Tst == FALSE, "Value is not FALSE as supposed to be" );
}

/**
 * @brief   **Test toggle bits**
 *
 * The test validates if the bits can be toggle over a varible with value 0xAA, to pass Data should
 * be equal to 0x55.
 */
void test__Bfx_ToggleBits_u8( void )
{
    uint8 Data = 0xAAu;
    Bfx_ToggleBits_u8( &Data );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( 0x55, Data, "Value is not FALSE as supposed to be" );
}

/**
 * @brief   **Test toggle bits with a MAsk**
 *
 * The test validates if the bits set on tha mask 0xF0 can toggle the bits over a varible with value 0xAA,
 * to pass Data should be equal to 0x50.
 */
void test__Bfx_ToggleBitMask_u8u8( void )
{
    uint8 Data = 0xAAu;
    Bfx_ToggleBitMask_u8u8( &Data, 0xF0 );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( 0x5A, Data, "Value is not FALSE as supposed to be" );
}

/**
 * @brief   **Test shift to the right 4 bits**
 *
 * The test validates a shift to the right by 4 bits over a varible with value 0xAA, to pass Data
 * should be equal to 0x0A.
 */
void test__Bfx_ShiftBitRt_u8u8_4bits( void )
{
    uint8 Data = 0xAAu;
    Bfx_ShiftBitRt_u8u8( &Data, 4 );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( 0x0A, Data, "Value is not FALSE as supposed to be" );
}

/**
 * @brief   **Test shift to the right 8 bits**
 *
 * The test validates a shift to the right by 8 bits over a varible with value 0xAA, to pass Data
 * should be equal to 0x00.
 */
void test__Bfx_ShiftBitRt_u8u8_8bits( void )
{
    uint8 Data = 0xAAu;
    Bfx_ShiftBitRt_u8u8( &Data, 8 );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( 0x00, Data, "Value is not FALSE as supposed to be" );
}

/**
 * @brief   **Test shift to the left 4 bits**
 *
 * The test validates a shift to the left by 4 bits over a varible with value 0xAA, to pass Data
 * should be equal to 0xA0.
 */
void test__Bfx_ShiftBitLt_u8u8_4bits( void )
{
    uint8 Data = 0xAAu;
    Bfx_ShiftBitLt_u8u8( &Data, 4 );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( 0xA0, Data, "Value is not FALSE as supposed to be" );
}

/**
 * @brief   **Test shift to the left 8 bits**
 *
 * The test validates a shift to the left by 8 bits over a varible with value 0xAA, to pass Data
 * should be equal to 0x00.
 */
void test__Bfx_ShiftBitLt_u8u8_8bits( void )
{
    uint8 Data = 0xAAu;
    Bfx_ShiftBitLt_u8u8( &Data, 8 );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( 0x00, Data, "Value is not FALSE as supposed to be" );
}


int main( void )
{
    UNITY_BEGIN( );
    RUN_TEST( test__Bfx_SetBit_u8u8__bit2 );
    RUN_TEST( test__Bfx_SetBit_u8u8__bit7 );
    RUN_TEST( test__Bfx_ClrBit_u8u8__bit2 );
    RUN_TEST( test__Bfx_ClrBit_u8u8__bit7 );
    RUN_TEST( test__Bfx_GetBit_u8u8_u8__true );
    RUN_TEST( test__Bfx_GetBit_u8u8_u8__false );
    RUN_TEST( test__Bfx_SetBits_u8u8u8u8__mask1 );
    RUN_TEST( test__Bfx_SetBits_u8u8u8u8__mask0 );
    RUN_TEST( test__Bfx_GetBits_u8u8u8_u8__3bits );
    RUN_TEST( test__Bfx_GetBits_u8u8u8_u8__4bits );
    RUN_TEST( test__Bfx_SetBitMask_u8u8__4bits );
    RUN_TEST( test__Bfx_ClrBitMask_u8u8__4bits );
    RUN_TEST( test__Bfx_TstBitMask_u8u8_u8__true );
    RUN_TEST( test__Bfx_TstBitMask_u8u8_u8__false );
    RUN_TEST( test__Bfx_TstBitLnMask_u8u8_u8__true );
    RUN_TEST( test__Bfx_TstBitLnMask_u8u8_u8__false );
    RUN_TEST( test__Bfx_TstParityEven_u8_u8__true );
    RUN_TEST( test__Bfx_TstParityEven_u8_u8__false );
    RUN_TEST( test__Bfx_ToggleBits_u8 );
    RUN_TEST( test__Bfx_ToggleBitMask_u8u8 );
    RUN_TEST( test__Bfx_ShiftBitRt_u8u8_4bits );
    RUN_TEST( test__Bfx_ShiftBitRt_u8u8_8bits );
    RUN_TEST( test__Bfx_ShiftBitLt_u8u8_4bits );
    RUN_TEST( test__Bfx_ShiftBitLt_u8u8_8bits );
    return UNITY_END( );
}

void setUp( void )
{
}

void tearDown( void )
{
}
