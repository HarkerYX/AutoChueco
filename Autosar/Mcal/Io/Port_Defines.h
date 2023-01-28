#ifndef PORT_DEFINES_H
#define PORT_DEFINES_H


/**
 * @defgroup PORTS Microcontroller PORT definitions
 * @{ */
#define PORT_PA                   0x00
#define PORT_PB                   0x10
#define PORT_PC                   0x20
#define PORT_PD                   0x30
#define PORT_PE                   0x40
#define PORT_PF                   0x50
#define PORT_PG                   0x60
/**
 * @} */


/**
 * @defgroup PORTA Microcontroller PORTA pins definitions
 * @{ */
#define PORT_PIN_PA_00            0x00
#define PORT_PIN_PA_01            0x01
#define PORT_PIN_PA_02            0x02
#define PORT_PIN_PA_03            0x03
#define PORT_PIN_PA_04            0x04
#define PORT_PIN_PA_05            0x05
#define PORT_PIN_PA_06            0x06
#define PORT_PIN_PA_07            0x07
#define PORT_PIN_PA_08            0x08
#define PORT_PIN_PA_09            0x09
#define PORT_PIN_PA_10            0x0A
#define PORT_PIN_PA_11            0x0B
#define PORT_PIN_PA_12            0x0C
#define PORT_PIN_PA_13            0x0D
#define PORT_PIN_PA_14            0x0E
#define PORT_PIN_PA_15            0x0F
/**
 * @} */


/**
 * @defgroup PORTB Microcontroller PORTB pins definitions
 * @{ */
#define PORT_PIN_PB_00            0x10
#define PORT_PIN_PB_01            0x11
#define PORT_PIN_PB_02            0x12
#define PORT_PIN_PB_03            0x13
#define PORT_PIN_PB_04            0x14
#define PORT_PIN_PB_05            0x15
#define PORT_PIN_PB_06            0x16
#define PORT_PIN_PB_07            0x17
#define PORT_PIN_PB_08            0x18
#define PORT_PIN_PB_09            0x19
#define PORT_PIN_PB_10            0x1A
#define PORT_PIN_PB_11            0x1B
#define PORT_PIN_PB_12            0x1C
#define PORT_PIN_PB_13            0x1D
#define PORT_PIN_PB_14            0x1E
#define PORT_PIN_PB_15            0x1F
/**
 * @} */


/**
 * @defgroup PORTC Microcontroller PORTC pins definitions
 * @{ */
#define PORT_PIN_PC_00            0x20
#define PORT_PIN_PC_01            0x21
#define PORT_PIN_PC_02            0x22
#define PORT_PIN_PC_03            0x23
#define PORT_PIN_PC_04            0x24
#define PORT_PIN_PC_05            0x25
#define PORT_PIN_PC_06            0x26
#define PORT_PIN_PC_07            0x27
#define PORT_PIN_PC_08            0x28
#define PORT_PIN_PC_09            0x29
#define PORT_PIN_PC_10            0x2A
#define PORT_PIN_PC_11            0x2B
#define PORT_PIN_PC_12            0x2C
#define PORT_PIN_PC_13            0x2D
#define PORT_PIN_PC_14            0x2E
#define PORT_PIN_PC_15            0x2F
/**
 * @} */


/**
 * @defgroup PORTD Microcontroller PORTD pins definitions
 * @{ */
#define PORT_PIN_PD_00            0x30
#define PORT_PIN_PD_01            0x31
#define PORT_PIN_PD_02            0x32
#define PORT_PIN_PD_03            0x33
#define PORT_PIN_PD_04            0x34
#define PORT_PIN_PD_05            0x35
#define PORT_PIN_PD_06            0x36
#define PORT_PIN_PD_07            0x37
#define PORT_PIN_PD_08            0x38
#define PORT_PIN_PD_09            0x39
#define PORT_PIN_PD_10            0x3A
#define PORT_PIN_PD_11            0x3B
#define PORT_PIN_PD_12            0x3C
#define PORT_PIN_PD_13            0x3D
#define PORT_PIN_PD_14            0x3E
#define PORT_PIN_PD_15            0x3F
/**
 * @} */


/**
 * @defgroup PORTE Microcontroller PORTE pins definitions
 * @{ */
