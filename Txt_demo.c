/*  TXT_DEMO  This program uses the text window functions
	      to demonstrate the use of the library
	      functions.  */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "graph.h"

main()
{
  int i, j;
  char buffer[80];

  _clearscreen( _GCLEARSCREEN );
  _setvideomode ( _TEXTC80 );

  while( !kbhit() ) {
    for( i = 0; i <=15; i++ ) {
      _settextcolor( i );
      for( j = 48; j <= 90; j++) {
	sprintf( buffer, "%c", j );
	_outtext( buffer );
      }
    }
  }
}
