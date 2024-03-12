#include <shared.h>
#include <defs.h>


shared_sv_props sv;

void initialize_sv(int spots, int machines){
    sv.queue = create_queue();
    sv.machines = machines;
    sv.spots = spots;
}

void destroy_sv(){
    while(is_queue_empty(sv.queue) == FALSE)
        dequeue(sv.queue);
}

shared_sv_props get_sv(){
    return sv;
}