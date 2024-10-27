// Implementation of the usleep command

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char **argv ){
	// Make sure there is only one argument:
	if( argc == 1 ){
		printf( "%s: Needs an integer value (microseconds to sleep).\n", argv[0] );
		exit( 1 );
	}
	if( argc > 2 ){
		printf( "%s: Too many arguments.\n", argv[0] );
		exit( 1 );
	}
	// Make sure the argument is a positive integer:
	int len = strlen( argv[1] );
	for( int i = 0; i < len; i++ ){
		if( argv[1][i] < '0' || argv[1][i] > '9' ){
			printf( "%s: %s: Argument must be a positive integer.\n", argv[0], argv[1] );
			exit( 2 );
		}
	}
	usleep( atoi( argv[1] ) );
	return 0;
}
