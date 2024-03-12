#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

// Cria uma nova fila
Queue *create_queue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// Verifica se a fila está vazia
int is_queue_empty(Queue *queue) {
  return (queue->front == NULL);
}

// Enfileira um elemento
void enqueue(Queue *queue, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (is_queue_empty(queue)) {
    queue->front = queue->rear = newNode;
  } else {
    debug("Entered here")
    queue->rear->next = newNode;
    queue->rear = newNode;
  }

  debug("Inserted %d on queue \n", data);

}

// Desenfileira um elemento
int dequeue(Queue *queue) {
  if (is_queue_empty(queue)) {
    printf("Fila vazia!\n");
    return -1;
  }

  int data = queue->front->data;
  Node *temp = queue->front;
  queue->front = queue->front->next;

  if (queue->front == NULL) {
    queue->rear = NULL;
  }


  debug("Dequeued %d \n", data);

  free(temp);
  return data;
}

// Mostra a fila
void print_queue(Queue *queue) {
  if (is_queue_empty(queue)) {
    printf("Fila vazia!\n");
    return;
  }

  Node *temp = queue->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}
