/**
 * @file    Platform_Types.h
 * @brief   **Specification of Platform Types**
 *
 * This file contains all platform dependent types and symbols. Those types must be abstracted in
 * order to be-come platform and compiler independent. It is required that all platform types files
 * are unique within the AUTOSAR community to guarantee unique types per platform and to avoid type
 * changes when moving a software module from platform A to B.
 *
 * https://www.autosar.org/fileadmin/standards/classic/22-11/AUTOSAR_SWS_PlatformTypes.pdf
 */
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


/**
 * @name   CPU_Types
 * Symbols that specify the CPU type according to its own arquitecture (8, 16, 32 or 64 bits)
 */
/**@{*/
#define CPU_TYPE_8  8  /*!< Define a 8 bit CPU, ejem. PIC18F, ATmega, STM8 etc.. */
#define CPU_TYPE_16 16 /*!< Define a 16 bit CPU, ejem. PIC24F, S12, xMega etc.. */
#define CPU_TYPE_32 32 /*!< Define a 32 bit CPU, ejem. PIC132MX, STM32, TC2xx etc.. */
#define CPU_TYPE_64 64 /*!< Define a 64 bit CPU, ejem. ARMv8, x86 etc.. */
/**@}*/


/**
 * @name    Bit_order
 * Symbols to specify the bit order according to the CPU endianess, LSB for little endian and MSB
 * for big endian
 */
/**@{*/
#define MSB_FIRST 0 /*!< CPU with most significant bit aranged first */
#define LSB_FIRST 1 /*!< CPU with least significant bit aranged first */
/**@}*/


/**
 * @name    Byte_order
 * Symbols to specify the endianess types of the CPU
 */
/**@{*/
#define HIGH_BYTE_FIRST 0 /*!< Define a CPU with a big endian arquitecture */
#define LOW_BYTE_FIRST  1 /*!< Define a CPU with a little endian arquitecture */
/**@}*/


/**
 * @name    CPU_Definition
 * Specifies the CPU data and endianess arquitecture. In this case the values correspond to the mcu
 * stm32g0xx wich has a little endian 32 bits CPU
 */
/**@{*/
#define CPU_TYPE       CPU_TYPE_32    /*!< Indicate the CPU type (8,16,32 or 64 bits) */
#define CPU_BIT_ORDER  LSB_FIRST      /*!< CPU bit order (lsb or msb) */
#define CPU_BYTE_ORDER LOW_BYTE_FIRST /*!< Endianess type little or big */
/**@}*/

/**
 * @name    boolean_values
 * Symbols to specify true and false values
 */
/**@{*/
#ifndef TRUE
#define TRUE 1 /*!< Boolean representation of true */
#endif

#ifndef FALSE
#define FLASE 0 /*!< Boolean representation of false */
#endif
/**@}*/

/**
 * @name    unsigned_types
 * Cross platform type definitions to declare unsigned integer variables of  8, 16, 32, 64 and
 * boolean values
 */
/**@{*/
typedef bool boolean;              /*!< standar type that represents values TRUE or FALSE */
typedef unsigned char uint8;       /*!< standar type to declare one byte variables that store values
                                    in the range 0..255*/
typedef unsigned short uint16;     /*!< standar type to declare two byte variables that store values
                                    in the range 0..65,535 */
typedef unsigned int uint32;       /*!< standar type to declare four byte variables that store values
                                    in the range 0..4,294,967,295 */
typedef unsigned long long uint64; /*!< standar type to declare eight byte variables that store
                                    values in the range 0..18,446,744,073,709,551,615 */
/**@}*/


/**
 * @name    signed_types
 * Cross platform type definitions to declare signed integer variables of  8, 16, 32 and 64 values
 */
/**@{*/
typedef signed char sint8;       /*!< standar type to declare one byte variables that store values in the
                                range 128..+127 */
typedef signed short sint16;     /*!< standar type to declare two byte variables that store values in
                                the range -32,768..+32,767 */
typedef signed int sint32;       /*!< standar type to declare four byte variables that store values in the
                                range -2,147,483,648..+2,147,483,647 */
typedef signed long long sint64; /*!< standar type to declare eight byte variables that store values
                                in the range -9,223,372,036,854,775,808..+9,223,372,036,854,775,807 */
/**@}*/


/**
 * @name    unsigned_least
 * Cross platform type definitions to declare max or min ranges of unsigned 8, 16 and 32 values
 */
/**@{*/
typedef unsigned char uint8_least;   /*!< standar type to declare max or min ranges for an unsigned
                                        one byte variable */
typedef unsigned short uint16_least; /*!< standar type to declare max or min ranges for an unsigned
                                        two byte variable */
typedef unsigned long uint32_least;  /*!< standar type to declare max or min ranges for an unsigned
                                        four byte variable */
/**@}*/


/**
 * @name    signed_least
 * Cross platform type definitions to declare max or min ranges of signed 8, 16 and 32 values
 */
/**@{*/
typedef signed char sint8_least;   /*!< standar type to declare max or min ranges for a signed one
                                    byte variable */
typedef signed short sint16_least; /*!< standar type to declare max or min ranges for a signed two
                                    byte variable */
typedef signed long sint32_least;  /*!< standar type to declare max or min ranges for a signed four
                                    byte variable */
/**@}*/


/**
 * @name    floating_point
 * Cross platform type definitions to declare floating point variables of single and double presicion
 */
/**@{*/
typedef float float32;  /*!< standar type to declare single precision floating point variables in the
                          range of -3.4028235e+38..+3.4028235e+38 */
typedef double float64; /*!< standar type to declare double precision floating point variables in
                           the range of -1.7976931348623157e+308..+1.7976931348623157e+308 */
/**@}*/


/**
 * @name    void_pointers
 * Cross platform type definitions to declare void pointers
 */
/**@{*/
typedef void *VoidPtr;            /*!< standar type to declare void pointers, his type shall be used
                                    for buffers that contain data returned to the caller */
typedef const void *ConstVoidPtr; /*!< standar type to declare constant void pointers. This type
                                    shall be used for buffers that are passed to the callee */
/**@}*/


#endif /* PLATFORM_TYPES_H */