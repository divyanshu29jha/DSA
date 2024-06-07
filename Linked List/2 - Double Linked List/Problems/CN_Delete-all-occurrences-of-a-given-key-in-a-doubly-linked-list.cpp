/**
 * Definition of doubly linked list:
 *
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

// T.C: O(N), S.C: O(1)
Node * deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == k){
            if(temp->prev == NULL){    // temp is head
                head = temp->next; 
                if(head) head->prev = NULL;    // if single node, then head will be NULL, so cannot access head->prev
                temp->next = NULL;
                delete temp;
                temp = head;
            }  
            else{
                Node* back = temp->prev;   // temp is k-th node/tail
                Node* front = temp->next;

                if(back) back->next = front;
                if(front) front->prev = back;   // front is NULL for tail, so cannot access front->prev
                temp->next = NULL;
                temp->prev = NULL;
                delete(temp);
                temp = front;
            }
        }
        
        else{
            temp = temp->next;
        }
    }

    return head;
}



