// brute force 

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> findArrayIntersection(vector<int> &A, int n,
// vector<int> &B, int m) {
//     vector<int> ans;

//     int vis[m] = {m, 0};
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<m; j++) {
//             if(A[i] == B[j] && vis[j] == 0) {
//                 ans.push_back(A[i]);
//                 vis[j] = 1;
//                 break;
//             }
//             else if (B[j] > A[i]) break;
//         }
//     }
//     return ans;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> A(n);
//     for(int i=0; i<n; i++){
//         cin >> A[i];
//     }

//     int m;           
//     cin >> m;   
//     vector<int> B(m);
//     for(int i=0; i<m; i++){
//         cin >> B[i];
//     }
//     vector<int> ans = findArrayIntersection(A, n, B, m);

//     for(int i=0; i<ans.size(); i++){
//         cout << ans[i] << " "; 
//     }
// }


// optimal using two pointers 

#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, int n,
                                  vector<int> &B, int m)
{
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < A[i])
        {
            j++;
        }
        else
        {
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++)
        cin >> B[i];

    vector<int> ans = findArrayIntersection(A, n, B, m);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
