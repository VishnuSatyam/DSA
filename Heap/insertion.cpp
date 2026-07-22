#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    void insert(int val) {
        // Step 1: Insert at the end
        heap.push_back(val);

        // Step 2: Heapify Up
        int index = heap.size() - 1;

        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void print() {
        for (int x : heap)
            cout << x << " ";
    }
};

int main() {
    MaxHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(40);
    h.insert(50);

    h.print();
}



// for min heap just reverse the comparision

// if (heap[parent] > heap[index]) {
//     swap(heap[parent], heap[index]);
//     index = parent;
// }

/*Time Complexity
Insert at end → O(1)
Heapify Up → O(log n)

Overall:

TC = O(log n)
SC = O(1) (excluding the heap storage)*/ 