#define PORT_PIN_PE_00            0x40
#define PORT_PIN_PE_01            0x41
#define PORT_PIN_PE_02            0x42
#define PORT_PIN_PE_03            0x43
#define PORT_PIN_PE_04            0x44
#define PORT_PIN_PE_05            0x45
#define PORT_PIN_PE_06            0x46
#define PORT_PIN_PE_07            0x47
#define PORT_PIN_PE_08            0x48
#define PORT_PIN_PE_09            0x49
#define PORT_PIN_PE_10            0x4A
#define PORT_PIN_PE_11            0x4B
#define PORT_PIN_PE_12            0x4C
#define PORT_PIN_PE_13            0x4D
#define PORT_PIN_PE_14            0x4E
#define PORT_PIN_PE_15            0x4F
/**
 * @} */


/**
 * @defgroup PORTE Microcontroller PORTE pins definitions
 * @{ */
#define PORT_PIN_PF_00            0x50
#define PORT_PIN_PF_01            0x51
#define PORT_PIN_PF_02            0x52
#define PORT_PIN_PF_03            0x53
#define PORT_PIN_PF_04            0x54
#define PORT_PIN_PF_05            0x55
#define PORT_PIN_PF_06            0x56
#define PORT_PIN_PF_07            0x57
#define PORT_PIN_PF_08            0x58
#define PORT_PIN_PF_09            0x59
#define PORT_PIN_PF_10            0x5A
#define PORT_PIN_PF_11            0x5B
#define PORT_PIN_PF_12            0x5C
#define PORT_PIN_PF_13            0x5D
#define PORT_PIN_PF_14            0x5E
#define PORT_PIN_PF_15            0x5F
/**
 * @} */


/**
 * @defgroup PORT_modes GPIO Output Maximum frequency
 * @{ */
#define PORT_MODE_INPUT           0x00u /*!< Low speed       */
#define PORT_MODE_OUTPUT          0x01u /*!< Medium speed    */
#define PORT_MODE_ALTERN          0x02u /*!< High speed      */
#define PORT_MODE_ANALOG          0x03u /*!< Very high speed */
/**
 * @} */


/**
 * @defgroup PORT_speed GPIO Output Maximum frequency
 * @{ */
#define PORT_SPEED_FREQ_LOW       0x00u /*!< Low speed       */
#define PORT_SPEED_FREQ_MEDIUM    0x01u /*!< Medium speed    */
#define PORT_SPEED_FREQ_HIGH      0x02u /*!< High speed      */
#define PORT_SPEED_FREQ_VERY_HIGH 0x03u /*!< Very high speed */
/**
 * @} */


/**
 * @defgroup PORT_pull Pull-Up or Pull-Down Activation
 * @{ */
#define PORT_RESISTOR_NOPULL      0x00u /*!< No Pull-up or Pull-down activation  */
#define PORT_RESISTOR_PULLUP      0x01u /*!< Pull-up activation                  */
#define PORT_RESISTOR_PULLDOWN    0x02u /*!< Pull-down activation                */
/**
 * @} */

/**
 * @defgroup PORT_drive Drive output Push-Pull or Open collector
 * @{ */
#define PORT_PUSH_PULL            0x00u /*!< No Pull-up or Pull-down activation  */
#define PORT_OPEN_COLECTOR        0x01u /*!< Pull-up activation                  */
/**
 * @} */

/**
 * @brief   AF 0 selection
 */
