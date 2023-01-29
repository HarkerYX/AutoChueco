#include "Std_Types.h"
#include "Port.h"
#include "Dio.h"

int main( void )
{
    Port_Init( &PortConfig );
    while( 1u )
    {
        Dio_FlipChannel( DIO_RED_LED );
    }

    return 0u;
}
