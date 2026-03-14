// #include<iostream>
// using namespace std;
// void update(int *p){
//     *p=*p+1;

// }
// int main(){
//     int a=5;
//     int *p=&a;
//     update(p);
//     cout<<*p;  // if we pass by pointers the value will  get updated 
// }

 

// if we pass like this then no update as value is passed as a copy from main function
// #include<iostream>
// using namespace std;
// void update(int a){
//   a=a+1;
//   cout<<a<<endl;

// }
// int main(){
//     int a=5;
//     update(a);
//     cout<<a;  // if we pass by pointers the value will  get updated 
// }





#include<iostream>
using namespace std;
int  getSum(int *arr , int n){
    cout<<sizeof(arr)<<endl;

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;

}
int main(){
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<getSum(arr , n);  
    return 0;
}