#define PORT_AF0_CEC              ( (uint8)0x00 ) /*!< CEC Alternate Function mapping */
#define PORT_AF0_CRS              ( (uint8)0x00 ) /*!< CRS Alternate Function mapping */
#define PORT_AF0_EVENTOUT         ( (uint8)0x00 ) /*!< EVENTOUT Alternate Function mapping */
#define PORT_AF0_IR               ( (uint8)0x00 ) /*!< IR Alternate Function mapping */
#define PORT_AF0_LPTIM1           ( (uint8)0x00 ) /*!< LPTIM1 Alternate Function mapping */
#define PORT_AF0_MCO              ( (uint8)0x00 ) /*!< MCO (MCO1) Alternate Function mapping */
#define PORT_AF0_OSC              ( (uint8)0x00 ) /*!< OSC (By pass and Enable) Alternate Function mapping */
#define PORT_AF0_OSC32            ( (uint8)0x00 ) /*!< OSC32 (By pass and Enable) Alternate Function mapping */
#define PORT_AF0_SWJ              ( (uint8)0x00 ) /*!< SWJ (SWD) Alternate Function mapping */
#define PORT_AF0_SPI1             ( (uint8)0x00 ) /*!< SPI1 Alternate Function mapping */
#define PORT_AF0_SPI2             ( (uint8)0x00 ) /*!< SPI2 Alternate Function mapping */
#define PORT_AF0_TIM14            ( (uint8)0x00 ) /*!< TIM14 Alternate Function mapping */
#define PORT_AF0_TIM15            ( (uint8)0x00 ) /*!< TIM15 Alternate Function mapping */
#define PORT_AF0_TIM16            ( (uint8)0x00 ) /*!< TIM16 Alternate Function mapping */
#define PORT_AF0_TIM17            ( (uint8)0x00 ) /*!< TIM17 Alternate Function mapping */
#define PORT_AF0_USART1           ( (uint8)0x00 ) /*!< USART1 Alternate Function mapping */
#define PORT_AF0_USART2           ( (uint8)0x00 ) /*!< USART2 Alternate Function mapping */
#define PORT_AF0_USART3           ( (uint8)0x00 ) /*!< USART3 Alternate Function mapping */
#define PORT_AF0_USART4           ( (uint8)0x00 ) /*!< USART4 Alternate Function mapping */
#define PORT_AF0_UCPD1            ( (uint8)0x00 ) /*!< UCPD1 Alternate Function mapping */
#define PORT_AF0_UCPD2            ( (uint8)0x00 ) /*!< UCPD2 Alternate Function mapping */

/**
 * @brief   AF 1 selection
 */
#define GPIO_AF1_CEC              ( (uint8)0x01 ) /*!< CEC Alternate Function mapping */
#define GPIO_AF1_EVENTOUT         ( (uint8)0x01 ) /*!< EVENTOUT Alternate Function mapping */
#define GPIO_AF1_IR               ( (uint8)0x01 ) /*!< IR Alternate Function mapping */
#define GPIO_AF1_LPTIM2           ( (uint8)0x01 ) /*!< LPTIM2 Alternate Function mapping */
#define GPIO_AF1_LPUART1          ( (uint8)0x01 ) /*!< LPUART1 Alternate Function mapping */
#define GPIO_AF1_LPUART2          ( (uint8)0x01 ) /*!< LPUART2 Alternate Function mapping */
#define GPIO_AF1_OSC              ( (uint8)0x01 ) /*!< OSC (By pass and Enable) Alternate Function mapping */
#define GPIO_AF1_SPI1             ( (uint8)0x01 ) /*!< SPI2 Alternate Function mapping */
#define GPIO_AF1_SPI2             ( (uint8)0x01 ) /*!< SPI2 Alternate Function mapping */
#define GPIO_AF1_TIM1             ( (uint8)0x01 ) /*!< TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM3             ( (uint8)0x01 ) /*!< TIM3 Alternate Function mapping */
#define GPIO_AF1_USART1           ( (uint8)0x01 ) /*!< USART1 Alternate Function mapping */
#define GPIO_AF1_USART2           ( (uint8)0x01 ) /*!< USART2 Alternate Function mapping */
#define GPIO_AF1_USART4           ( (uint8)0x01 ) /*!< USART4 Alternate Function mapping */
#define GPIO_AF1_UCPD1            ( (uint8)0x01 ) /*!< UCPD1 Alternate Function mapping */
#define GPIO_AF1_UCPD2            ( (uint8)0x01 ) /*!< UCPD2 Alternate Function mapping */

/**
 * @brief   AF 2 selection
 */
#define GPIO_AF2_LPTIM1           ( (uint8)0x02 ) /*!< LPTIM1 Alternate Function mapping */
#define GPIO_AF2_LPTIM2           ( (uint8)0x02 ) /*!< LPTIM2 Alternate Function mapping */
#define GPIO_AF2_TIM1             ( (uint8)0x02 ) /*!< TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2             ( (uint8)0x02 ) /*!< TIM2 Alternate Function mapping */
#define GPIO_AF2_TIM4             ( (uint8)0x02 ) /*!< TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM14            ( (uint8)0x02 ) /*!< TIM14 Alternate Function mapping */
#define GPIO_AF2_TIM15            ( (uint8)0x02 ) /*!< TIM15 Alternate Function mapping */
#define GPIO_AF2_TIM16            ( (uint8)0x02 ) /*!< TIM16 Alternate Function mapping */
#define GPIO_AF2_TIM17            ( (uint8)0x02 ) /*!< TIM17 Alternate Function mapping */
#define GPIO_AF2_USB              ( (uint8)0x02 ) /*!< USB Alternate Function mapping */

