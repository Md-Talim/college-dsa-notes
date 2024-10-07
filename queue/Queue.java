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
