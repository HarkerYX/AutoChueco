#include "Std_Types.h"
#include "Port.h"
#include "Dio.h"

int main( void )
{
    Port_Init( &PortConfig );
    while( 1u )
    {
        Dio_FlipChannel();
    }

    return 0u;
}
