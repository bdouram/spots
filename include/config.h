#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdio.h>

/*============================================================================*
 * Configuração                                                               *
 *============================================================================*/



#define FALSE                    0
#define TRUE                     1
#define NULL                    ((void *)0)

typedef struct config {
    unsigned int spots;
    unsigned int machines;
    unsigned int seed;
} config_t;

extern config_t config;
extern config_t parse(int argc, char **argv);

#ifndef NDEBUG
    #define plog(...) printf(__VA_ARGS__); fflush(stdout)
#else
    #define plog(...)
#endif


#endif /*__CONFIG_H__*/