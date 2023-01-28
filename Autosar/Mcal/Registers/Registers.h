#ifndef REGISTERS_H
#define REGISTERS_H

/**
 * @brief General Purpose I/O
 */
typedef struct
{
    volatile uint32 MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
    volatile uint32 OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
    volatile uint32 OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
    volatile uint32 PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    volatile uint32 IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
    volatile uint32 ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
    volatile uint32 BSRR;     /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
    volatile uint32 LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    volatile uint32 AFR[ 2 ]; /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
    volatile uint32 BRR;      /*!< GPIO Bit Reset register,               Address offset: 0x28      */
} Port_RegisterType;

/** @addtogroup Peripheral_memory_map
 * @{
 */
#define FLASH_BASE  ( 0x08000000UL ) /*!< FLASH base address */
#define SRAM_BASE   ( 0x20000000UL ) /*!< SRAM base address */
#define PERIPH_BASE ( 0x40000000UL ) /*!< Peripheral base address */
#define IOPORT_BASE ( 0x50000000UL ) /*!< IOPORT base address */

/*!< IOPORT */
#define PORTA_BASE  ( IOPORT_BASE + 0x00000000UL )
#define PORTB_BASE  ( IOPORT_BASE + 0x00000400UL )
#define PORTC_BASE  ( IOPORT_BASE + 0x00000800UL )
#define PORTD_BASE  ( IOPORT_BASE + 0x00000C00UL )
#define PORTE_BASE  ( IOPORT_BASE + 0x00001000UL )
#define PORTF_BASE  ( IOPORT_BASE + 0x00001400UL )

#define PORTA       ( (Port_RegisterType *)PORTA_BASE )
#define PORTB       ( (Port_RegisterType *)PORTB_BASE )
#define PORTC       ( (Port_RegisterType *)PORTC_BASE )
#define PORTD       ( (Port_RegisterType *)PORTD_BASE )
#define PORTE       ( (Port_RegisterType *)PORTE_BASE )
#define PORTF       ( (Port_RegisterType *)PORTF_BASE )

#endif /* REGISTERS_H */
