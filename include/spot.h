#ifndef __SPOT_H__
#define __SPOT_H__

#include <pthread.h>

typedef struct revocable{
    int _id;
    pthread_t thread;
} spot_t;

spot_t *burst_spots();
void terminate_all_spots(int spots, spot_t *revocable);

#endif