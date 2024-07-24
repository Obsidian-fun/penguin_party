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

	if (setsid() == -1) {							/*Become leader of new session*/
		return -1;
	}

	switch(fork()) {								/*Ensure we are not leader of new session*/
		case -1: return -1;
		case 0: break;
	  default: _exit(EXIT_SUCCESS);
	}	

	if (!(flags & BD_NO_UMASKO)) {	/*clear file mode creation mask*/
		umask(0);
	}

	if (!(flags & BD_NO_CHDIR)) {  /*change to root directory*/
		chdir("/");
	}

	if (!(flags & BD_NO_CLOSE_FILES)) { /*close all open files*/
		maxfd = sysconf(_SC_OPEN_MAX);
		if (maxfd == -1) {								/*limit is indeterminate*/
			maxfd = BD_MAX_CLOSE;						/*taking a guess*/
		}
		for (fd=0; fd < maxfd; fd ++) {
			close(fd);
		}
	}

	if (!(flags & BD_NO_REOPEN_STD_FDS)) {
		close(STDIN_FILENO); 								/*reopen standard fd's to /dev/null */

		fd = open("/dev/null",O_RDWR);

		if (fd != STDIN_FILENO) {
			return -1;												/*fd should be 0*/
		}		

		if (dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO) {
			return -1;
		}

		if (dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO) {
			return -1;
		}
	}

	return 0;
}
