#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// How to handle SIGSEGV, but also generate a core dump

// Define shared libraries onload and onunload functions
void __attribute__ ((constructor)) MyLibOnLoad();
void __attribute__ ((destructor)) MyLibOnUnLoad();


// Remove IPC file when process received signal
void MyLibCrashHandler(int nSignal, siginfo_t* si, void* arg)
{
    // Get thread id
    pid_t nThreadID = syscall(SYS_gettid);

    printf("fucking here   [%s]---%d \n",__func__,__LINE__);
    // Write thread id into a file
    FILE* pf = fopen("crash_thread_id", "wt");
    if (pf != NULL)
    {
        fprintf(pf, "%d\n", nThreadID);
        fclose(pf);
    }

    // Send self the same signal again, so that default system signal handler is invoked,
    //   which will generate core dump files.
    kill(getpid(), nSignal);
}

void MyLibOnLoad()
{
    // Register signal handler for following signals:
    //   SIGBUS:  Bus error (bad memory access)
    //   SIGSEGV: Invalid memory reference
    // Here sigaction() is used instead of signal() to block other signals
    //  until current signal returns.
    struct sigaction sa = {};
    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = MyLibCrashHandler;
    sa.sa_flags = SA_SIGINFO|SA_RESETHAND;  // Reset signal handler to system default after signal triggered
    sigaction(SIGBUS, &sa, NULL);
    sigaction(SIGSEGV, &sa, NULL);
}


int main(){
    static int idx=0;
    while(1){
        printf("here %d\n ",idx++);
        sleep(1);
    }
}
