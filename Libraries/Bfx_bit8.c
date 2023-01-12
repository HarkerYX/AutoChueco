#include "Std_Types.h"
#include "Bfx_bit8.h"

/**
 * @brief **8 bits Set Bit** 
 * 
 * Sets the logical status of an 8 bits input data as 1 at the requested bit postion.
 * 
 * Example:
 *      Data = 10001010b 
 *      Bfx_SetBit_u8u8(&Data, 2);
 *      
 *      The Data will be updated to 10001110b
 * 
 * @param  Data Pointer to input data
 * @param  BitPn Bit position
 */
void Bfx_SetBit_u8u8( uint8 *Data, uint8 BitPn )
{
    (void)Data;
    (void)BitPn;
}

/**
 * @brief **8 bits Clear Bit**  
 * 
 * Clears the logical status of an 8 bit input data as 0 at the requested bit postion.
 * 
 * Example: 
 *      Data = 10001010b 
 *      Bfx_ClrBit_u8u8(&Data, 1); 
 *      
 *      The Data will be updated to 10001000b
 * 
 * @param  Data Pointer to inpur data
 * @param  BitPn Bit position
 */
void Bfx_ClrBit_u8u8( uint8 *Data, uint8 BitPn )
{
    (void)Data;
    (void)BitPn;
}

/**
 * @brief **8 bits Get Bit**  
 * 
 * Returns the logical status of the 8 bit input data for the requested bit position.
 * 
 * Example: 
 *      Bit = Bfx_GetBit_u8u8(10001010b, 1);
 *      Bit will be equal to TRUE
 * 
 * @param Data Input data  
 * @param BitPn Bit position
 * 
 * @retval Boolean Bit status
 */
boolean Bfx_GetBit_u8u8_u8( uint8 Data, uint8 BitPn )
{
    (void)Data;
    (void)BitPn;

    return FALSE;
}

/**
 * @brief **8 bits Write Multiple Bits**  
 * 
 * Sets the input data as 1 or 0 as per Status value starting from BitStartPn for the length BitLn.
 * 
 * For Example: 
 *      Data = 00000111b 
 *      Bfx_SetBits_u8u8u8u8(&Data, 4, 3, 1); 
 *      The Data will be updated to 11110111b
 * 
 * @param  Data Pointer to input Data
 * @param  BitStartPn Start bit position
 * @param  BitLn Bit field length
 * @param  Status Status value
 */
void Bfx_SetBits_u8u8u8u8( uint8 *Data, uint8 BitStartPn, uint8 BitLn, uint8 Status )
{
    (void)Data;
    (void)BitStartPn;
    (void)BitLn;
    (void)Status;   
}

/**
 * @brief **8 bits Get Multiple Bits**
 * 
 * Returns the Bits of the input data starting from BitStartPn for the length of BitLn. 
 * 
 * Example: 
 *      Data = Bfx_GetBits_u8u8u8_u8(01100111b, 4, 3) 
 *      data will be equal to 00000110b
 * 
 * @param  Data Input Data
 * @param  BitStartPn Start bit position
 * @param  BitLn Bit field length
 * 
 * @retval uint8 Bit field sequence
 */
uint8 Bfx_GetBits_u8u8u8_u8( uint8 Data, uint8 BitStartPn, uint8 BitLn )
{
    (void)Data;
    (void)BitStartPn;
    (void)BitLn;

    return 0u;  
}

/**
 * @brief **8 bits Set Multiple Bits**  
 * 
 * Set the data to logical status '1' as per the corresponding Mask bits when set to value 1 and 
 * remaining bits will retain their original values.
 * 
 * Example: 
 *      Data = 01100111b
 *      SetBitMask_u8u8(&Data, 11110000b) 
 *      Data will be equal to 11110111b
 * 
 * @param Data Pointer to input Data 
 * @param Mask Mask used to set bits
 */
void SetBitMask_u8u8( uint8 *Data, uint8 Mask )
{
    (void)Data;
    (void)Mask;   
}

