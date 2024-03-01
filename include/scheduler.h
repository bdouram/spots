#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

typedef struct sched{
    int _id;
    pthread_t thread;
} sched_t;

sched_t *start_scheduler_service();
void end_scheduler_service();

#endif