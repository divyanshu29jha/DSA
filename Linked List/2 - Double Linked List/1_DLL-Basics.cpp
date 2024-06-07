#include <bits/stdc++.h>
using namespace std;

class Node {   
    public:     
        int data;     
        Node* next;   
        Node* prev;
    
    public:
        Node(int data1, Node* next1, Node* prev1){     
            data = data1;  
            next = next1;
            prev = prev1;
        }

        Node(int data1){
            data = data1;   
            next = NULL; 
            prev = NULL;
        }
};

// 1. Convert Array to Doubly Linked List
Node* convertArr2DLL(vector<int>& arr){     
    Node* head = new Node(arr[0]);      // next and prev are NULL initially
    Node* back = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], NULL, back);     
        back->next = temp;
        back = temp;       
    }

    return head;
}

// 2. Traversal of Doubly Linked List
void traversalOfDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}

// 3. Length of Doubly Linked List
int lengthOfDLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;    // increment cnt for every node traversed
    }
    return count;
}

// 4. Search an element in a Doubly Linked List
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

    // 1. Convert Array to Doubly Linked List
    Node* head = convertArr2DLL(arr);  
    cout<<"Array converted to DLL. \n";
    cout<< head->data <<endl;
    cout<< head->next->data <<endl;
    cout<< head->next->prev->data <<endl;

    // 2. Traversal of Doubly Linked List
    cout<<"The DLL traversal is : ";
    traversalOfDLL(head);    
    cout<< endl;

    // 3. Length of Linked List
    cout<<"The length of DLL is: ";
    cout<< lengthOfDLL(head);    
    cout<< endl;

    // 4. Search an element in a Linked List
    cout<<"Is element present : ";
    cout<< checkIfPresent(head, 9);
    cout<< endl;
   

    return 0;
}
