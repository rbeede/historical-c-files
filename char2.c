#include <stdio.h>
#define CARRAY_SIZE 30

main()
{
	char carray[CARRAY_SIZE];
	int sub;
	
	printf( "Enter character string\n" );
	gets( carray );
	
	printf( "The array contains: %s\n", carray );
	
	for ( sub = 0; (sub < CARRAY_SIZE) && ( carray[sub] != ' ' ); sub++ )
	{
		putchar( carray[sub] );
	}
	putchar( '\n' );
}