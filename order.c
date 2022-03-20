/*  ORDER.C  An illustration of the basic parts of a
    C program.	*/

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

float calc_sub_total( int quantity, float price );
float calc_tax( float sub_total );

main()
{
  char name[30];
  char product[30];
  int quantity;
  float price;
  float sub_total;
  float tax;

  _clearscreen( _GCLEARSCREEN );
  printf( "\n\nEnter your last name => " );
  scanf( "%s", name );
  printf( "\n\nEnter the name of product => " );
  scanf( "%s", product );
  printf( "\n\n Enter the quantity and price => ");
  scanf( "%d %f", &quantity, &price );

  sub_total = calc_sub_total( quantity, price );
  tax = calc_tax( sub_total );

  _clearscreen( _GCLEARSCREEN );
  printf( "\n\nOrder Information\n\n" );
  printf( "Name: %s\n", name );
  printf( "Product ordered: %s\n\n", product );
  printf( "Quantity ordered: %d\n\n", quantity );
  printf( "Price per unit: $%3.2f\n", price );
  printf( "Sub total:          $%3.2f\n", sub_total );
  printf( "Tax:                $%3.2f\n", tax );
  printf( "Total:              $%3.2f\n", (sub_total + tax ) );
}

float calc_sub_total( int quantity, float price )
{
  float sub_total;

  sub_total =  price * quantity;
  return sub_total;
}

float calc_tax( float sub_total )
{
  const float tax_rate = 0.06;

  float tax;

  tax = sub_total * tax_rate;
  return tax;
}
