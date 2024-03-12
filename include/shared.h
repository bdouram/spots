#ifndef __SHARED_H__
#define __SHARED_H__

/* This header stores type definitions across the system. */

#include <queue.h>

typedef struct {
    Queue *queue;
    int machines;
    int spots;
} shared_sv_props;

extern shared_sv_props sv;

void initialize_sv(int spots, int machines);
void destroy_sv();
shared_sv_props get_sv();

#endif