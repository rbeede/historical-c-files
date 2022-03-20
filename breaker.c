#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

main() {
	int i, j;
	int strend;
	char Password[15];
	int PasswordPart[15];
	char Guess[15];
	char StartTimeDate[50];
	char StopTimeDate[50];
	char temp[25];
	
	printf( "\nNumber of Characters   Time\n" );
	printf( "1                      0 Seconds\n" );
	printf( "2                      0 Seconds\n" );
	printf( "3                      1 Second\n" );
	printf( "4                      1 Minute 13 Seconds\n" );
	printf( "5                      2 Hours 32 Seconds\n" );
	printf( "6                      10 1/2 Days?\n" );
	printf( "7                      2.6 Years?\n" );
	printf( "8                      2.5 Centuries?\n" );  
	
	printf( "\nEnter a password to break: " );
	scanf( "%s", Password );
 
	_strtime( temp );
	strcpy( StartTimeDate, temp );
	strcat( StartTimeDate, "  " );
	
	_strdate( temp );
	strcat( StartTimeDate, temp );

	do  {
		for( i = 32; i <= 126; i++ ) {
			PasswordPart[0] = i;

            strcpy( Guess, "" );
						
			for( j = 0; j <= 7; j++ ) {
				if( (PasswordPart[j] < 32) || (PasswordPart[j] > 126) ) {
					Guess[j] = '\0';
					strend = j+2;
					break;
				}
				else {
					Guess[j] = PasswordPart[j];
					Guess[j+1] = '\0';
				}
			}

			if( strncmp( Guess, Password, strend ) == 0 ) {
				_strtime( temp );
				strcpy( StopTimeDate, temp );
				strcat( StopTimeDate, "  " );
				
				_strdate( temp );
				strcat( StopTimeDate, temp );
				printf( "\nYour password is %s.\nStart time and date was %s and stop time and date was %s.", Guess, StartTimeDate, StopTimeDate );
						 
				return 0;
			}  //If-Block

			//Try to force a compare twice
			if( strncmp( Guess, Password, strend ) == 0 ) {
				_strtime( temp );
				strcpy( StopTimeDate, temp );
				strcat( StopTimeDate, "  " );
				
				_strdate( temp );
				strcat( StopTimeDate, temp );
				printf( "\nYour password is %s.\nStart time and date was %s and stop time and date was %s.", Guess, StartTimeDate, StopTimeDate );
						 
				return 0;
			}  //If-Block

		}  //For-Loop-Block

		if( PasswordPart[1] < 32 ) {
			PasswordPart[1] = 31;
		}  
		
		PasswordPart[1]++;
		
		for( i = 1; i <= 7; i++ ) {
			if( PasswordPart[i] > 126 ) {
				PasswordPart[i] = 32;
				
				if( PasswordPart[i+1] < 32 ) {
					PasswordPart[i+1] = 31;	
                }
                
	        	PasswordPart[i+1]++;
	        }
	        else {
	        	break;
	        }
		}  //For-Loop-Block
		
		if( PasswordPart[8] == 32 ) {
			_strtime( temp );
			strcpy( StopTimeDate, temp );
			strcat( StopTimeDate, "  " );
				
			_strdate( temp );
			strcat( StopTimeDate, temp );
	
			printf( "Could not break password.\nStart time and date was %s and stop time and date was %s.", StartTimeDate, StopTimeDate );
			
			return 0;
		}  //If-Block
	} while( 1 == 1);  //Do-Loop-Block
	
	return 0;
}