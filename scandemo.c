/*  SCANDEMO.C - This program demonstrates scanf(). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  int num1;
  int num2;
  char operation[4];
  int comp_result;

  printf( "This program lets you input two numbers and\n" );
  printf( "the type of mathematical operation \n" );
  printf( "for the numbers.  At the INPUT > prompt, \n" );
  printf( "enter two numbers and the operation to be\n" );
  printf( "performed.  ADD for addition, SUB for\n" );
  printf( "subtraction.\n\n" );

  printf( "INPUT > " );
  scanf( "%d %d %s", &num1, &num2, operation );

  comp_result = strcmp( "ADD", operation );
  if( comp_result == 0 )
    printf( "The sum equals %d\n", num1 + num2 );
  else
    printf( "The difference is %d\n", num1 - num2 );

  return 0;
}
