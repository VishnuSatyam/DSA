//Deletion in a heap almost always means delete the root because the root is the maximum element in a Max Heap (or minimum in a Min Heap).


/*Save the root (answer).
Replace the root with the last element.
Remove the last element.
Heapify Down from the root:
Compare with left and right child.
Swap with the larger child (for Max Heap).
Continue until the heap property is restored.*/

void deleteRoot(vector<int>& heap) {
    int n = heap.size();

    if (n == 0)
        return;

    // Move last element to root
    heap[0] = heap[n - 1];

    // Remove last element
    heap.pop_back();

    n--;

    int i = 0;

    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(heap[i], heap[largest]);
        i = largest;
    }
}

/*Time Complexity
Replace root: O(1)
Remove last: O(1)
Heapify Down: O(log n)

Overall: O(log n)*/