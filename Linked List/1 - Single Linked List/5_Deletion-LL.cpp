// Never tamper with head node or else LL will be lost. So always create a temp Node pointing to head, and use it for traversal of LL.
// temp = temp->next and temp->next = temp2 are different. 

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

// 2. Delete head of a LL
Node* deleteHead(Node *head) {
    if (head == NULL) return head;      // Check if the linked list is empty
    
    Node* temp = head;
    head = head->next;
    delete temp;  // free(temp)
    
    return head;
}

// 3. Delete tail of a LL
Node* deleteTail(Node *head) {
    if (head == NULL || head->next == NULL) return head;      // Check if the linked list is empty or has single node
    
    Node* temp = head;
    while(temp->next->next != NULL){    // gives second last node     
        temp = temp->next;
    }
    temp->next = NULL;    
    delete temp->next;

    return head;    
}

// 4. Delete k-th element of a LL
Node* deleteKth(Node *head, int k) {
    if (head == NULL) return head; 

    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;        // My method
    Node* temp = head;
    while(temp != NULL){  
        cnt++;
        if(cnt == k-1){
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            break;
        }  
        temp = temp->next;
    }

    // Node* temp = head;    // Method-2 Striver
    // Node* prev = NULL;
    // int cnt = 0;

    // while (temp != NULL) {
    //     cnt++;        
    //     if (cnt == k) { // If the k-th node is found            
    //         prev->next = prev->next->next;  // Adjust the pointers to skip the k-th node
    //         delete temp;   // Delete the k-th node
    //         break;
    //     }
    //     // Move to the next node
    //     prev = temp;
    //     temp = temp->next;
    // }

    return head;    
}

// 5. Delete the element with value X
Node* deleteValX(Node *head, int x) {
    if (head == NULL) return head;  

    if(head->data == x){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }    
    
    Node* temp = head;      // My method
    while(temp != NULL){    
        if(temp->next->data == x){
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            break;
        }
        temp = temp->next;
    }

    // Node* temp = head;    // Method-2 Striver
    // Node* prev = NULL;

    // while (temp != NULL) {      
    //     if (temp->data == x) { // If the k-th node is found            
    //         prev->next = prev->next->next;  // Adjust the pointers to skip the k-th node
    //         delete temp;   // Delete the k-th node
    //         break;
    //     }
    //     prev = temp;
    //     temp = temp->next;
    // }

    return head;    
}

int main() {
    vector<int> arr = {7, 5, 8, 6};   
    
    // 1. Create the linked list with nodes initialized with vector values
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // 2. Delete head of a LL
    // head = deleteHead(head);
    // traversalOfLL(head);    

    // 3. Delete tail of a LL
    // head = deleteTail(head);
    // traversalOfLL(head);  

    // 4. Delete k-th element of a LL
    // head = deleteKth(head,3);
    // traversalOfLL(head);

    // 5. Delete the element with value X
    head = deleteValX(head,8);
    traversalOfLL(head);



    return 0;
}
