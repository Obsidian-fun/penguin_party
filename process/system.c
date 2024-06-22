/***
Execute a command from within the program

***/

#include "stdlib.h"

int main() {
	int return_value;
	return_value = system("ls -l");
	return return_value;
}


