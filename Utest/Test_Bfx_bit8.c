#include "unity.h"
#include "Std_Types.h"
#include "Bfx_bit8.h"

void test__Bfx_SetBit_u8u8__bit2( void )
{
    uint8 Data = 0u;
    Bfx_SetBit_u8u8( &Data, 2u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0x04, "Bit 2 was not set as supposed to be" );
}

void test__Bfx_ClrBit_u8u8__bit2( void )
{
    uint8 Data = 0xffu;
    Bfx_ClrBit_u8u8( &Data, 2u );
    TEST_ASSERT_EQUAL_UINT8_MESSAGE( Data, 0xfb, "Bit 2 was not clear as supposed to be" );
}

int main( void )
{
    UNITY_BEGIN( );
    RUN_TEST( test__Bfx_SetBit_u8u8__bit2 );
    RUN_TEST( test__Bfx_ClrBit_u8u8__bit2 );
    return UNITY_END( );
}

void setUp( void )
{
}

void tearDown( void )
{
}
