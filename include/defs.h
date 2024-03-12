#ifndef __DEFS_H__
#define __DEFS_H__

/* This header stores type definitions across the system. */

#define TRUE 1
#define FALSE 0

typedef struct {
    int spots;
    int machines;
} scheduler_props;

// Estrutura da fila
typedef struct node {
  int data;
  struct node *next;
} Node;

// Fila
typedef struct queue {
  Node *front;
  Node *rear;
} Queue;

#define DEBUG   0      /* Toggle (0 or 1) this macro if you want to disable all debug messages */


#if DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif


#endif