/**
 * @brief   AF 3 selection
 */
#define GPIO_AF3_FDCAN1           ( (uint8)0x03 ) /*!< FDCAN1 Alternate Function mapping */
#define GPIO_AF3_FDCAN2           ( (uint8)0x03 ) /*!< FDCAN2 Alternate Function mapping */
#define GPIO_AF3_LPUART2          ( (uint8)0x03 ) /*!< LPUART2 Alternate Function mapping */
#define GPIO_AF3_USART5           ( (uint8)0x03 ) /*!< USART5 Alternate Function mapping */
#define GPIO_AF3_USART6           ( (uint8)0x03 ) /*!< USART6 Alternate Function mapping */
#define GPIO_AF3_MCO2             ( (uint8)0x03 ) /*!< MCO2 Alternate Function mapping */

/**
 * @brief   AF 4 selection
 */
#define GPIO_AF4_CRS              ( (uint8)0x04 ) /*!< CRS Alternate Function mapping */
#define GPIO_AF4_SPI2             ( (uint8)0x04 ) /*!< SPI2 Alternate Function mapping */
#define GPIO_AF4_SPI3             ( (uint8)0x04 ) /*!< SPI3 Alternate Function mapping */
#define GPIO_AF4_TIM14            ( (uint8)0x04 ) /*!< TIM14 Alternate Function mapping */
#define GPIO_AF4_TIM15            ( (uint8)0x04 ) /*!< TIM15 Alternate Function mapping */
#define GPIO_AF4_USART1           ( (uint8)0x04 ) /*!< USART1 Alternate Function mapping */
#define GPIO_AF4_USART3           ( (uint8)0x04 ) /*!< USART3 Alternate Function mapping */
#define GPIO_AF4_USART4           ( (uint8)0x04 ) /*!< USART4 Alternate Function mapping */
#define GPIO_AF4_USART6           ( (uint8)0x04 ) /*!< USART6 Alternate Function mapping */
#define GPIO_AF4_UCPD1            ( (uint8)0x04 ) /*!< UCPD1 Alternate Function mapping */
#define GPIO_AF4_UCPD2            ( (uint8)0x04 ) /*!< UCPD2 Alternate Function mapping */

/**
 * @brief   AF 5 selection
 */
#define GPIO_AF5_LPTIM1           ( (uint8)0x05 ) /*!< LPTIM1 Alternate Function mapping */
#define GPIO_AF5_LPTIM2           ( (uint8)0x05 ) /*!< LPTIM2 Alternate Function mapping */
#define GPIO_AF5_SPI1             ( (uint8)0x05 ) /*!< SPI1 Alternate Function mapping */
#define GPIO_AF5_SPI2             ( (uint8)0x05 ) /*!< SPI2 Alternate Function mapping */
#define GPIO_AF5_TIM1             ( (uint8)0x05 ) /*!< TIM1 Alternate Function mapping */
#define GPIO_AF5_TIM15            ( (uint8)0x05 ) /*!< TIM15 Alternate Function mapping */
#define GPIO_AF5_TIM16            ( (uint8)0x05 ) /*!< TIM16 Alternate Function mapping */
#define GPIO_AF5_TIM17            ( (uint8)0x05 ) /*!< TIM17 Alternate Function mapping */
#define GPIO_AF5_USART3           ( (uint8)0x05 ) /*!< USART3 Alternate Function mapping */

/**
 * @brief   AF 6 selection
 */
#define GPIO_AF6_I2C1             ( (uint8)0x06 ) /*!< I2C1 Alternate Function mapping */
#define GPIO_AF6_I2C2             ( (uint8)0x06 ) /*!< I2C2 Alternate Function mapping */
#define GPIO_AF6_I2C3             ( (uint8)0x06 ) /*!< I2C3 Alternate Function mapping */
#define GPIO_AF6_LPUART1          ( (uint8)0x06 ) /*!< LPUART1 Alternate Function mapping */
#define GPIO_AF6_UCPD1            ( (uint8)0x06 ) /*!< UCPD1 Alternate Function mapping */
#define GPIO_AF6_UCPD2            ( (uint8)0x06 ) /*!< UCPD2 Alternate Function mapping */
#define GPIO_AF6_USB              ( (uint8)0x06 ) /*!< USB Alternate Function mapping */

