#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <scheduler.h>
#include <defs.h>

#define TRUE 1
#define FALSE 0

int *create_tokens(int machines){

    /* Warning: malloc call */
    int *tokens = (int *)malloc(machines * sizeof(int));
    
    if (tokens == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit program
    }

    for (int i = 0; i < machines; i++)
        tokens[i] = i * 10; /** Feed the array with some token id*/

    return tokens;
}


void destroy_tokens(int *tokens){
    free(tokens);
}



void *scheduler_service(void *args) {
    
    scheduler_props *props = (scheduler_props *)args;

    int service = TRUE;
    int seconds = 0;
    
    //int spots = props->spots;
    int *tokens = create_tokens(props->machines);
    

    while(service){
        
        if(seconds > 2){
            printf("Scheduler executed\n");
            service = FALSE;
        }
        
        seconds+=1;

        sleep(1);
    }

    destroy_tokens(tokens);
    pthread_exit(NULL);
}

sched_t *start_scheduler_service(scheduler_props props){

    sched_t *sched = NULL;
    
    /* Warning: malloc call */
    sched = malloc(sizeof(sched_t));

    if(pthread_create(&sched->thread, NULL, scheduler_service, (void *)&props)){
        printf("Error on create scheduler service.");
        exit(-1);
    }

    return sched;
}

void end_scheduler_service(sched_t *worker){
    pthread_join(worker->thread, NULL);
    free(worker);
}