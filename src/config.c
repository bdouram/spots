/*********************
 ** System includes **
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*********************
 ** Custom includes **
 *********************/
#include "config.h"

config_t parse(int argc, char **argv)
{
    int c;
    config_t config = {1, 5, 4};

    while ((c = getopt(argc, argv, "n:m:r:h")) != -1)
    {
        switch (c) {
            case 'n':
                config.spots = atoi(optarg);
                break;
            case 'm':
                config.machines = atoi(optarg);
                break;
            case 'r':
                config.seed = atoi(optarg);
                break;
            case 'h':
                printf("Usage: %s [OPTIONS] \n\nOptions:\n", argv[0]);
                printf("  -s  Number of spot machines(default 1).\n");
                printf("  -h  Prints this help.\n");
            default:
                exit(1);
        }
    }

    return config;
}
