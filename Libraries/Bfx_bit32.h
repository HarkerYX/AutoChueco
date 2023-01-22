/**
 * @file    Bfx_bit32.h
 * @brief   **Specification of 32 Bit Handling Routines**
 *
 * AUTOSAR Library routines are the part of system services in AUTOSAR architecture and below figure
 * shows position of AUTOSAR library in layered architecture.
 *
 * Bfx routines specification specifies the functionality, API and the configuration of the AUTOSAR
 * library for BIT functionality dedicated to fixed-point arithmetic routines All bit functions are
 * re-entrant and can handle several simultaneous requests from the application.
 */
#ifndef BFX_BIT32_H
#define BFX_BIT32_H

void Bfx_SetBit_u32u8( uint32 *Data, uint8 BitPn );
void Bfx_ClrBit_u32u8( uint32 *Data, uint8 BitPn );
boolean Bfx_GetBit_u32u8_u8( uint32 Data, uint8 BitPn );

void Bfx_SetBits_u32u8u8u8( uint32 *Data, uint8 BitStartPn, uint8 BitLn, uint8 Status );
uint32 Bfx_GetBits_u32u8u8_u32( uint32 Data, uint8 BitStartPn, uint8 BitLn );

void Bfx_SetBitMask_u32u32( uint32 *Data, uint32 Mask );
void Bfx_ClrBitMask_u32u32( uint32 *Data, uint32 Mask );

boolean Bfx_TstBitMask_u32u32_u8( uint32 Data, uint32 Mask );
boolean Bfx_TstBitLnMask_u32u32_u8( uint32 Data, uint32 Mask );
boolean Bfx_TstParityEven_u32_u8( uint32 Data );

void Bfx_ToggleBits_u32( uint32 *Data );
void Bfx_ToggleBitMask_u32u32( uint32 *Data, uint32 Mask );

void Bfx_ShiftBitRt_u32u8( uint32 *Data, uint8 ShiftCnt );
void Bfx_ShiftBitLt_u32u8( uint32 *Data, uint8 ShiftCnt );
void Bfx_RotBitRt_u32u8( uint32 *Data, uint8 ShiftCnt );
void Bfx_RotBitLt_u32u8( uint32 *Data, uint8 ShiftCnt );
void Bfx_CopyBit_u32u8u32u8( uint32 *DestinationData, uint8 DestinationPosition, uint32 SourceData, uint8 SourcePosition );

void Bfx_PutBits_u32u8u8u32( uint32 *Data, uint8 BitStartPn, uint8 BitLn, uint32 Pattern );
void Bfx_PutBitsMask_u32u32u32( uint32 *Data, uint32 Pattern, uint32 Mask );
void Bfx_PutBit_u32u8u8( uint32 *Data, uint8 BitPn, boolean Status );

sint32 Bfx_ShiftBitSat_s32s8_s32( sint32 Data, sint8 ShiftCnt );
uint32 Bfx_ShiftBitSat_u32s8_u32( uint32 Data, sint8 ShiftCnt );

uint8 Bfx_CountLeadingOnes_u32( uint32 Data );
uint8 Bfx_CountLeadingSigns_s32( sint32 Data );
uint8 Bfx_CountLeadingZeros_u32( uint32 Data );


#endif /* BFX_BIT32_H */
