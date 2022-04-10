#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   	#include <io.h>
	#define F_OK 0
	#define access _access	
#elif __APPLE__
    #include <TargetConditionals.h>
   	#if TARGET_OS_MAC
		// Other kinds of Apple platforms
		#include <unistd.h>
    #else
		// if it returns to be an apple device, but it doesn't get checked by those above, it will return apple unknown
		#include <unistd.h>
    #endif
#elif __linux__
	#include <unistd.h>
#elif __unix__ // all unices not caught above
	#include <unistd.h>
#elif defined(_POSIX_VERSION)
	#include <unistd.h>
#else
	#   error "Unknown compiler"
#endif

#include "core.h"

// TODO: Improve error messages

// Parse CoreScript standard functions
int standard(struct Memory *memory, struct Lang *core, struct Tree *tree, int line) {
	// Make a simple pointer to the first part
	char *first = tree->parts[0].value;

	char string[MAX_STRING] = {0};
	if (!strcmp(first, core->command[0].first)) {
		// print
		parseString(string, tree, memory);
		puts(string);
	} else if (!strcmp(first, core->command[1].first)) {
		// var
		parseString(string, tree, memory);
		createVariable(
			tree->parts[1].value,
			string,
			memory
		);
	} else if (!strcmp(first, core->command[2].first)) {
		// set
		parseString(string, tree, memory);
		setVariable(
			tree->parts[1].value,
			string,
			memory
		);
	} else if (!strcmp(first, core->command[3].first)) {
		// goto
		parseString(string, tree, memory);

		// Subtract one because the loop will move ahead
		// after setting
		int tryLabel = gotoLabel(
			string,
			line,
			memory
		);

		if (tryLabel == -1) {
			printf("%s%d%s\n", "Line ", line + 1, ": Label not found");
			return tryLabel;
		} else {
			line = tryLabel;
		}
	} else if (!strcmp(first, core->command[4].first)) {
		// if
		parseString(string, tree, memory);

		int error = 0;
		int tryLine = testCondition(
			&error,
			tree->parts[2].value,
			tree->parts[1].value,
			string,
			line,
			memory
		);

		// Exit if error is -5, which means it is false,
		// not really an error.
		if (error == FALSE) {
			return line;
		}

		if (error != 0) {
			printf("%d %s%d\n", line + 1, "Error parsing condition: ", error);
			return error;
		} else {
			// Subtract one because the loop will move ahead
			// after setting, same did with goto
			line = tryLine;
		}
	} else if (!strcmp(first, core->command[5].first)) {
		// return
		parseString(string, tree, memory);

		int tryLabel = findLabel(
			string,
			memory
		);

		if (tryLabel == -1) {
			printf("%s%d\n", "Label not Found: ", tryLabel);
			return tryLabel;
		} else {
			line = memory->labels[tryLabel].lastUsed;
		}
	} else if (!strcmp(first, core->command[6].first)) {
		// system call / sys
		parseString(string, tree, memory);
		system(string);
	}
	else if (!strcmp(first, core->command[7].first)) {
		// mkdir
		char parseddirpath[100];
		parseString(string, tree, memory);
		sprintf(parseddirpath, "mkdir %s", string);
		system(parseddirpath);
	} else if (!strcmp(first, core->command[8].first)) {
		// rmdir
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   			char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "del %s", string);
			system(parseddirpath);
		#elif __APPLE__
    		#include <TargetConditionals.h>
   			#if TARGET_OS_MAC
				// Other kinds of Apple platforms
        		char parseddirpath[100];
				parseString(string, tree, memory);
				sprintf(parseddirpath, "rm -rf %s", string);
				system(parseddirpath);
    		#else
				// if it returns to be an apple device, but it doesn't get checked by those above, it will return apple unknown
    			char parseddirpath[100];
				parseString(string, tree, memory);
				sprintf(parseddirpath, "rm -rf %s", string);
				system(parseddirpath);
			#endif
		#elif __linux__
    		char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "rm -rf %s", string);
			system(parseddirpath);
		#elif __unix__ // all unices not caught above
    		char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "rm -rf %s", string);
			system(parseddirpath);
		#elif defined(_POSIX_VERSION)
    		char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "rm -rf %s", string);
			system(parseddirpath);
		#else
		#   error "Unknown compiler"
		#endif
	} else if (!strcmp(first, core->command[9].first)) {
		// mk
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   			char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "echo. >> %s", string);
			system(parseddirpath);
		#elif __APPLE__
    		#include <TargetConditionals.h>
   			#if TARGET_OS_MAC
				// Other kinds of Apple platforms
        		char parseddirpath[100];
				parseString(string, tree, memory);
				sprintf(parseddirpath, "touch %s", string);
				system(parseddirpath);
    		#else
				// if it returns to be an apple device, but it doesn't get checked by those above, it will return apple unknown
    			char parseddirpath[100];
				parseString(string, tree, memory);
				sprintf(parseddirpath, "touch %s", string);
				system(parseddirpath);
			#endif
		#elif __linux__
    		char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "touch %s", string);
			system(parseddirpath);
		#elif __unix__ // all unices not caught above
    		char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "touch %s", string);
			system(parseddirpath);
		#elif defined(_POSIX_VERSION)
    		char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "touch %s", string);
			system(parseddirpath);
		#else
		#   error "Unknown compiler"
		#endif
	} else if (!strcmp(first, core->command[10].first)) {
		// rem
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   			char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "del %s", string);
			system(parseddirpath);
		#elif __APPLE__
    		#include <TargetConditionals.h>
   			#if TARGET_OS_MAC
				// Other kinds of Apple platforms
        		char parseddirpath[100];
				parseString(string, tree, memory);
				sprintf(parseddirpath, "rm %s", string);
				system(parseddirpath);
    		#else
				// if it returns to be an apple device, but it doesn't get checked by those above, it will return apple unknown
    			char parseddirpath[100];
				parseString(string, tree, memory);
				sprintf(parseddirpath, "rm %s", string);
				system(parseddirpath);
			#endif
		#elif __linux__
    		char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "rm %s", string);
			system(parseddirpath);
		#elif __unix__ // all unices not caught above
    		char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "rm %s", string);
			system(parseddirpath);
		#elif defined(_POSIX_VERSION)
    		char parseddirpath[100];
			parseString(string, tree, memory);
			sprintf(parseddirpath, "rm %s", string);
			system(parseddirpath);
		#else
		#   error "Unknown compiler"
		#endif
	} else if (!strcmp(first, core->command[11].first)) {
		// input
		parseString(string, tree, memory);
		printf(string);
		char input[100];
		fgets(input,100,stdin);
		createVariable(
			tree->parts[1].value,
			input,
			memory
		);
	} else if (!strcmp(first, core->command[12].first)) {
		// nprint
		parseString(string, tree, memory);
		printf(string);
	} 

	return line;
}
