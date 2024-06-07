// A Node refers to the structure that contains data and the pointer to the next node. 
// Node* (Node pointer) specifically denotes a pointer variable that stores the address of the Node it is pointing to.
// The arrow operator (->) is a shorthand for dereferencing a pointer and accessing a member eg. y->data == (*y).data
// M-1 dynamically allocates memory on the heap, while M-2 uses stack memory.  (the memory management is different.)
// In M-2), Node x = Node(arr[0], nullptr);  this can also be written as Node x; x.data = arr[0]; x.next = nullptr;


#include <bits/stdc++.h>
using namespace std;

class Node {   // can also write struct Node
    public:     // access modifier
        int data;      // the value stored in the node
        Node* next;    // points to the next node in the linked list
    
    public:
        Node(int data1, Node* next1){     // parametrized constructor (is also a function) initializes the data and next pointer when a new node is created.
            data = data1;   // Initialize data with the provided value
            next = next1;
        }

        Node(int data1){
            data = data1;   // Initialize data with the provided value
            next = NULL;    // Initialize next as null since it's the end of the list
        }

        // Node(int data1, Node* next1) : data(data1), next(next1) {}   // member initializer list i.e : data(data1), next(next1) to initialize member variables/ Nodes.

};

int main() {
    vector<int> arr = {2, 5, 8, 6};
    
    // M-1)
    // Node* y = new Node(arr[0], nullptr);     // a new node y is dynamically allocated using the new keyword 

    // M-2)
    Node x(arr[0], NULL);  // Create a object Node 'x' with the first element of the vector and a null next reference (constructor used)
    Node* y = &x;                    // Create a pointer 'y' pointing to the Node 'x'
    
    cout<<y <<endl;         // returns the memory value
    cout<<x.data <<' '<<(*y).data <<' '<< y->data <<endl;   // returns the data stored at that memory point

    return 0;
}
