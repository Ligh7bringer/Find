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
	bool ignore_case = false;	

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

	load(input, output, search);


	//printf("%s", words[0]);
	//search_for_word(argv[1])
	//output_results(output)
	//exit....
	return 0;
}