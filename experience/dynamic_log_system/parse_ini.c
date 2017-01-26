#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "log.h"

#define LOG_PATH "./moduleinfo.ini"
#define LOG_LINE_LENGTH 30

// global log level
size_t g_log_level;

// init CA log system
log_system_t g_log_system = {0};

#define PARSE_LOG_STR(line,STR)do{ \
        if(memcmp(line,#STR,strlen(#STR))==0) \
        { \
            char *c_ptr = strtok(line,"="); \
            c_ptr = strtok(NULL,"=");   \
            g_log_system.STR = atoi(c_ptr); \
            printf( YELLOW "     %s is %d \n" NONE,#STR,g_log_system.STR); \
        }\
}while(0);

static void parse_ini(void)
{
    FILE *log_fptr = NULL;
    char line[256]={ 0 };
    size_t outBufferLen = 0;

    log_fptr = fopen(LOG_PATH,"rt");
    if(log_fptr==NULL)
            return;

    printf( YELLOW "     ======  DEBUG SYSTEM =====\n" NONE);
    //--READ each line
    while(fgets(line,LOG_LINE_LENGTH,log_fptr)!=NULL)
    {
        //--ignore mark
        if(line[0]=='#')
        {
            memset(line,0,256);
            continue;
        }

        PARSE_LOG_STR(line,CA_LOG);
        PARSE_LOG_STR(line,TA_LOG);
        PARSE_LOG_STR(line,PARSE_CA_COMMAND);
        PARSE_LOG_STR(line,PARSE_TA_COMMAND);
        PARSE_LOG_STR(line,OPTEE_LOG);
        PARSE_LOG_STR(line,AES_SW_MODE);

    }
    printf( YELLOW "     ==============================\n" NONE);

    if(log_fptr)
        fclose(log_fptr);

    g_log_level = g_log_system.CA_LOG;

    // send log structure to TEE
ErrorExit:
    return ;
}


int main()
{
    parse_ini();
}
