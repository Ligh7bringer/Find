The program was tested with both clang and gcc.

To compile, run 'make find'. 
'make clean' is used to delete object files and the executable. 

Usage: ./find needle
	-i haystack.txt
	-o output.txt (created if doesn't exist)
	-c ignore case

Examples:
	./find needle 	-> needle is earched for in text inputted from the command line
	./find needle -i test.txt 	-> needle is searched for in test.txt
	./find needle -i test.txt -o output.txt 	-> results are printed in output.txt
	./find needle -i test.txt -o output.txt -c 		-> needle will be searched for regardless of case