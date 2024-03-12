#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <bill.h>

#define TRUE 1
#define FALSE 0

void *billing_service(void *args){
    int service = TRUE;
    int seconds = 0;
    
    while(service){
        
        if(seconds > 2){
            printf("Bill executed\n");
            service = FALSE;
        }
        seconds+=1;
        sleep(1);
    }
    
    pthread_exit(NULL);
}

bill_t *start_billing_service(){

    bill_t *bill = NULL;
    
    /* Warning: malloc call */
    bill = malloc(sizeof(bill_t));

    if(pthread_create(&bill->thread, NULL, billing_service, NULL)){
        printf("Error on create billing service.");
        exit(-1);
    }

    return bill;
}

void end_bill_service(bill_t *self){
    pthread_join(self->thread, NULL);
    free(self);
}