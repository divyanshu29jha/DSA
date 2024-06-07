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

// 2. Traversal of DLL
void traversalOfDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}

// 3. Insert at head of a DLL
Node* insertAtHead(Node *head, int val) {    
    if(head == NULL)
        return new Node(val, NULL, NULL);
    
    Node* newHead = new Node(val, head, NULL);
    head->prev = newHead;

    return newHead;
}

// 4. Insert at tail of a DLL
Node* insertAtTail(Node *head, int val) {    
    if(head == NULL)
        return new Node(val, NULL, NULL);

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* tail = new Node(val, NULL, temp);
    temp->next = tail;

    return head;    
}

// 5. Insert before k-th node of a DLL
Node* insertBeforeKth(Node *head, int k, int val) {
    if (head == NULL || k == 1) {      
        return insertAtHead(head, val);
    } 

    int cnt = 0;       
    Node* temp = head;
    while(temp != NULL){  
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* back = temp->prev;  // temp is k-th node    
    Node* newNode = new Node(val, temp, back);
    back->next = newNode;
    temp->prev = newNode;
    return head;    
}


int main() {
    vector<int> arr = {7, 5, 8, 6, 3};   
    
    // 1. Convert Array to Doubly Linked List
    Node* head = convertArr2DLL(arr);  
    cout<<"Array converted to DLL. \n";

    // 2. Traversal of Doubly Linked List
    cout<<"The DLL traversal is : ";
    traversalOfDLL(head);    
    cout<< endl;

    // 3. Insert at head of a DLL
    // head = insertAtHead(head, 9);           
    // traversalOfDLL(head);    

    // 4. Insert at tail of a DLL
    // head = insertAtTail(head, 12);
    // traversalOfDLL(head);  

    // 5. Insert before k-th node of a DLL
    head = insertBeforeKth(head, 3, 20);
    traversalOfDLL(head);
    
    return 0;
}