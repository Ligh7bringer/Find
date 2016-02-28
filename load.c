#include "load.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define WORDS 500
#define WORD_LENGTH 30
#define LINE_LENGTH 200
#define MAX 5000

void load(char input[50], char output[50], char search[50]) {	
	char words[WORDS][WORD_LENGTH];
	int word = 0, character = 0, count = 0, line = 1;
	char curr_line[LINE_LENGTH];	

	FILE *inp = fopen(input, "r");
	if(strcmp(input, "stdin") == 0) {
		inp = stdin;
		printf("Enter text:\n");
	}
	if(inp == NULL)
		printf("File to be read not found.\n");

   	FILE * outp = fopen(output, "w");	
   	if(strcmp(output, "stdout") == 0) {   		
    	remove(output);    	
	}	
	if(outp == NULL) {
	   		printf("Something went wrong with output file.\n"); 	
	}

	while(fgets(curr_line, LINE_LENGTH, inp) != NULL) {   
		if(strstr(curr_line, search) != NULL && strcmp(output, "stdout") == 0) {			
			printf("Found %s on line %i:\n %s\n\n", search, line, curr_line);
		} else if(strstr(curr_line, search) != NULL && strcmp(output, "stdout") != 0) {			
			fprintf(outp, "Found %s on line %i:\n %s\n\n", search, line, curr_line);
		}

		for(int l = 0; l < strlen(curr_line); l++) {
			if(curr_line[l] == '\n' || curr_line[l] == ' ' || curr_line[l] == '.' || curr_line[l] == ',' || curr_line[l] == '?' || curr_line[l] == '!' || curr_line[l] == '.')  {
   				word++;
   				character = 0;   
   			} else {							
	   			words[word][character] = curr_line[l];  	   			
	   			character++;
	   		}
   		}  
   		line++;
   		break;
	}  

	
	for (int j = 0; j < word; ++j) {		
		char *result = strstr(words[j], search);
		if (result == NULL)			
			continue;
		if(strcmp(output, "stdout") != 0) {			
			fprintf(outp, "-%s\n", words[j]);
		} else {			
			printf("-%s\n", words[j]);
		}
		count++; 
	}

	if(count == 0 && strcmp(output, "stdout") != 0) 
		fprintf(outp, "%s\n", "Word not found.\n");
	else if(count == 0 && strcmp(output, "stdout") == 0) 
		printf("%s\n", "Word not found."); 

	fclose(inp);
	fclose(outp);
}