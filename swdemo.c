/*  SWDEMO.C  A demonstration of the switch statement */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graph.h>

main()
{
  char char_in;

  _clearscreen( _GCLEARSCREEN );

  printf( "----- Diagnostic Menu -----\n\n" );
  printf( "A:  System Tests\n" );
  printf( "B:  Video Tests\n" );
  printf( "C:  Hard Drive Tests\n" );
  printf( "D:  Keyboard Tests\n\n" );
  printf( "Enter a letter to select the tests => " );

  char_in = getche();
  printf( "\n\n\n");
  char_in = toupper( char_in );

  switch( char_in )
  {
    case 'A': printf( "You chose the system tests.\n" );
	      break;
    case 'B': printf( "You chose the video tests.\n" );
	      break;
    case 'C': printf( "You chose the drive tests.\n" );
	      break;
    case 'D': printf( "You chose the keyboard tests.\n" );
	      break;
    default : printf( "You did not choose a test.\n" );
   }
}
