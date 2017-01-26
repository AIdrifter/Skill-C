#ifndef LOGGER_H
#define LOGGER_H

#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"

#define PRO_TAG "TAG NAME"

//#define DEBUG_LOG_SYSTEM
typedef struct log_system
{
    // log
    size_t CA_LOG;
    size_t TA_LOG;
    size_t PARSE_CA_COMMAND;
    size_t PARSE_TA_COMMAND;
    size_t OPTEE_LOG;
    size_t FUNCTION_IN_OUT;

    // set property
    size_t AES_SW_MODE;

    // future
    size_t panding[100];
}log_system_t;

extern log_system_t g_log_system;
extern size_t g_log_level; // init CA or TA level in each OS


#define debug(level,format, args...) do {\
        if(level < g_log_level) break;\
        \
        switch(level)\
        case 0:\
                printf( RED"[ERROR](%u)[%s:%d] "format NONE, level, __FUNCTION__, __LINE__, ##args);\
                break;\
        case 1:\
                printf( GREEN"[INFO](%u)" format NONE,level, ##args);\
                break;\
        case 2:\
                printf( YELLOW"[WARN](%u) [%s:%d] "format NONE, level,__FUNCTION__, __LINE__, ##args);\
                break;\
        case 3:\
                printf( BLUE"[DEBUG](%u)[%s:%d] "format NONE, level,__FUNCTION__, __LINE__, ##args);\
                break;\
        case 4:\
                printf( WHITE"[TRACE](%u)[%s:%d]" format NONE, level,__FUNCTION__, __LINE__, ##args);\
                break;\
        case 5:\
                break;\
}while(0)

#define BEGIN() if(g_log_system.FUNCTION_IN_OUT) printf(PRO_TAG "ENTER %s() \n ",__func__)
#define END()   if(g_log_system.FUNCTION_IN_OUT) printf(PRO_TAG "EXIT  %s() \n",__func__)

#endif
