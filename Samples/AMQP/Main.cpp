
#include <bur/plctypes.h>
#include <ar/logger.h>
#include <azure_c_shared_utility/threadapi.h>
#include "iothub_client_sample_amqp.h"

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

// amount of memory to be allocated for heap storage must be specified for every ANSI C++ program with the bur_heap_size variable
unsigned long bur_heap_size = 0xFFFF; 

void _INIT ProgramInit(void)
{
	// Insert code here 
	ArLoggerInit();
}

BOOL running;
extern BOOL g_continueRunning;
THREAD_HANDLE ThreadIdent;

//non-cyclic program thread
int ProgramMain(void* args)
{
   iothub_client_sample_amqp_run(); //run until done; g_continueRunning set to zero, or "quit" message received
   g_continueRunning = 0;
   running = 0;
   return 0;
}

void _CYCLIC ProgramCyclic(void)
{
	if(g_continueRunning && !running)
	{
		running = 1;
		ThreadAPI_Create(&ThreadIdent, ProgramMain, 0);
	}
}

void _EXIT ProgramExit(void)
{
	ThreadAPI_Join(ThreadIdent, 0);
}
