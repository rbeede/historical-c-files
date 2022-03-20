/*  STRTOINT.C	Converting a string value to an integer
    value.  */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graph.h>

main()
{
  char num_str[6];
  int num_int;

  _clearscreen( _GCLEARSCREEN );
  printf( "Enter an integer number => " );
  gets( num_str );
  num_int = atoi( num_str );
  printf( "\n\nYour integer was %d", num_int );
}
