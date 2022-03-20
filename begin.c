/* BEGIN.C  This program shows the basic
   parts of a C program */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graph.h>

#define F 0
  /* define the macro F to equal 0 */
#define T 1
  /* define the macro T to equal 1 */

int i = 0;

void put_msg( void );

main()
{
  int answer;

  _clearscreen( _GCLEARSCREEN );
  printf( "Do you want to see the message?\n" );
  printf( "Enter 0 for NO, 1 for YES ==> " );
  scanf( "%d", &answer );
  if( answer == T )
    put_msg();
    else
    puts( "Goodbye for now." );
}

void put_msg( void )
{
  _clearscreen( _GCLEARSCREEN );
  for( i = 0; i <=10; i++ )
    printf( "Test string # %d.\n", i );
}
