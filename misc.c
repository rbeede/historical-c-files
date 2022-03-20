#include <stdio.h>
#include <stdlib.h>

void main(void) {

	char name[3][30]; // names can be 30 chars long, Last, First, Middle
	int counter;
	
	printf( "Type in the last name:  " );
	scanf( "%s", name[0] ); //Last name
	printf( "Type in the first name:  " );
	scanf( "%s", name[1] ); //First name
	printf( "Type in the middle name:  " );
	scanf( "%s", name[2] ); //Middle name
	
	printf( "\nYou typed in the name " );
	
	for( counter = 0; counter <= 1; counter++)
	{
		printf( "%s, ", name[counter] );
	}
	
	printf( "%s.\n", name[2]);
	
	printf( "\nGood for you.");
	
	if( strcmp( name[1], "Rodney" ) == 0 ) {
		printf( "\nI like my name %s.\n", name[1] );
	}
	else {
		printf( "\nNot my name: %s\n", name[1] );
	}
	
}