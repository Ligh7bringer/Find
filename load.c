#include "load.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define SIZE 500
#define LINE_LENGTH 200

void load(char input[50], char output[50], char search[50]) {	
	char words[SIZE][SIZE];
	int word = 0, character = 0, count = 0, k = 0, pos = 0;
	char curr_line[LINE_LENGTH], line = 0;
	
	FILE *inp = fopen(input, "r");
	if(inp == NULL) 
   		printf("File not found. (Maybe it's not in the same folder?)\n"); 	

   	FILE * outp = fopen(output, "w");	
   	if(strcmp(output, "stdout") == 0) {
    	remove(output);
	}	

	while(fgets(curr_line, LINE_LENGTH, inp) != NULL) {   
		if(strstr(curr_line, search) != NULL) {
			printf("Found %s on line %i: %s\n", search, line, curr_line);
		}
		for(int l = 0; l < strlen(curr_line); l++) {
			if(curr_line[l] == '\n' ||curr_line[l] == ' ' || curr_line[l] == '.' || curr_line[l] == ',' || curr_line[l] == '?' || curr_line[l] == '!' || curr_line[l] == '.')  {
   				word++;
   				character = 0;   
   			} else {		
				//printf("READ CHARACTER: %c\n", curr_line[l]);
				//printf("pos: %i and l: %i\n", pos, l);								
	   			words[word][character] = curr_line[l];  
	   			//printf("CHARACTER STORED IN WORDS ARRAY: %c\n", words[word][character]); 				
	   			character++;
	   		}
   		}  
   		line++;
	}  
	fclose(inp);

	for (int j = 0; j < word; ++j) {
		//printf("%s\n",words[j]);		
		char *result = strstr(words[j], search);
		if (result == NULL)			
			continue;
		if(strcmp(output, "stdout") != 0)
			fprintf(outp, "%s\n", words[j]);
		else printf("%s\n", words[j]);
			count++; 
	}

	if(count == 0 && strcmp(output, "stdout") != 0) 
		fprintf(outp, "%s\n", "Word not found.\n");
	else if(count == 0 && strcmp(output, "stdout") == 0) 
		printf("%s\n", "Word not found."); 

	fclose(outp);
}