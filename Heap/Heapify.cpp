// void heapify(vector<int>& heap, int n, int i) {
//     while (true) {
//         int largest = i;
//         int left = 2 * i + 1;
//         int right = 2 * i + 2;

//         if (left < n && heap[left] > heap[largest])
//             largest = left;

//         if (right < n && heap[right] > heap[largest])
//             largest = right;

//         if (largest == i)
//             break;

//         swap(heap[i], heap[largest]);
//         i = largest;
//     }
// }


// for min heap

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& heap, int n, int i) {
    while (true) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] < heap[smallest])
            smallest = left;

        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(heap[i], heap[smallest]);
        i = smallest;
    }
}

int main() {
    vector<int> heap = {50, 20, 30, 10, 40};

    cout << "Before Build Heap: ";
    for (int x : heap)
        cout << x << " ";
    cout << endl;

    // Build the complete min heap
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        heapify(heap, heap.size(), i);
    }

    cout << "After Build Heap: ";
    for (int x : heap)
        cout << x << " ";
    cout << endl;

    return 0;
}


// tc and sc is O(log n) and O(1) respectively