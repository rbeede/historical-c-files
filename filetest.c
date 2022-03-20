/*	This program shows an example of how to read and write to a file.
	It makes information for each variable write to a seperate line
	and also reads only one line for each variable.  It then removes
	the extra \n on the information.
*/

#include <stdio.h>
#include <stdlib.h>

void null_term( char* str, int length );
void null_term2( char* str, int length );

char store[2][35];

void main(void)
{
	FILE *file_ptr;
	char stuff[2][30];
	
    printf( "\nType in something (30 chars max):  " );
    gets( stuff[0] );
    printf( "\nType in something else:  " );
    gets( stuff[1] );	
	
	//Write the file
	file_ptr = fopen( "filetest.txt", "w" );
	
	fprintf( file_ptr, "%s\n", stuff[0] );
	fprintf( file_ptr, "%s\n", stuff[1] );

	fclose( file_ptr );
	

	//Read the file
	file_ptr = fopen( "filetest.txt", "r" );
	
	fgets( store[0], 30, file_ptr );
	fgets( store[1], 30, file_ptr );
	
	fclose( file_ptr );
	
	null_term( store[0], 30 );
	null_term( store[1], 30 );
	null_term2( store[0], 30 );
	null_term2( store[1], 30 );

	printf( "\nI wrote and read: %s", store[0] );
	printf( "\nI wrote and reads: %s" , store[1] );
	printf( "\nI hope this wrote and read correctly!" );
	
//	remove( "TEST.TXT" );
}

void null_term( char* str, int length ) {
	static int i;
	
	str += length - 1;  // point to last byte
	for( i=length; i>0; --i ) {
		if( *str != ' ' ) {
			++str;
			break;
		}
		--str;
	}

	if( i == 0 ) ++str;
	*str = '\0';
}

void null_term2( char* str, int length ) {
	static int i;
	
	str += length - 1;  // point to last byte
	for( i=length; i>0; --i ) {
		if( *str == '\n' ) {
			str=str;
			break;
		}
		--str;
	}

	if( i == 0 ) ++str;
	*str = '\0';
}