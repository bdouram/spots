#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <scheduler.h>

#define TRUE 1
#define FALSE 0

void *scheduler_service(void *args) {
    
    int service = TRUE;
    int seconds = 0;
    
    while(service){
        
        if(seconds > 2){
            printf("Scheduler executed\n");
            service = FALSE;
        }
        seconds+=1;
        sleep(1);
    }
    
    pthread_exit(NULL);
}

sched_t *start_scheduler_service(){

    sched_t *sched = NULL;
    
    /* Warning: malloc call */
    sched = malloc(sizeof(sched_t));

    if(pthread_create(&sched->thread, NULL, scheduler_service, NULL)){
        printf("Error on create scheduler service.");
        exit(-1);
    }

    return sched;
}

void end_scheduler_service(sched_t *worker){
    pthread_join(worker->thread, NULL);
    free(worker);
}