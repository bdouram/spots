#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <bill.h>
#include <cluster.h>
#include <config.h>
#include <scheduler.h>
#include <spot.h>
#include <defs.h>
#include <shared.h>
#include <queue.h>

int main(int argc, char *argv[]){

    bill_t *bill; sched_t *sched; spot_t *burst;
    scheduler_props sched_props;

    /* Parsing arguments. */
    config_t _config = parse(argc, argv); // ./program -n (spots) -m (machines) -r (seeds) -h (help)

    /* Feed the pseudo-random C module */
    srand(_config.seed); // You can change the program behavior changing -r flag.
    
    sched_props.machines = _config.machines;
    sched_props.spots = _config.spots;

    //initialize_sv(_config.spots, _config.machines);
    
    bill = start_billing_service(sched_props); // Payment initializing.
    sched = start_scheduler_service(_config.machines, _config.spots); // Scheduler initializing.
    burst = burst_spots(_config.machines); // Spot's burst.

    //shared_sv_props sv = get_sv();
    //enqueue(sv.queue, 1);
    //enqueue(get_sv().queue, 2);

    /**
     * In mathematics, the order of factors does not change the result (usually). 
     * In programming, it's not quite like that. 
     * Please note that if we change the order in which services are completed, the result is a complete disaster. 
     * Keep this order [terminate(spots,scheduler,bill)] so everything ends well.
    */
    terminate_all_spots(_config.machines, burst); // Terminating spots;
    end_scheduler_service(sched); // Terminating scheduler.
    end_bill_service(bill); // Terminating bill service.
    //destroy_sv();

    return 0; /** Houston, we landed. */
}