/**
  * @brief  **8 bits Clear Multiple Bits**  
  * 
  * Clears the data to logical status 0 as per the corresponding mask bits value when set to 1.The 
  * remaining bits shall retain their original values.
  * 
  * Example: 
  *      Data = 01100111b
  *      Bfx_ClrBitMask_u8u8(&Data, 11110000b) 
  *      Data will be equal to 00000111b
  * 
  * @param Data Pointer to input Data 
  * @param Mask Mask value
  */
void Bfx_ClrBitMask_u8u8( uint8 *Data, uint8 Mask )
{
    (void)Data;
    (void)Mask;     
}

/**
 * @brief  **8 bit Test mask values**
 * 
 * Returns 1 if all bits defined in Mask value are set in the input Data value. In all other cases 
 * this function shall return 0.
 * 
 * Example: 
 *      Res = Bfx_TstBitMask_u8u8_u8(10010011b,10010000b) 
 *      Res will equal to TRUE.
 * 
 * @param Data Input Data 
 * @param Mask Mask value
 * 
 * @retval Boolean Value
 */
boolean Bfx_TstBitMask_u8u8_u8( uint8 Data, uint8 Mask )
{
    (void)Data;
    (void)Mask;

    return FALSE;    
}

/**
 * @brief **8 bit test at least one bit set**  
 *
 * Makes a test on the input data and if at least one bit is set as per the mask, then the function 
 * shall return TRUE, otherwise it shall return FALSE.
 * 
 * Example: 
 *      Res = Bfx_TstBitLnMask_u8u8_u8(10010011b,00010000b) 
 *      Res will equal to TRUE.
 * 
 * @param Data Input Data 
 * @param Mask Mask value
 * 
 * @retval Boolean Value
 */
boolean Bfx_TstBitLnMask_u8u8_u8( uint8 Data, uint8 Mask )
{
    (void)Data;
    (void)Mask; 

    return FALSE;    
}

/**
 * @brief **8 bit test parity**  
 * 
 * Tests the number of bits set to 1. If this number is even, it shall return TRUE, otherwise it 
 * returns FALSE.
 * 
 * Example: 
 *      Res = Bfx_TstParityEven_u8_u8(01010000b) 
 *      Res will equal to TRUE.
 * 
 * @param Data Input Data 
 * 
 * @retval Boolean Value
 */
boolean Bfx_TstParityEven_u8_u8( uint8 Data )
{
    (void)Data;

    return FALSE;     
}

/**
 * @brief  **8 bit Toggle bits**
 * 
 * Toggles all the bits of data (1's Complement Data).
 * 
 * Example: 
 *      Data = 01010001b
 *      Bfx_ToggleBits_u8(&Data) 
 *      Data will equal to 10101110b.
 * 
 * @param Data Pointer to input Data 
 */
void Bfx_ToggleBits_u8( uint8 *Data )
{
    (void)Data;
}

/**
 * @brief **8 bit Toggle multiple bits**
 * 
 * This function toggles the bits of data when the corresponding bit of the mask is enabled and set to 1.
 * 
 * Example: 
 *      Data = 01010001b
 *      Bfx_ToggleBitMask_u8u8(&Data, 11000011b) 
 *      Data will equal to 10010010b.
 * 
 * @param Data Pointer to input Data 
 * @param Mask Mask 
 */
void Bfx_ToggleBitMask_u8u8( uint8 *Data, uint8 Mask )
{
    (void)Data;
    (void)Mask;
}

/**
 * @brief  **8 bit Shift to the right**
 * 
 * This function shall shift data to the right by ShiftCnt. The most significant bit (left-most bit) is
 * replaced by a ’0’ bit and the least significant bit (right-most bit) is discarded for every single bit
 * shift cycle.
 * 
 * Example: 
 *      Data = 01010001b
 *      Bfx_ShiftBitRt_u8u8(&Data, 3) 
 *      Data will equal to 00001010b.
 * 
 * @param Data Pointer to input Data 
 * @param ShiftCnt Shift right count 
 */
void Bfx_ShiftBitRt_u8u8( uint8 *Data, uint8 ShiftCnt )
{
    (void)Data;
    (void)ShiftCnt;     
}

