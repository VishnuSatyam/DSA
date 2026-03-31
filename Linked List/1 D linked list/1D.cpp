// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // struct node{
// // //     public:
// // //     int data;
// // //     node*next;
// // //     //constructor
// // //     public:
// // //     node(int data1 , node*next1){
// // //         data = data1;
// // //         next = next1;
// // //     }
// // // };

// // // int main(){
// // //     vector<int> arr = {1,2,3,4,5};
// // //     node*y = new node(arr[0], nullptr);
// // //     cout<<y; // this will print meory address of y
// // //     cout<<y->data; // print 1.
// // // }

// // // if we dont wanna pass nullptr again and again we can use multiple constructor
// // #include<bits/stdc++.h>
// // using namespace std;
// // struct Node{
// //     int data;
// //     Node* next;

// //     // Constructor with 2 parameters
// //     Node(int data1 , Node* next1){
// //         data = data1;
// //         next = next1;
// //     }

// //     // Constructor with 1 parameter
// //     Node(int data1){
// //         data = data1;
// //         next = nullptr;
// //     }
// // };


// // int main(){
// //     vector<int> arr = {1,2,3,4,5};
// //     Node*y = new Node(arr[0]);
// //     cout<<y; // this will print meory address of y
// //     cout<<y->data; // print 1.
// // }



// // // instead of struct if we use class we can use all the oops features along 

// // #include<bits/stdc++.h>
// // using namespace std;
// // class node{
// //     public:
// //     int data;
// //     node*next;
// //     //constructor
// //     public:
// //     node(int data1 , node*next1){
// //         data = data1;
// //         next = next1;
// //     }
// // };

// // int main(){
// //     vector<int> arr = {1,2,3,4,5};
// //     node*y = new node(arr[0], nullptr);
// //     cout<<y; // this will print meory address of y
// //     cout<<y->data; // print 1.
// // } 



// // convert array to linked list

// // #include<bits/stdc++.h>
// // using namespace std;
// // struct Node{
// //     int data;
// //     Node* next;
// //     Node(int data1 , Node* next1){
// //         data = data1;
// //         next = next1;
// //     }
// //     Node(int data1){
// //         data = data1;
// //         next = nullptr;
// //     }
// // };
// // Node*convertArr2LL(vector<int>&arr){
// //     Node*head = new Node(arr[0]);
// //     Node*mover = head;
// //     for(int i=1;i<arr.size();i++){
// //         Node*temp = new Node(arr[i]);
// //         mover->next = temp;
// //         mover = temp;
// //     }
// //     return head;
// // }

// // int main(){
// //     vector<int> arr = {1,2,3,4,5};
// //     Node*head = convertArr2LL(arr);
// //     cout<<head->data;
// //     Node*temp = head;
// //     while(temp!=NULL){
// //         cout<<temp->data<<" ";
// //         temp = temp->next;
// //     }
// // }


// // length of ll

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
//     Node(int data1 , Node* next1){
//         data = data1;
//         next = next1;
//     }
//     Node(int data1){
//         data = data1;
//         next = nullptr;
//     }
// };
// Node*convertArr2LL(vector<int>&arr){
//     Node*head = new Node(arr[0]);
//     Node*mover = head;
//     for(int i=1;i<arr.size();i++){
//         Node*temp = new Node(arr[i]);
//         mover->next = temp;
//         mover = temp;
//     }
//     return head;
// }
// int lengthofLL(Node*head){
//     int cnt =0;
//     Node*temp = head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//         cnt++;
//     }
//     return cnt;
// }

// int main(){
//     vector<int> arr = {1,2,3,4,5};
//     Node*head = convertArr2LL(arr);
//     cout<<head->data;
//     cout<<lengthofLL(head);
  
// }


// search in LL

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node*convertArr2LL(vector<int>&arr){
    Node*head = new Node(arr[0]);
    Node*mover = head;
    for(int i=1;i<arr.size();i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int checkifPresent(Node*head , int val){
    Node*temp = head;
    while(temp!=NULL){
        if( temp->data ==val) return 1;
        temp = temp->next;

    }
    return 0;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node*head = convertArr2LL(arr);
    cout<<checkifPresent(head , 5);
  
}

// tc for search here is O(n) 
