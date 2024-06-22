/***
List process ID and parent process ID
***/

#include "stdio.h"
#include "unistd.h"

int main() {
	printf("The process ID is %d\n", (int) getpid());
	printf("The parent process IS is %d\n", (int) getppid());

	return 0;
}
