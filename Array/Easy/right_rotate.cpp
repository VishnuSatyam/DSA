// #include <bits/stdc++.h>
// using namespace std;

// void rightRotate(int arr[], int n, int d) {
//     d = d % n;
//     int temp[d];
//     for (int i = 0; i < d; i++) {
//         temp[i] = arr[n - d + i];
//     }
//     for (int i = n - d - 1; i >= 0; i--) {
//         arr[i + d] = arr[i];
//     }
//     for (int i = 0; i < d; i++) {
//         arr[i] = temp[i];
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int d;
//     cin >> d;
//     rightRotate(arr, n, d);
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


// more optimal approach 

#include <bits/stdc++.h>
using namespace std;

void rightRotate(int arr[], int n, int d) {
    d = d % n;
    reverse(arr, arr + n);
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int d;
    cin >> d;
    rightRotate(arr, n, d);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}



