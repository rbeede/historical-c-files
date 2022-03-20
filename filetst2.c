/*	This program shows an example of how to read and write to a file.
	It makes information for each variable write to a seperate line
	and also reads only one line for each variable.  It then removes
	the extra \n on the information.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

#define String_Length 3000

void null_term( char* str, int length );
void null_term2( char* str, int length );
int file_length( void );

char (*store)[2][35];
char filename[55]="c:\\rodney\\sfair\\master";

void main(void)
{
	FILE *file_ptr;
	char (*stuff)[2];
	int filel;
	int i;
	char Another;
	
alloveragain:

	if( NULL == ( stuff = calloc( (String_Length + 2), sizeof( char ) ) ) ){
		printf( "\nNot able to allocate memory.\n" );
		abort();
	}
	
	file_ptr = fopen( filename, "a" );
	
	Another = 'Y';

	while( Another == 'Y' ) {
        printf( "\nType in something (2500 chars max):  " );
    	gets( (*stuff) );	
		
		fprintf( file_ptr, "%s\n", (*stuff) );
	
		printf( "\nEnter another? (Y/N) ==> " );
		Another = getche();
		Another = toupper( Another );
		
	}

	fclose( file_ptr );
	
        	
	filel = file_length() - 1;
	if( NULL == ( store = calloc( filel * String_Length, sizeof( char ) ) ) ){
		printf( "\nNot able to allocate memory.\n" );
		abort();
	}

	printf( "\n\nFileL is %d.\n\n", filel );

	//Read the file
	file_ptr = fopen( filename, "r" );
	
	for( i = 0; i < filel; i++ ) {
		fgets( (*store)[i], String_Length, file_ptr );
		null_term( (*store)[i], String_Length );
		null_term2( (*store)[i], String_Length );
		printf( "\nI wrote and read: %s", (*store)[i] );
		if( strcmp( (*store)[i], "/~Begin Entry Class ID" ) == 0 ) 
			printf( "\nHeader\n" );
	}
	
	fclose( file_ptr );
	
	printf( "\nNumber of lines %d\n", filel );
	printf( "\nLast one is %s\n\n", (*store)[filel - 1] );
	printf( "\nDo it all over again? (Y/N) ==> " );
	Another = getche();
	Another = toupper( Another );
	
	free( stuff );
	free( store );
	
	if( Another == 'Y' ) goto alloveragain;
                                   
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

int file_length( void ) {
	FILE *fp;
	int length;
	char dummy[String_Length];
	
	length = 0;
	
	fp = fopen( filename, "r" );

	while( !feof( fp ) ) {
		fgets( dummy, String_Length, fp );
		length++;
	}
	
	return( length );
}
		
		
	