/* LVAR.C  Using local variables */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416
void square_1( void );
float square_2( float );

main()
{
  float radius_1 = 5.0; /* Declare local variables */
  float radius_2 = 7.0;
  float area_1;
  float area_2;

  square_1();
  radius_2 = square_2( radius_2 );

  area_1 = PI * radius_1;
  area_2 = PI * radius_2;

  printf( "Area 1 = %f\n", area_1 );
  printf( "Area 2 = %f\n", area_2 );

}

void square_1( void )
{
  float radius_1;

  radius_1 = radius_1 * radius_1;
}

float square_2( float  radius_2 )
{
  radius_2 = radius_2 * radius_2;
  return radius_2;
}
