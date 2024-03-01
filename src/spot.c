#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <spot.h>
#include <scheduler.h>

#define TRUE 1
#define FALSE 0

void *spot_service(void *args){

    int service = TRUE;
    int seconds = 0;
    
    while(service){
        
        if(seconds > 2){
            printf("Spot executed\n");
            service = FALSE;
        }

        seconds+=1;
        sleep(1);
    }
    
    pthread_exit(NULL);
}

spot_t *burst_spots(int spots){

    spot_t *revocables = NULL;
    int idx;

    /* Warning: malloc call */
    revocables = malloc(sizeof(spot_t) * spots);

    for (idx = 0; idx < spots; idx++){
        revocables[idx]._id = idx; /* Spot id */
        if (pthread_create(&revocables[idx].thread, NULL, spot_service, NULL)){
            printf("Error on create thread for spot burst.");
            exit(-1);
        }
    }

    return revocables;
}


void terminate_all_spots(int spots, spot_t *revocables){
    int idx;
    for (idx = 0; idx < spots; idx++){
        pthread_join(revocables[idx].thread, NULL);
    }
    free(revocables);
}

void clear_spot(spot_t *self){
    pthread_join(self->thread, NULL);
    free(self);
}
