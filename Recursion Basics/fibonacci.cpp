// // by using just for loop

// #include <bits/stdc++.h>
// using namespace std;

// void fib(int n){
//     if(n <= 0) return;

//     vector<int> f(n);
//     f[0] = 0;
//     if(n > 1) f[1] = 1;

//     cout << f[0] << " ";
//     if(n > 1) cout << f[1] << " ";

//     for(int i = 2; i < n; i++){
//         f[i] = f[i-1] + f[i-2];
//         cout << f[i] << " ";
//     }
//     cout << endl;
// }

// int main(){
//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     fib(n);
// }


// using recursion nth fibonacci number
#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n<=1){
        return n;
    }
    int last=fib(n-1);
    int second_last=fib(n-2);
    return last + second_last;
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}


// time complexity is near about 2^n . it is exponential in nature .