/**
 * @brief   AF 7 selection
 */
#define GPIO_AF7_COMP1            ( (uint8)0x07 ) /*!< COMP1 Alternate Function mapping */
#define GPIO_AF7_COMP2            ( (uint8)0x07 ) /*!< COMP2 Alternate Function mapping */
#define GPIO_AF7_COMP3            ( (uint8)0x07 ) /*!< COMP3 Alternate Function mapping */
#define GPIO_AF7_EVENTOUT         ( (uint8)0x07 ) /*!< EVENTOUT Alternate Function mapping */

/**
 * @brief   AF 8 selection
 */
#define GPIO_AF8_I2C2             ( (uint8)0x08 ) /*!< I2C2 Alternate Function mapping */
#define GPIO_AF8_USART5           ( (uint8)0x08 ) /*!< USART5 Alternate Function mapping */
#define GPIO_AF8_USART6           ( (uint8)0x08 ) /*!< USART5 Alternate Function mapping */

/**
 * @brief   AF 9 selection
 */
#define GPIO_AF9_I2C3             ( (uint8)0x09 ) /*!< I2C3 Alternate Function mapping */
#define GPIO_AF9_SPI3             ( (uint8)0x09 ) /*!< SPI3 Alternate Function mapping */
#define GPIO_AF9_TIM4             ( (uint8)0x09 ) /*!< TIM4 Alternate Function mapping */

/**
 * @brief   AF 10 selection
 */
#define GPIO_AF10_LPUART2         ( (uint8)0x0A ) /*!< LPUART2 Alternate Function mapping */

/**
 * @brief   AF Default selection
 */
#define PORT_AF_DEFAULT           ( (uint8)0x00 ) /*!< DEfault Alternate Function mapping */

/**
 * @brief   set 8 values into a 4 bits each one
 */
#define PORT_SET_4BITS_VALUES( p7, p6, p5, p4, p3, p2, p1, p0 ) \
    ( ( p7 ) << 28 ) | ( ( p6 ) << 24 ) | ( ( p5 ) << 20 ) | ( ( p4 ) << 16 ) | ( ( p3 ) << 12 ) | ( ( p2 ) << 8 ) | ( ( p1 ) << 4 ) | ( ( p0 ) << 0 )

/**
 * @brief   set 16 values into a 2 bits each one
 */
#define PORT_SET_2BITS_VALUES( p15, p14, p13, p12, p11, p10, p9, p8, p7, p6, p5, p4, p3, p2, p1, p0 )                                                             \
    ( ( p15 ) << 30 ) | ( ( p14 ) << 28 ) | ( ( p13 ) << 26 ) | ( ( p12 ) << 24 ) | ( ( p11 ) << 22 ) | ( ( p10 ) << 20 ) | ( ( p9 ) << 18 ) | ( ( p8 ) << 16 ) | \
    ( ( p7 ) << 14 ) | ( ( p6 ) << 12 ) | ( ( p5 ) << 10 ) | ( ( p4 ) << 8 ) | ( ( p3 ) << 6 ) | ( ( p2 ) << 4 ) | ( ( p1 ) << 2 ) | ( ( p0 ) << 0 )

/**
 * @brief   Set 16 values intop each bit
 */
#define PORT_SET_BITS_VALUES( p15, p14, p13, p12, p11, p10, p9, p8, p7, p6, p5, p4, p3, p2, p1, p0 )                                                            \
    ( ( p15 ) << 15 ) | ( ( p14 ) << 14 ) | ( ( p13 ) << 13 ) | ( ( p12 ) << 12 ) | ( ( p11 ) << 11 ) | ( ( p10 ) << 10 ) | ( ( p9 ) << 9 ) | ( ( p8 ) << 8 ) | \
    ( ( p7 ) << 7 ) | ( ( p6 ) << 6 ) | ( ( p5 ) << 5 ) | ( ( p4 ) << 4 ) | ( ( p3 ) << 3 ) | ( ( p2 ) << 2 ) | ( ( p1 ) << 1 ) | ( ( p0 ) << 0 )


#endif /*PORT_DEFINES_H*/
