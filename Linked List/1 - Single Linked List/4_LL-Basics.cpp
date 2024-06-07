// Never tamper with head node or else LL will be lost. So always create a temp Node pointing to head, and use it for traversal of LL.
// temp = temp->next and temp->next = temp2 are different.
// temp = temp->next  movies temp Node pointer to next node pointer. And temp->next = temp2 changes the next address of temp node to address of temp2 node.

#include <bits/stdc++.h>
using namespace std;

class Node {   
    public:     
        int data;     
        Node* next;   
    
    public:
        Node(int data1, Node* next1){     
            data = data1;  
            next = next1;
        }

        Node(int data1){
            data = data1;   
            next = NULL; 
        }
};

// 1. Convert Array to Linked List
Node* convertArr2LL(vector<int>& arr){     // returns pointer to a Node (here Head)
    Node* head = new Node(arr[0]);      // next is NULL initially
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);     // creates a new node that will be attached to previous node
        mover->next = temp;
        mover = temp;       // OR mover = mover->next
    }

    return head;
}

// 2. Traversal of Linked List
void traversalOfLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}

// 3. Length of Linked List
int lengthOfLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;    // increment cnt for every node traversed
    }
    return count;
}

// 4. Search an element in a Linked List
int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == val)
            return 1;               
        temp = temp->next;  // Move to the next node
    }
    return 0;   // Return 0 if the element is not found in the linked list
}

int main() {
    vector<int> arr = {7, 5, 8, 6, 3};   

    // 1. Convert Array to Linked List
    Node* head = convertArr2LL(arr);  
    cout<<"Array converted to LL. \n";
    cout<< head->data <<endl;
    cout<< head->next->data <<endl;

    // 2. Traversal of Linked List
    cout<<"The LL traversal is : ";
    traversalOfLL(head);    
    cout<< endl;

    // 3. Length of Linked List
    cout<<"The length of LL is: ";
    cout<< lengthOfLL(head);    
    cout<< endl;

    // 4. Search an element in a Linked List
    cout<<"Is element present : ";
    cout<< checkIfPresent(head, 9);
    cout<< endl;
   

    return 0;
}
