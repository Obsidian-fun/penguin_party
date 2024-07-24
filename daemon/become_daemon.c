/* Book: Linux Programming Interface, Pg:770 */

#include "sys/stat.h"
#include "fcntl.h"
#include "become_daemon.h"
#include "tlpi_hdr.h"

int becomeDaemon (int flags) {   	/* returns 0 on success -1 on error*/
	int maxfd, fd;

	switch (fork()) { 							/* become background process */
		case -1: return -1;
		case 0 : break;								/*Child falls through*/
		default: _exit(EXIT_SUCCESS);	/*While parent terminates*/
	}

	if (setsid == -1) {							/*Become leader of new session*/
		return -1;
	}

	switch(fork()) {
		case -1: return -1;
		case 0: break;
	  default: _exit(EXIT_SUCCESS);
	}	


}
