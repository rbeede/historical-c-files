#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 80

main( int argc, char *argv[] )
{
	FILE *ip, *op;
	char line[MAX_LINE];
	void crypt( char * );
	
	if (argc != 3)
	{
		printf("crypt file1 file2\n");
		exit(-1);
	}
	if ((ip = fopen(argv[1], "r")) == NULL)
	{
		printf("Cannot open file %s\n", argv[1]);
		exit(-2);
	}
	if ((op = fopen(argv[2], "w")) == NULL)
	{
		printf("Cannot open file %s\n", argv[2]);
		exit();
	}
	while (fgets(line, (sizeof(line) - 1), ip) != NULL)
	{
		crypt( line );
		fputs(line, op);
	}
	fclose( ip );
	fclose( op );
}

void crypt( char *sp )
{
	int c;
	
	for( c = *sp; c != '\n'; sp++, c = *sp)
	{
		*sp = (c+2);
	}
	return;
}
		