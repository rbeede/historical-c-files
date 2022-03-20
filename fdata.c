#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <graph.h>

#define DATA_FILE "data.fil"

int menu( void );
int add( void );
int display( void );

main() {
	int return_value;
	
	while( ( return_value = menu() ) != 0 ) {
		switch( return_value ) {
			case 1:	add();
					break;
			case 2:	display();
					break;
			case 3:	_clearscreen( _GCLEARSCREEN);
					printf( "Enter a correct menu value.\n" );
					printf( "Press a key to continue.\n" );
					while( !kbhit() );
					break;
		}
	}
	return 0;
}

int menu() {
	char char_in[2];
	int i;
	
	_clearscreen( _GCLEARSCREEN );
	printf( "\n\n\n\n\n" );
	printf( "1.  Add data to the data file.\n" );
	printf( "2.  Display the data file.\n" );
	printf( "0.  Quit.\n" );
	
	printf( "\n\nEnter your selection ==> " );
	gets( char_in );
	i = atoi( char_in );
	if( i >= 0 && i <= 3 )
		return( i );
	else
		return( 3 );
}

int add() {
	FILE *fp;
	char more = 'Y';
	char name[30];
	int count;
	float weight;
	
	_clearscreen( _GCLEARSCREEN );
	
	if( ( fp = fopen( DATA_FILE, "ab" ) ) == NULL ) {
		_clearscreen( _GCLEARSCREEN );
		printf( "\n\nData file could not be opened.\n" );
		exit( 0 );
	}
	
	while( more == 'Y' ) {
		_clearscreen( _GCLEARSCREEN );
		printf( "\n\nEnter product name ==> " );
		scanf( "%s", name );
		printf( "\nEnter number of items ==> " );
		scanf( "%d", &count );
		printf( "\nEnter product weight ==> " );
		scanf( "%f", &weight );
		fflush( stdin );
		
		fprintf( fp, "%s %d %f", name, count, weight );
		
		printf( "\n\n\nEnter another product? Y/N ==> " );
		more = getche();
		if( more == 'y' ) more = 'Y';
	}
	
	fclose( fp );
	return 0;
}

int display() {
	FILE *fp;
	char name[30];
	int count;
	float weight;
	
	_clearscreen( _GCLEARSCREEN );
	if( ( fp = fopen( DATA_FILE, "rb" ) ) == NULL ) {
		_clearscreen( _GCLEARSCREEN );
		printf( "\n\nData file could not be opened.\n" );
		exit( 0 );
	}
	
	while( !feof( fp ) ) {
		fscanf( fp, "%s %d %f", name, &count, &weight );
		printf( "\n\n" );
		printf( "Product name: %s\n", name );
		printf( "Product count = %d\n", count );
		printf( "Product weight = %4.2f\n", weight );
	}
	
	printf( "\n\nPress any key to continue." );
	while( !kbhit() );
	
	fclose( fp );
	return 0;
}