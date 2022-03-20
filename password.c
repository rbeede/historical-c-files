#include <stdio.h>
#include <conio.h>

void UserPassword( char Password[] );

void main() {
    char Pass[25];
	
	
	UserPassword( Pass );
	printf( "\nPassword is: %s.", Pass );
}

void UserPassword( char Password[] ) {
	int char_in, i;
	
	i = 0;
	while( char_in != '\r' ) {
		char_in = getch();
		
		if( char_in == '\b' ) {
			i--;
			if( i < 0 ) i = 0;
			Password[i] = '\0';
		}
		else if( char_in == '\r' ) {
			;
		}
		else if( i != 8 ) {
			Password[i] = char_in;
			i++;
			if( i > 8 ) i = 8;
		}
	}
}