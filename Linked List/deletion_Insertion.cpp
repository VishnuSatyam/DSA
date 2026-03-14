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
    if(arr.size() == 0) return nullptr;
    Node*head = new Node(arr[0]);
    Node*mover = head;
    for(int i=1;i<arr.size();i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
        
    }
    cout<<endl;
}

// remove head 

Node* removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// remove tail or last node 

Node* removeTail(Node* head){

    if(head == NULL) return NULL;

    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

// remove the kth element 

Node* removeK(Node* head , int k){
    if(head == NULL) return head;
    if(k==1){
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt =0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){

            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// remove node based on given value of node 

Node* removeEl(Node* head , int el){
    if(head == NULL) return head;
    if(head->data==el){
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data==el){

            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


// insertion at head or in start of linked list 


Node* instertHead(Node*head , int val){
    Node* temp = new Node(val , head);
    return temp;
}


// insertion at the last 


Node* insertTail(Node* head , int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val); // here since we didn't gave pointer it will automatically point to null as last element do that
    temp->next = newNode;
    return head;
}


// insertion at the kth position in linked list


Node* insertK(Node* head , int el , int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }
        else{
            return head;  /// this else statement have no meaning it will depend on what is being asked in the problem 
        }
    }
    if(k==1){
        return new Node(el , head); // this is for insertion at head
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt == (k-1)){
            Node* x = new Node(el , temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}


// insert based on the value for example inserting the element before the value x from linked list


Node* insertBeforevalue(Node* head , int el , int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        return new Node(el , head);
    }

    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* x = new Node(el , temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}



int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node*head = convertArr2LL(arr);
    head = removeHead(head);
    head = removeTail(head);
    head = removeK(head , 3);
    head = removeEl(head , 3);
    head = instertHead(head , 6);
    head = insertTail(head , 6);
    head = insertK(head , 6 , 2);
    head = insertBeforevalue(head , 7 , 2);


    print(head);
}