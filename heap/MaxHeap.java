package heap;

import java.util.ArrayList;

public class MaxHeap {
    ArrayList<Integer> heap = new ArrayList<>();

    private void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxIdx = i;

        if (left < heap.size() && heap.get(left) > heap.get(maxIdx)) {
            maxIdx = left;
        }

        if (right < heap.size() && heap.get(right) > heap.get(maxIdx)) {
            maxIdx = right;
        }

        if (maxIdx != i) {
            int temp = heap.get(i);
            heap.set(i, heap.get(maxIdx));
            heap.set(maxIdx, temp);

            heapify(maxIdx);
        }
    }

    public void add(int data) {
        heap.add(data);

        int child = heap.size() - 1;
        int parent = (child - 1) / 2;

        while (heap.get(child) > heap.get(parent)) {
            int childValue = heap.get(child);
            int parentValue = heap.get(parent);
            heap.set(child, parentValue);
            heap.set(parent, childValue);

            child = parent;
            parent = (child - 1) / 2;
        }
    }

    public int peek() {
        return heap.get(0);
    }

    public int remove() {
        int first = heap.get(0);
        int last = heap.get(heap.size() - 1);

        heap.set(0, last);
        heap.set(heap.size() - 1, first);
        heap.remove(heap.size() - 1);

        heapify(0);

        return first;
    }

    public boolean isEmpty() {
        return heap.size() == 0;
    }
}
