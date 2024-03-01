#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

// Global flag to indicate if the signal was received
volatile sig_atomic_t signal_received = 0;

// Signal handler for SIGUSR1
void sigusr1_handler(int signum) {
    signal_received = 1;
}

void *thread_function(void *arg) {
    printf("Thread is running\n");

    // Install signal handler
    signal(SIGUSR1, sigusr1_handler);

    // Wait for a signal
    while (!signal_received) {
        // Do some work or wait
    }

    printf("Thread received SIGUSR1\n");

    while(1);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    // Create the thread
    if (pthread_create(&thread, NULL, thread_function, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Sleep for a while to let the thread run
    sleep(2);

    // Send a signal to the thread
    pthread_kill(thread, SIGUSR1);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    printf("Main thread exiting\n");
    return 0;
}
