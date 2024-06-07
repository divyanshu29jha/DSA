// Never tamper with head node or else LL will be lost. So always create a temp Node pointing to head, and use it for traversal of LL.
// temp = temp->next and temp->next = temp2 are different. 

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

// 2. Traversal of LL
void traversalOfDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}

// 3. Delete head of a LL
Node* deleteHead(Node *head) {
    if (head == NULL || head->next == NULL) return NULL;      // Check if the DLL is empty
    
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;  // free(temp)
    
    return head;

    // M-2)
    // Node* newHead = head->next;
    // newHead->prev = NULL;
    // head->next = NULL;
    // delete head;

    // return newHead;
}

// 4. Delete tail of a LL
Node* deleteTail(Node *head) {
    if (head == NULL || head->next == NULL) return NULL;      // Check if the DLL is empty or has single node
    
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* newTail = temp->prev;   // temp is the last node
    newTail->next = NULL;
    temp->prev = NULL;
    delete temp;

    return head;    
}

// 5. Delete k-th element of a DLL
Node* deleteKth(Node *head, int k) {
    if (head == NULL) return NULL; 

    int cnt = 0;       
    Node* temp = head;
    while(temp != NULL){  
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* back = temp->prev;   // temp is k-th node
    Node* front = temp->next;

    if(front == NULL){
        return deleteTail(head);   // temp is tail
    }
    else if(back == NULL){
        return deleteHead(head);   // temp is head
    }

    back->next = front;
    front->prev = back;
    temp->next = NULL;
    temp->prev = NULL;
    delete(temp);

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

    // 3. Delete head of a DLL
    // head = deleteHead(head);
    // traversalOfDLL(head);    

    // 4. Delete tail of a DLL
    // head = deleteTail(head);
    // traversalOfDLL(head);  

    // 5. Delete k-th element of a DLL
    head = deleteKth(head,3);
    traversalOfDLL(head);

    return 0;
}
