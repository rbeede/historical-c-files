#include <stdio.h>

void main( void ) {
	int Letter[10];  //Used to hold parts of password code
	int i, j;  //Used for counters

	int TOP = 255;
	int BOTTOM = 32;
	
	//Initilize all the data in the Letter array
	for( i = 0; i <= 10; i++ )
		Letter[i] = 0;

	do {
		for( i = BOTTOM; i <= TOP; i++ ) {
		    Letter[0] = i;

			printf( "Letter[0-7] = " );
			for( j = 0; j <= 7; j++ )
				printf( "%c", Letter[j] );
				
			printf( "\n" );

		}

		if( Letter[1] < BOTTOM ) Letter[1] == BOTTOM - 1;
		
		Letter[1]++;

		for( i = 1; i <= 7; i++ ) {
			if( Letter[i] > TOP ) {
				Letter[i] = BOTTOM;
					
	        	if( i != 7 ) Letter[i+1]++;
	        
	        	if( Letter[i+1] < BOTTOM ) Letter[i+1] = BOTTOM;
	        }
	        else {
	        	break;
	        }
		}  //For-Loop-Block
		
	} while( Letter[7] < 256 );

}