/**
 * @brief  **8 bit Shift to the left**
 * 
 * This function shall shift data to the left by ShiftCnt. The least significant bit (right-most bit) is
 * replaced by a ’0’ bit and the most significant bit (left-most bit) is discarded for every single bit
 * shift cycle.
 * 
 * Example: 
 *      Data = 01010001b
 *      Bfx_ShiftBitLt_u8u8(&Data, 3) 
 *      Data will equal to 10001000b.
 * 
 * @param Data Pointer to input Data 
 * @param ShiftCnt Shift left count 
 */
void Bfx_ShiftBitLt_u8u8( uint8 *Data, uint8 ShiftCnt )
{
    (void)Data;
    (void)ShiftCnt; 
}

/**
 * @brief  **8 bit Rotate to the right**
 * 
 * This function shall rotate data to the right by ShiftCnt. The least significant bit is rotated to the
 * most significant bit location for every single bit shift cycle.
 * 
 * Example:
 *      If ShiftCnt = 1 then,
 *      uint8 Data = 0001 0111 (before rotate right)
 *      Data = 1000 1011 (after rotate right)
 *      
 *      If ShiftCnt = 3 then,
 *      uint8 Data = 0001 0111 (before rotate right)
 *      Data = 1110 0010 (after rotate right)
 * 
 * @param Data Pointer to input Data 
 * @param ShiftCnt Shift right count 
 */
void Bfx_RotBitRt_u8u8( uint8 *Data, uint8 ShiftCnt)
{
    (void)Data;
    (void)ShiftCnt; 
}

/**
 * @brief  **8 bit Rotate to the left**
 * 
 * This function shall rotate data to the left by ShiftCnt. The most significant bit is rotated to the
 * least significant bit location for every single bit shift cycle
 * 
 * Example:
 *      If ShiftCnt = 1 then,
 *      uint8 Data = 1011 0111 (before rotate left)
 *      Data = 0110 1111 (after rotate left)
 *      
 *      If ShiftCnt = 3 then,
 *      uint8 Data = 1011 0111 (before rotate left)
 *      Data = 1011 1101 (after rotate left)
 * 
 * @param Data Pointer to input Data 
 * @param ShiftCnt Shift left count 
 */
void Bfx_RotBitLt_u8u8( uint8 *Data, uint8 ShiftCnt)
{
    (void)Data;
    (void)ShiftCnt; 
}

/**
 * @brief  **8 bit Copy bitst**
 * 
 * This function shall copy a bit from source data from bit position to destination data at bit
 * position.
 * 
 * Example:
 *      DestinationData = 10100001b
 *      BFX_CopyBit_u8u8u8u8(&DestinationData, 6, 11011010, 1)
 *      The DestinationData will have 11100001b
 * 
 * @param DestinationData Pointer to destination data
 * @param DestinationPosition Destination position
 * @param SourceData Source data
 * @param SourcePosition Source position 
 */
void Bfx_CopyBit_u8u8u8u8( uint8* DestinationData, uint8 DestinationPosition, uint8 SourceData, uint8 SourcePosition)
{
    (void)DestinationData;
    (void)DestinationPosition; 
    (void)SourceData;
    (void)SourcePosition; 
}

/**
 * @brief  **8 bit Put bitst**
 * 
 * This function shall put bits as mentioned in Pattern to the input Data from the specified bit
 * position.
 * 
 * Example:
 *      Data = 11110000b
 *      Bfx_PutBits_u8u8u8u8(&Data, 1, 3, 00000011b)
 *      The Data will have 11110110b
 * 
 * @param Data Pointer to input data
 * @param BitStartPn Start bit position
 * @param BitLn Bit field length
 * @param Pattern Pattern to be set
 */
void Bfx_PutBits_u8u8u8u8( uint8* Data, uint8 BitStartPn, uint8 BitLn, uint8 Pattern )
{
    (void)Data;
    (void)BitStartPn; 
    (void)BitLn;
    (void)Pattern; 
}

