#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node
{
  int data;
  struct Node *next;
};

// Define the structure for the queue
struct Queue
{
  struct Node *front;
  struct Node *rear;
};

// Function to create a new node
struct Node *newNode(int data)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

// creates a queue
struct Queue *createQueue()
{
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

// function to add an element to the queue
void enqueue(struct Queue *q, int data)
{
  struct Node *temp = newNode(data);

  // if queue is empty, front and rear are the same
  if (q->rear == NULL)
  {
    q->front = q->rear = temp;
    return;
  }

  // otherwise, add the new node at the end and change rear
  q->rear->next = temp;
  q->rear = temp;
}

// removes an element from the queue
int dequeue(struct Queue *q)
{
  // if the queue is empty, return -1
  if (q->front == NULL)
  {
    printf("Queue is empty\n");
    return -1;
  }

  // store the front node and move the front one node ahead
  struct Node *temp = q->front;
  q->front = q->front->next;

  // if front becomes null, set rear to null as well
  if (q->front == NULL)
  {
    q->rear = NULL;
  }

  int data = temp->data;
  free(temp); // Free the memory of the dequeued node

  return data;
}

// checks if the queue is empty
int isEmpty(struct Queue *q)
{
  return q->front == NULL;
}

// prints a queue
void printQueue(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty\n");
    return;
  }

  struct Node *temp = q->front;
  printf("Queue elements: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

// returns the front element without removing it
int peek(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty\n");
    return -1;
  }

  return q->front->data;
}

int main()
{
  struct Queue *q = createQueue();

  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  printQueue(q);

  printf("Dequeued: %d\n", dequeue(q));
  printf("Front element: %d\n", peek(q));
  printQueue(q);
  printf("Dequeued: %d\n", dequeue(q));
  printQueue(q);
  printf("Is queue empty? %s\n", isEmpty(q) ? "Yes" : "No");

  return 0;
}
