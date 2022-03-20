#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <graph.h>

main() {
	int i;
	char temp;
	
	_setvideomode( _VRES16COLOR );
	_registerfonts( "roman.fon" );

	_setfont( "t'roman'h10w10v" );
	
	_clearscreen( _GCLEARSCREEN );

	for( i = 1; i <=15; i++ ) {
		_clearscreen( _GCLEARSCREEN );		
		_setcolor( i );
		_rectangle ( _GBORDER, 400, 50, 600, 200 );
		_moveto( 450, 100 );
		_outgtext( "TEST\nOUT" );		
		_outtext( "TEST\nOUT" );
    	temp = getche();
	}
	
	_unregisterfonts();
	_setvideomode( _DEFAULTMODE );
	return 0;
}