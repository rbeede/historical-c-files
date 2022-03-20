/*  FDUMP.C  File dump utility using a while loop */
#include <stdio.h>
#include <stdlib.h>

main()
{
  FILE *f_in;
  char c;

  if( ( f_in = fopen( "\\test.txt", "rt" ) ) == NULL )
  {
    printf( "Unable to open file.  Aborting.\n" );
    return 1;
  }

  while( !feof( f_in ) ) {
    c = fgetc( f_in );
    putchar( c );
  }
}
