#include <stdio.h>
#include <limits.h>

void printCharAsBinary( char c )
{
    for ( int i = CHAR_BIT; i-- != 0; )
    {
        printf( "%u", ( unsigned char )c >> i & 1 );
    }
}

int main() 
{
   
    
        printCharAsBinary( 'A' );
        putchar( '\n' );
          

    return 0;
}