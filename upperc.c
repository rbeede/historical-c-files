/*  UPPERC.C  Convert a lowercase letter to an uppper case
    letter using the toupper() function.  */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graph.h>

main()
{
  int in_char;
  int out_char;

  _clearscreen( _GCLEARSCREEN );
  printf( "Enter a single character => " );
  in_char = getche();
  out_char = toupper( in_char );
  printf( "\n\nThe uppercase character is: %c",
	  out_char );
}
