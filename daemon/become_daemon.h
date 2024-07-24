/* Book: Linux Programming Interface, Pg:770 */

#ifndef BECOME_DAEMON_H    /* to prevent double inclusion */
#define BECOME_DAEMON_H

/* Bit-mask values for 'flags' argument of becomeDaemon()  */

#define  BD_NO_CHDIR           01    /*Don't chdir, ie, don't change working directory*/
#define  BD_NO_CLOSE_FILES     02    /*Don't close all open files*/
#define  BD_NO_REOPEN_STD_FDS  04		 /**/
#define  BD_NO_UMASKO          010   /**/
#define  BD_MAX_CLOSE          8192  /**/




