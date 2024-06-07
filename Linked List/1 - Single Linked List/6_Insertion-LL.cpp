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

// 1. Traversal of LL
void traversalOfLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}

// 2. Insert at head of a LL
Node* insertAtHead(Node *head, int val) {    
    Node* temp = new Node(val, head);    
    // Node* temp = new Node(val);      // Method-2
    // temp->next = head;    
    return temp;
}

// 3. Insert at tail of a LL
Node* insertAtTail(Node *head, int val) {    
    if(head == NULL)
        return new Node(val);

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* toInsert = new Node(val);
    temp->next = toInsert;

    return head;    
}

// 4. Insert at k-th position of a LL
Node* insertAtKth(Node *head, int k, int val) {
    if (head == NULL){     // If the linked list is empty and k is 1, insert the new node as the head
        if (k == 1)
            return new Node(val);
        else
            return head;
    }

    if(k == 1){     // If k is 1, insert the new node at the beginning of the linked list
        return new Node(val, head);
    }

    int cnt = 0;        
    Node* temp = head;
    while(temp != NULL){  
        cnt++;
        if(cnt == k-1){
            Node* toInsert = new Node(val, temp->next);
            temp->next = toInsert;
            break;

            // Node* toInsert = new Node(val);
            // toInsert->next = temp->next;
            // temp->next = toInsert;
            // break;
        }  
        temp = temp->next;
    }

    return head;    
}

// 5. Insert before the value X of LL
Node* insertBeforeValX(Node *head, int x, int val) {
    if (head == NULL){
        return NULL;  
    }

    if(head->data == x){
        return new Node(val, head);
    }    
    
    Node* temp = head;     
    while(temp->next != NULL){    
        if(temp->next->data == x){
            Node* toInsert = new Node(val, temp->next);
            temp->next = toInsert;
            break;
        }
        temp = temp->next;
    }

    return head;    
}

int main() {
    vector<int> arr = {7, 5, 8, 6};   
    
    // 1. Create the linked list with nodes initialized with vector values
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // 2. Insert at head of a LL
    // head = insertAtHead(head, 9);           // head = new Node(9, head);
    // traversalOfLL(head);    

    // 3. Insert at tail of a LL
    // head = insertAtTail(head, 12);
    // traversalOfLL(head);  

    // 4. Insert at k-th position of a LL
    // head = insertAtKth(head,3,20);
    // traversalOfLL(head);

    // 5. Insert before the value X of LL
    head = insertBeforeValX(head,6,29);
    traversalOfLL(head);

    return 0;
}
