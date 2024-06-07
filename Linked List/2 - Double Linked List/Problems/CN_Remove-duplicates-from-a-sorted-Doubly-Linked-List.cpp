/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

// M-1) T.C: O(N), S.C: O(1)
/*
Node * removeDuplicates(Node *head){    
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            Node* toDelete = temp->next;
            Node* nextNode = temp->next->next;
            
            temp->next = nextNode;
            if(nextNode != NULL) nextNode->prev = temp;
            delete(toDelete);
        }
        else{
            temp = temp->next;
        }
    }

    return head;
}
*/


// Better code quality for M-1 --> T.C: O(N), S.C: O(1)
Node * removeDuplicates(Node *head){    
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        Node* nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data){
            Node* duplicate = nextNode;   // to free memory
            nextNode = nextNode->next;
            delete(duplicate);
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;
        temp = temp->next;
    }

    return head;
}
