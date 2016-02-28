#include "findLine.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void findLine(char curr_line[200], char search[30], char output[50], FILE *outp, int line) {
	if(strstr(curr_line, search) != NULL && strcmp(output, "stdout") == 0) {			
 		printf("Found %s on line %i:\n %s\n\n", search, line, curr_line);
	} else if(strstr(curr_line, search) != NULL && strcmp(output, "stdout") != 0) {			
		fprintf(outp, "Found %s on line %i:\n %s\n\n", search, line, curr_line);
	}
}
