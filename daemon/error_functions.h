

#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void errMsg(const char *format,...);

#ifdef __GNUC__

/***
 * This macro stops 'gcc -Wall' complaining that "control reaches
 * to end of non-void function" if we use the following functions 
 * to terminate main() or some other non-void function.
***/

#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errExit(const char *format, ...) NORETURN ;
void err_exit(const char *format, ...) NORETURN ;
void errExitEN(int errnum, const char *format, ...) NORETURN ;
void fatal(const char *format, ...) NORETURN ;
void usageErr(const char *format, ...) NORETURN ;
void cmdLineErr(const char *format, ...) NORETURN ;
#endif

/*
To diagnose errors from system calls and library functions, we use errMsg(),
errExit(), err_exit(), and errExitEN().
*/