/**
 * @brief  **8 bit Put bitst**
 * 
 * This function shall put bits as mentioned in Pattern to the input Data from the specified bit
 * position.
 * 
 * Example:
 *      Data = 11100000b
 *      Bfx_PutBitsMask_u8u8u8(&Data, 11001101b, 00001111b)
 *      results in Data = 11101101b
 * 
 * @param Data Pointer to input data
 * @param Pattern Pattern to be set
 * @param Mask Mask value
 */
void Bfx_PutBitsMask_u8u8u8( uint8* Data, uint8 Pattern, uint8 Mask )
{
    (void)Data;
    (void)Mask; 
    (void)Pattern; 
}

/**
 * @brief  **8 bit Put single bit**
 * 
 * This function shall update the bit specified by BitPn of input data as ’1’ or ’0’ as per ’Status’
 * value.
 * 
 * Example:
 *      uint8 InputData = 11100111b;
 *      Bfx_PutBit_u8u8u8(&InputData, 4, TRUE);
 *      results in InputData = 11110111b
 * 
 * @param Data Pointer to destination data
 * @param BitPn Destination position
 * @param Status Source data
 */
void Bfx_PutBit_u8u8u8( uint8* Data, uint8 BitPn, boolean Status )
{
    (void)Data;
    (void)BitPn; 
    (void)Status;
}

/**
 * @brief  **8 bit Arithmetic shift with saturation**
 * 
 * For signed data an arithmetic shift is performed. The vacated bits are filled with zeros
 * and the result is saturated if its sign bit differs from the sign bits that are shifted out.
 *
 * For unsigned data a logical shift is performed. In this case the result is saturated, if the
 * leading one bit is shifted out.
 *
 * If the shift count is less than zero, right-shift the value in Data by the absolute value of
 * the shift count. The vacated bits are filled with the sign-bit (the most significant bit) and
 * bits shifted out are discarded.
 *
 * Note that a shift right by the word width leaves all zeros or all ones in the result, de-
 * pending on the sign-bit.
 *
 * Example:
 * a 32 bit signed integer: The range for shift count is -32 to +31, allowing a
 * shift left up to 31 bit positions and a shift right up to 32 bit positions (a shift right by 32
 * bits leaves all zeros or all ones in the result, depending on the sign bit)
 * 
 * @param ShiftCnt Shift count (-<MaxShiftRight> ... -1: right, 1 ... <MaxShiftLeft>:left)
 * @param Data Input value
 * 
 * @retval Shifted and saturated bit pattern.
 */
sint8 Bfx_ShiftBitSat_s8s8( sint8 ShiftCnt, sint8 Data )
{
    (void)Data;
    (void)ShiftCnt;

    return 0; 
}

/**
 * @brief  **8 bit Count Leading Ones**
 * 
 * Count the number of consecutive ones in Data starting with the most significant bit and return
 * the result.
 * 
 * Example:
 *      Res = Bfx_CountLeadingOnes_u8(11100110b);
 *      Res is equal to 3
 * 
 * @param Data Input data
 *
 * @retval Bit position
 */
uint8 Bfx_CountLeadingOnes_u8( uint8 Data )
{
    (void)Data;

    return 0; 
}

/**
 * @brief  **8 bit Count Leading bits**
 * 
 * Count the number of consecutive bits which have the same value as most significant bit in Data,
 * starting with bit at position msb minus one. Put the result in Data. It is the number of leading
 * sign bits minus one, giving the number of redundant sign bits in Data
 * 
 * Example:
 *      Res = Bfx_CountLeadingSigns_s8(11100110b);
 *      Res is equal to 2
 * 
 * @param Data Input data
 *
 * @retval Bit position
 */
uint8 Bfx_CountLeadingSigns_s8( sint8 Data )
{
    (void)Data;

    return 0; 
}

/**
 * @brief  **8 bit Count Leading Zeros**
 * 
 * Count the number of consecutive zeros in Data starting with the most significant bit and return
 * the result
 * 
 * Example:
 *      Res = Bfx_CountLeadingZeros_u8(00100110b);
 *      Res is equal to 2
 * 
 * @param Data Input data
 *
 * @retval Bit position
 */
uint8 Bfx_CountLeadingZeros_u8( uint8 Data )
{
    (void)Data; 

    return 0; 
}

