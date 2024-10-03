# College DSA Notes

## Table of Content

- [Queue](#queue)
  - [Queue Implementation with Array](#queue-implementation-with-array)
  - [Queue Implementation with Linked List](#queue-implementation-with-linked-list)

## Queue

### Queue Implementation with Array

Here's a basic implementation of a queue using array in C:

```c
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
```

### Queue Implementation with Linked List

Here's a basic implementation of a queue using linked lists in C:

```c
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
int front(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty\n");
    return -1;
  }

  return q->front->data;
}
```
