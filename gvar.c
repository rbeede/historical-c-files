/*  GVAR.C  Using a global variable */

#include <stdio.h>
#include <stdlib.h>

int gvar;
void funct_1( void );

main()
{
  gvar = 2;
  funct_1();
  printf( "In main()\n" );
  printf( "gvar = %d\n\n", gvar);
}

void funct_1( void )
{
  printf( "In funct1()\n" );
  printf( "gvar = %d\n\n", gvar );
  gvar = gvar * 2;
}
