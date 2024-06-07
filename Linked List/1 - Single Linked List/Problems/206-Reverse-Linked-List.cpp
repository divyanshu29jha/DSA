#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;   
    Node* next;      

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


// M-1) Brute force using stack
// T.C: O(2N) traverse the linked list twice: once to push the values onto the stack, and once to pop the values and update the linked list
// S.C: O(N) we use a stack to store the values of the linked list
// We we use a vector to store, then we will have to reverse the vector before storing its element back into the linked list
Node* reverseLinkedList(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
   
    return head;  
}


// M-2) Iterative approach
// T.C: O(N), S.C: O(1), three pointers (prev, temp and front) use constant space
Node* reverseLinkedList2(Node* head) {
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;   // Store the next node in 'front' to preserve the reference
        temp->next = prev;        // Reverse the direction of the current node's 'next' pointer to point to 'prev'
        prev = temp;            // Move 'prev' to the current node for the next iteration
        temp = front;         // Move 'temp' to the 'front' node advancing the traversal
    }
   
    return prev;   // Return the new head of the reversed linked list
}


// M-3) Recursive approach
// T.C: O(N), S.C: O(1), as no extra memory apart from stack space used 
Node* reverseLinkedList3(Node* head) {
    // Base case:    
    if (head == NULL || head->next == NULL) {   // If the linked list is empty or has only one node, return the head as it is already reversed.
        return head;
    }
    
    // Recursive step:
    Node* newHead = reverseLinkedList3(head->next);   // Reverse the linked list starting from the second node (head->next).
    
    Node* front = head->next;  // Save a reference to the node following the current 'head' node.
    front->next = head;      // Make the 'front' node point to the current 'head' node in the reversed order.
    head->next = NULL;     // Break the link from the current 'head' node to the 'front' node to avoid cycles.
    
    return newHead;   // Return the 'newHead,' which is the new head of the reversed linked list.
}


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with values 1, 3, 2, and 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Print the original linked list:
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Print the reversed linked list:    
    // head = reverseLinkedList(head);
    // head = reverseLinkedList2(head);
    head = reverseLinkedList3(head);
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}