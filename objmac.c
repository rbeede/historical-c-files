/*  OBJMAC.C  This program demonstrates the use of object-
    like macros that work with characters and strings.	*/

#include <stdio.h>
#include <stdlib.h>

#define FIRST_CHAR 'H'
#define SECOND_CHAR 'i'
#define COMMA ','
#define STRING " this is a macro example."

main()
{
  putchar( FIRST_CHAR );
  putchar( SECOND_CHAR );
  putchar( COMMA );
  puts( STRING );
}
