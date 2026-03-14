#include <iostream>
using namespace std;

int main() {
    int i = 5;            // a normal integer variable with value 5
    int* ptr = &i;        // ptr stores the address of i
    int** ptr2 = &ptr;    // ptr2 stores the address of ptr

    cout << ptr << endl;        // prints the address of i 
    cout << ptr2 << endl;       // prints the address of ptr 

    cout << "address of ptr " << &ptr << endl;   // &ptr = address of ptr 
                                                 // same as what ptr2 printed

    cout << "value of i (using *ptr) " << *ptr << endl;    
    // *ptr means "value at address stored in ptr"
    // prints 5

    cout << "value of i (using **ptr2) " << **ptr2 << endl; 
    // ptr2 -> points to ptr
    // *ptr2 -> ptr (address of i)
    // **ptr2 -> value at address of i = 5
}
