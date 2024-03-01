#ifndef __BILL_H__
#define __BILL_H__

#include <pthread.h>

typedef struct collector{
    int _id;
    pthread_t thread;
} bill_t;

bill_t *start_billing_service();
void end_bill_service(bill_t *worker);

#endif