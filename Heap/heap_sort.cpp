// For ascending order, we use a Max Heap and vice versa
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i)
{
    while(true)
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && arr[left]>arr[largest])
            largest=left;

        if(right<n && arr[right]>arr[largest])
            largest=right;

        if(largest==i)
            break;

        swap(arr[i],arr[largest]);
        i=largest;
    }
}

void heapSort(vector<int>& arr)
{
    int n=arr.size();

    // Build Max Heap
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    // Sorting
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}

int main()
{
    vector<int> arr={50,20,30,10,40};

    heapSort(arr);

    for(int x:arr)
        cout<<x<<" ";
}

// tc will be O(n log n) and sc will be O(1)