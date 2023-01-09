#include <stdint.h>

extern uint8_t __stack_init;
extern uint8_t __bss_start;
extern uint8_t __bss_end;
extern uint8_t __data_init;
extern uint8_t __data_start;
extern uint8_t __data_end;

/*since we reference symbol main before the function declaration
we need to declare its prototype before array vectors*/
extern int main( void );
void Reset_Handler( void );
void NMI_Handler( void ) __attribute__( ( weak, alias( "Common_Handler" ) ) );
void HardFault_Handler( void ) __attribute__( ( weak, alias( "Common_Handler" ) ) );
void SysTick_Handler( void ) __attribute__( ( weak, alias( "Common_Handler" ) ) );


/*The following array should be place at the first FLASH memory adress and it holds
the stack pointer plus the 48 interrupts vector addresses*/
__attribute__( ( section( ".vectors" ) ) ) uint32_t vectors[ 49u ] =
{
/* clang-format off */
    (uint32_t)&__stack_init,    /*Stack init address*/
    (uint32_t)Reset_Handler,    /*function main address*/
    (uint32_t)NMI_Handler,      /*NMI interrupt service routine address*/
    (uint32_t)HardFault_Handler,/*Hard Fault interrupt service routine address*/
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)SysTick_Handler
};/* clang-format on */


/*We replaced the NMI and HardFault ISR for this "common" ISR*/
void Common_Handler( void )
{
}

/**
 *
 */
void Reset_Handler( void )
{
    uint32_t size;
    uint8_t *location;
    uint8_t *source;

    /*init bss section goes here*/
    location = &__bss_start;              /*init pointer to set a zero on each .bss location*/
    size     = &__bss_end - &__bss_start; /*get the amount of bytes from the .bss section*/
    for( int i = 0; i < size; i++ )
    {
        *location++ = 0u; /*fill it with zeros*/
    }

    /*init data section goes here*/
    source   = &__data_init;  /*get the LMA .data starting address*/
    location = &__data_start; /*get the VMA .data starting address*/
    size     = &__data_end - &__data_start;
    for( int i = 0; i < size; i++ )
    {
        *location++ = *source++; /*copy from flash to ram one bit at the time*/
    }

    main( );
}
