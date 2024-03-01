#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <bill.h>
#include <cluster.h>
#include <config.h>
#include <scheduler.h>
#include <spot.h>

#define WORKERS   2


int main(int argc, char *argv[]){

    bill_t *bill; sched_t *sched; spot_t *burst;

    /* Parsing arguments. */
    config_t _config = parse(argc, argv); // ./program -n (spots) -m (machines) -r (seeds) -h (help)

    /* Feed the pseudo-random C module */
    srand(_config.seed); // You can change the program behavior changing -r flag.
    

    bill = start_billing_service(); // Payment initializing.
    sched = start_scheduler_service(); // Scheduler initializing.
    burst = burst_spots(_config.machines); // Spot's burst.


    /**
     * In mathematics, the order of factors does not change the result (usually). 
     * In programming, it's not quite like that. 
     * Please note that if we change the order in which services are completed, the result is a complete disaster. 
     * Keep this order [terminate(spots,scheduler,bill)] so everything ends well.
    */
    terminate_all_spots(_config.machines, burst); // Terminating spots;
    end_scheduler_service(sched); // Terminating scheduler.
    end_bill_service(bill); // Terminating bill service.

    return 0; /** Houston, we landed. */
}