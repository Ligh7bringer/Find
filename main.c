#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "load.h"

int main(int argc, char const *argv[])
{	
	char input[50] = "stdin\0";
	char output[50] = "stdout\0";
	char search[50];
	int ignore_case = 0;	

	strcpy(search, argv[1]);
	
	/* if(argc < 2) {
		printf("Wrong number of arguments\n");
		return 1;
	} */

	for(int i = 1; i < argc; ++i) {
		if(strcmp(argv[i], "-i") == 0) {
			strcpy(input, argv[i+1]);
		} else if(strcmp(argv[i], "-o") == 0) {
			strcpy(output, argv[i+1]);
		} else if(strcmp(argv[i], "-c") == 0) {
			ignore_case = true;
		} 		
	}

	load(input, output, search, ignore_case);

	return 0;
}