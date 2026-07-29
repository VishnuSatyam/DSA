class Solution {
public:

    // Heapify a subtree rooted at index i
    void heapify(vector<int> &arr, int n, int i)
    {
        while (true)
        {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] > arr[largest])
                largest = left;

            if (right < n && arr[right] > arr[largest])
                largest = right;

            // Heap property already satisfied
            if (largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // Step 1: Merge both arrays
        vector<int> ans = a;

        for (int x : b)
            ans.push_back(x);

        int size = ans.size();

        // Step 2: Build Max Heap
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(ans, size, i);

        return ans;
    }
};