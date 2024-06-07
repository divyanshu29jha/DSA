/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

// T.C: O(1), S.C:  O(1 )

void Queue::push(int x) {
    // Creating a dummy node
    Node* tempNode = new Node(x);
    
    if(front == NULL) {
        // Assigning both 'front' and 'rear' to 'tempNode'
        front = rear = tempNode;
    }
    else {
        // Assigning the 'next' of rear to 'tempNode'
        // and assigning 'rear' to rear->next
        rear -> next = tempNode;
        rear = rear -> next;
    }
}

int Queue::pop() {
    // Creating a dummy node
    Node* tempNode = front;
    
    // Queue is empty
    if(tempNode == NULL) {
        return -1;
    }
    
    // Initialising the variable 'ans'
    int ans = tempNode -> data;
    
    if(tempNode -> next != NULL) {    // Check if there is single element in queue
        // Shifting 'front'
        tempNode = tempNode -> next;
        delete(front);
        front = tempNode;
    }
    else {
        // Making both 'rear' and 'front' as NULL
        delete(front);
        front = rear = NULL;
    }
    
    return ans;
}