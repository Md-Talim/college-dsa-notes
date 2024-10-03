#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int front, rear, capacity;
  int *queue;
};

// Function to initialize the queue
struct Queue *createQueue(int capapcity)
{
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->capacity = capapcity;
  q->front = 0;
  q->rear = -1;
  q->queue = (int *)malloc(q->capacity * sizeof(int));
}

// inserts an element at the rear of the queue
void enqueue(struct Queue *q, int data)
{
  // check if the queue is full
  if (q->rear == q->capacity - 1)
  {
    printf("Queue is full\n");
    return;
  }

  // insert element at the rear
  q->queue[++q->rear] = data;
}

// deletes an element from the front of the queue
void dequeue(struct Queue *q)
{
  // if the queue is empty
  if (q->front > q->rear)
  {
    printf("Queue is empty\n");
    return;
  }

  // shift all elements from index 1 till rear to the left by one
  for (int i = 0; i < q->rear; i++)
  {
    q->queue[i] = q->queue[i + 1];
  }

  // decrement rear
  q->rear--;
}

// prints all the queue elements
void display(struct Queue *q)
{
  // check if the queue is empty
  if (q->front > q->rear)
  {
    printf("Queue is empty\n");
    return;
  }

  // traverse front to rear and print elements
  for (int i = q->front; i <= q->rear; i++)
  {
    printf("%d | ", q->queue[i]);
  }

  printf("\n");
}

// prints the front elment of the queue
void front(struct Queue *q)
{
  if (q->rear == -1)
  {
    printf("Queue is empty\n");
    return;
  }

  printf("Front Element is: %d\n", q->queue[q->front]);
}

int main()
{
  struct Queue *q = createQueue(4);

  display(q);

  enqueue(q, 20);
  enqueue(q, 30);

  display(q);

  enqueue(q, 40);
  enqueue(q, 50);

  display(q);

  return 0;
}
