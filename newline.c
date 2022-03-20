#include <stdio.h>
#include <string.h>

void main() {
	char str[]="This_is_a_test.This_is_a_test.This_is_a_test.This_is_a_test.This_is_a_test.";
	char nstr[100];
	char temp[5];
	int j, k, l;
	
	strcpy( nstr, str );
		
	k = strlen( str );
	
	for( j = 0; j < k; j++ ) {
		if( (j + 1) % 50 == 0 ) {
			for ( l = k; l > j; l-- ) {
				*temp = nstr[l];
				nstr[l+1] = *temp; 
			}          
			nstr[j+1] = '\n';
			k++;
		}
	}
							
	strcpy( str, nstr );
	
	printf( "%s", str );
	printf( "\n         1         2         3         4         5" );
	printf( "\n12345678901234567890123456789012345678901234567890" );
	
}