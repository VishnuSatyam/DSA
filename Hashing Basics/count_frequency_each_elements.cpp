
// using brute force in which we use two for loop using using a visited array approach



// #include <bits/stdc++.h>
// using namespace std;
 
// void countFreq(int arr[], int n)
// {
//     vector<bool> visited(n, false);
 
//     for (int i = 0; i < n; i++) {
 
//         // Skip this element if already processed
//         if (visited[i] == true)
//             continue;
 
//         // Count frequency
//         int count = 1;
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] == arr[j]) {
//                 visited[j] = true;
//                 count++;
//             }
//         }
//         cout << arr[i] << "is visited  " << count <<"times "<< endl;
//     }
// }
 
// int main()
// {
//     int arr[] = {10, 5, 10, 15, 10, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     countFreq(arr, n);
//     return 0;
// }


//time complexity of this approach will be ime Complexity: O(N*N) Space Complexity:  O(N)




// for better approach we can do with the unordered map


#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {10, 20, 10, 30, 20, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> freq;
    /*
Example Dry Run

Array = {10, 20, 10}

Start:

freq = {}


First iteration (arr[0] = 10):

freq[10] doesn’t exist.

Map creates {10: 0}.

Then ++ makes it {10: 1}.

Second iteration (arr[1] = 20):

freq[20] doesn’t exist.

Map creates {20: 0}.

Then ++ makes it {20: 1}.



    */

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for (auto x : freq) {
        cout << x.first << " occurs " << x.second << " times" << endl;
    }

    return 0;
}
