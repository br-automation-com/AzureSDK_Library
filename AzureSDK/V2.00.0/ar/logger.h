#ifndef _ARLOGGER_H_
#define _ARLOGGER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*Public API*/
void ArLoggerResetError();
char ArLoggerGetError();
unsigned long ArLoggerGetErrorCounter();
unsigned long ArLoggerInit();

void ArLogError(const char *format, ...);
void ArLogInfo(const char *format, ...);


#ifdef __cplusplus
}
#endif

#endif
