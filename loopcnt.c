/*  LOOPCNT.C  This program demonstrates how arguments are
	       passed by value.  */

#include <stdio.h>
#include <stdlib.h>

void loop_count( int i );

main()
{
  int i = 2;

  loop_count( i );
  printf( "In main, i = %d.\n", i );
}

void loop_count( int i )
{
  for( ; i < 10; i++ )
    printf( "In loop_count, i = %d.\n", i );
}
