/**
 * @file    Bfx_bit8.h
 * @brief   **Specification of 8 Bit Handling Routines**
 *
 * AUTOSAR Library routines are the part of system services in AUTOSAR architecture and below figure
 * shows position of AUTOSAR library in layered architecture.
 *
 * Bfx routines specification specifies the functionality, API and the configuration of the AUTOSAR
 * library for BIT functionality dedicated to fixed-point arithmetic routines All bit functions are
 * re-entrant and can handle several simultaneous requests from the application.
 */
#ifndef BFX_BIT8_H
#define BFX_BIT8_H

void Bfx_SetBit_u8u8( uint8 *Data, uint8 BitPn );
void Bfx_ClrBit_u8u8( uint8 *Data, uint8 BitPn );
boolean Bfx_GetBit_u8u8_u8( uint8 Data, uint8 BitPn );

void Bfx_SetBits_u8u8u8u8( uint8 *Data, uint8 BitStartPn, uint8 BitLn, uint8 Status );
uint8 Bfx_GetBits_u8u8u8_u8( uint8 Data, uint8 BitStartPn, uint8 BitLn );

void SetBitMask_u8u8( uint8 *Data, uint8 Mask );
void Bfx_ClrBitMask_u8u8( uint8 *Data, uint8 Mask );

boolean Bfx_TstBitMask_u8u8_u8( uint8 Data, uint8 Mask );
boolean Bfx_TstBitLnMask_u8u8_u8( uint8 Data, uint8 Mask );
boolean Bfx_TstParityEven_u8_u8( uint8 Data );

void Bfx_ToggleBits_u8( uint8 *Data );
void Bfx_ToggleBitMask_u8u8( uint8 *Data, uint8 Mask );

void Bfx_ShiftBitRt_u8u8( uint8 *Data, uint8 ShiftCnt );
void Bfx_ShiftBitLt_u8u8( uint8 *Data, uint8 ShiftCnt );
void Bfx_RotBitRt_u8u8( uint8 *Data, uint8 ShiftCnt );
void Bfx_RotBitLt_u8u8( uint8 *Data, uint8 ShiftCnt );
void Bfx_CopyBit_u8u8u8u8( uint8 *DestinationData, uint8 DestinationPosition, uint8 SourceData, uint8 SourcePosition );

void Bfx_PutBits_u8u8u8u8( uint8 *Data, uint8 BitStartPn, uint8 BitLn, uint8 Pattern );
void Bfx_PutBitsMask_u8u8u8( uint8 *Data, uint8 Pattern, uint8 Mask );
void Bfx_PutBit_u8u8u8( uint8 *Data, uint8 BitPn, boolean Status );

sint8 Bfx_ShiftBitSat_s8s8( sint8 ShiftCnt, sint8 Data );
uint8 Bfx_CountLeadingOnes_u8( uint8 Data );
uint8 Bfx_CountLeadingSigns_s8( sint8 Data );
uint8 Bfx_CountLeadingZeros_u8( uint8 Data );


#endif /* BFX_BIT8_H */
