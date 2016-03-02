#include "find.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORDS 1000
#define WORD_LENGTH 30
#define LINE_LENGTH 200

void find(FILE* inp, FILE* outp, char search[50], int ignore_case, char input[50], char output[50]) {		
	char curr_line[LINE_LENGTH];
	char words[WORDS][WORD_LENGTH];
	int word = 0, character = 0, count = 0, line = 1;

	while(fgets(curr_line, LINE_LENGTH, inp) != NULL && !feof(inp)) {   
		if(ignore_case == 1 ) {
			for(int i = 0; i < strlen(curr_line); ++i) {				
				curr_line[i] = tolower(curr_line[i]);				
			}			
			for(int i = 0; i < strlen(search); ++i) {
				search[i] = tolower(search[i]); 
			}			
		}

		if(strstr(curr_line, search) != NULL && strcmp(output, "stdout") == 0) {			
	 		fprintf(outp, "Found %s on line %i:\n %s\n\n", search, line, curr_line);
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
	}  
	
	for (int j = 0; j < word; ++j) {		
		char *result = strstr(words[j], search);
		if (result == NULL)			
			continue;
		if(strcmp(output, "stdout") != 0) {			
			fprintf(outp, "-%s\n", words[j]);
		} else {			
			fprintf(outp, "-%s\n", words[j]);		}
		count++; 
	}

	if(count == 0 && strcmp(output, "stdout") != 0) 
		fprintf(outp, "%s\n", "Word not found.\n");
	else if(count == 0 && strcmp(output, "stdout") == 0) 
		fprintf(outp, "%s\n", "Word not found.\n");
	
	fclose(inp);
	fclose(outp);
}
