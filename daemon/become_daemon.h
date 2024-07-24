/* Book: Linux Programming Interface, Pg:770 */

#ifndef BECOME_DAEMON_H    /* to prevent double inclusion */
#define BECOME_DAEMON_H

/* Bit-mask values for 'flags' argument of becomeDaemon()  */

#define  BD_NO_CHDIR           01    /*Don't chdir, ie, don't change working directory*/
#define  BD_NO_CLOSE_FILES     02    /*Don't close all open files*/
#define  BD_NO_REOPEN_STD_FDS  04		 /*Don't reopen stdin, stdout, stderr to /dev/null */
#define  BD_NO_UMASKO          010   /*Don't do a umask(O)*/
#define  BD_MAX_CLOSE          8192  /*Maximum file descriptors to close if 
																			sysconf(_SC_OPEN_MAX) is indeterminate*/

int becomeDaemon(int flags);

#endif

