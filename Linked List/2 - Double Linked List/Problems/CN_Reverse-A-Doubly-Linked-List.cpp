/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

#include<bits/stdc++.h>

// M-1) Brute force using stack
// T.C: O(2*N), S.C: O(N)
/*
Node* reverseDLL(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    
    stack<int> st;
    
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    

    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}
*/


// M-2) Optimal approach withour extra space
// T.C: O(N), S.C: O(1)
/*
Node* reverseDLL(Node* head){  
    if(head == NULL || head->next == NULL){
        return head;
    } 

    Node* temp = head;
    Node* back = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = back;
        if(back != NULL) back->prev = temp;

        back = temp;
        temp = front;
    }  

    return back;
}
*/

// M-3) Better code quality for M-2
// T.C: O(N), S.C: O(1)
Node* reverseDLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    
    Node* back = NULL;  
    Node* current = head;   

    while (current != NULL) {
        back = current->prev; 
        current->prev = current->next;  // Swap the previous and next pointers
        current->next = back;     // This step reverses the links        
        
        current = current->prev;  // Move to the next node in the original list
    }
    
    // The final node in the original list becomes the new head after reversal
    return back->prev;
}

