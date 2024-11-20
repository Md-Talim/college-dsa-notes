# College DSA Notes

## Sorting

<details>
<summary><code>Heap Sort</code></summary>

```java
public static void heapify(int heap[], int i, int size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxIdx = i;

    if (left < size && heap[left] > heap[maxIdx]) {
        maxIdx = left;
    }

    if (right < size && heap[right] > heap[maxIdx]) {
        maxIdx = right;
    }

    if (maxIdx != i) {
        int temp = heap[i];

        heap[i] = heap[maxIdx];
        heap[maxIdx] = temp;
        heapify(heap, maxIdx, size);
    }
}

public static void heapSort(int arr[]) {
    int n = arr.length;

    for (int i = n / 2; i >= 0; i--) {
        heapify(arr, i, n);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, 0, i);
    }
}
```

</details>

## Queue

<details>
  <summary>
  <code>Queue Implementation with Array</code>
  </summary>

```java
public class Queue {
    static int queue[];
    static int size;
    static int rear;

    Queue(int n) {
        size = n;
        queue = new int[n];
        rear = -1;
    }

    public boolean isEmpty() {
        return rear == -1;
    }

    public void add(int data) {
        if (rear == size - 1) {
            System.out.println("Queue is full!");
            return;
        }

        rear = rear + 1;
        queue[rear] = data;
    }

    public int remove() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return -1;
        }

        int front = queue[0];
        for (int i = 0; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear = rear - 1;
        return front;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return -1;
        }

        return queue[0];
    }
}

```

</details>

<details>
<summary>
<code>Queue Implementation with Linked List</code>
</summary>

```java
public class LinkedListQueue {
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static Node head = null;
    static Node tail = null;

    public boolean isEmpty() {
        return head == null && tail == null;
    }

    public void enqueue(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = tail = newNode;
            return;
        }

        tail.next = newNode;
        tail = newNode;
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is Empty");
            return -1;
        }

        int front = head.data;

        if (head == tail) {
            head = tail = null;
        } else {
            tail = tail.next;
        }

        return front;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is Empty");
            return -1;
        }

        return head.data;
    }
}

```

</details>

<details>
<summary><code>Circular Queue</code></summary>

```java
static class CiruclarQueue {
  static int queue[];
  static int size;
  static int rear;
  static int front;

  CircularQueue(int initialSize) {
    size = initialSize;
    queue = new int[size];
    front = rear = -1;
  }

  public boolean isEmpty() {
    return front == -1 && rear == -1;
  }

  public boolean isFull() {
    return (rear + 1) % size == front;
  }

  public void enqueue(int data) {
    if (isFull()) {
      System.out.println("Queue is Full");
      return;
    }

    if (front == -1) {
      front =  0;
    }

    rear = (rear + 1) % size;
    queue[rear] = data;
  }

  public int dequeue() {
    if (isEmpty()) {
      System.out.println("Queue is Empty");
      return -1;
    }

    int peek = queue[front];

    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % size;
    }

    return peek;
  }

  public int peek() {
    if (isEmpty()) {
      System.out.println("Queue is Empty");
      return -1;
    }

    return queue[front];
  }
}
```

</details>
