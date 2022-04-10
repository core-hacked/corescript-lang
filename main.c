#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core.h"

void runCorescript(char **code, int lineCount) {
	struct Memory *memory = malloc(sizeof(struct Memory));
	memory->variablesLength = 0;
	memory->labelsLength = 0;

	// default variables
	createVariable("cos.empty", "", memory);
	createVariable("cos.space", " ", memory);
	createVariable("cos.newline", "\n", memory);
	char* whichosvar = "os.pinpoint"; // are we on arch btw?

	// check operating system variable
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
		// check for win64 or win32
   		#ifdef _WIN64
      		createVariable(whichosvar, "win64", memory);
   		#else
      		createVariable(whichosvar, "win32", memory);
		#endif
	#elif __APPLE__
    	#include <TargetConditionals.h>
    	#if TARGET_OS_MAC
			// Mac OS basically
        	createVariable(whichosvar, "apple", memory);
    	#else
			// if it returns to be an apple device, but it doesn't get checked by the check above, it will return apple unknown
    		createVariable(whichosvar, "apple-unknown", memory);
		#endif
	#elif __linux__
    	createVariable(whichosvar, "linux", memory);
	#elif __unix__ // all unices not caught above
    	createVariable(whichosvar, "unix", memory);
	#elif defined(_POSIX_VERSION)
    	createVariable(whichosvar, "posix", memory);
	#else
		// if nothing above works, return unknown
		createVariable(whichosvar, "unknown", memory);
	#endif

	// Test for labels
	struct Tree tree;
	for (int l = 0; l < lineCount; l++) {
		tree = parse(
			&english,
			code[l]
		);

		// store label if parser detected it
		if (tree.ignore && tree.ignoreType == ':') {
			strcpy(memory->labels[memory->labelsLength].name, tree.parts[0].value);
			memory->labels[memory->labelsLength].line = l;
			memory->labelsLength++;
		}
	}

	for (int l = 0; l < lineCount; l++) {
		tree = parse(
			&english,
			code[l]
		);

		if (tree.ignore) {
			continue;
		}

		// parse command directly from "standard library"
		l = standard(
			memory,
			&english,
			&tree,
			l
		);
	}

	free(memory);
}
 
int main(int argc, char *argv[]) {
	if (argc == 1 || argv[1][0] == '?') {
		puts("<=== CoreScript v1.0.0 ===> \nUsage: corescript <file>");
		return 0;
	}

	// used twice, reset for the second usage
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		puts("File reading error.");
		return -1;
	}

	// count file length
	char temp[MAX_LINE_LENGTH];
	int lineCount = 0;
	while (fgets(temp, MAX_LINE_LENGTH, file) != NULL) {
		lineCount++;
	}

	fseek(file, 0, SEEK_SET);

	// allocate pointer to the string array
	char **code = malloc(lineCount * sizeof(char **));

	// store the program into the allocated array
	char read[MAX_LINE_LENGTH];
	int line = 0;
	while (fgets(read, MAX_LINE_LENGTH, file) != NULL) {
		code[line] = malloc(MAX_LINE_LENGTH * sizeof(char));
		strtok(read, "\n"); // remove trailing \n
		strcpy(code[line], read);
		line++;
	}

	fclose(file);
	
	runCorescript(code, lineCount);	

	for (int i = 0; i < line; i++) {
		free(code[i]);
	}

	free(code);
}
