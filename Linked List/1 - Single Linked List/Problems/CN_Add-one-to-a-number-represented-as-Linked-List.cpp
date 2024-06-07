/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

// M-1) Similar to LC 445. Add Two Bumbers II (Reverse LL, add 1 and then again reverse it)
Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    
    return prev;
}

/*
Node *addOne(Node *head){
    Node* dummyHead = new Node(-1);    // for creating answer LL
    Node* curr = dummyHead;

    Node* temp = reverseLL(head);

    int sum1 = temp->data + 1;
    Node* nextNode = new Node(sum1%10);
    curr->next = nextNode;
    curr = curr->next;
    temp = temp->next;
    int carry = sum1/10;
    
    while(temp != NULL){
        int sum = 0;   // sum for next nodes after 1st node of answer LL
        sum+=temp->data;
        sum+=carry;
        carry = sum/10;

        nextNode = new Node(sum%10);
        curr->next = nextNode;
        curr = curr->next;

        temp = temp->next;
    }

    if(carry){
        nextNode = new Node(carry);
        curr->next = nextNode;
    }

    Node* ans = reverseLL(dummyHead->next);
    return ans;    
}
*/

// Better code quality for above method
Node *addOne(Node *head){
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;  // initially 1 needs to be added
    
    while(temp != NULL){
        temp->data += carry;

        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{     // temp->data = 10
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }

    if(carry == 1){         // edge case when no. contains only 9s eg: 999
        head = reverseLL(head);
        Node* newNode = new Node(1);  // add extra carry at head of reversed LL
        newNode->next = head;
        return newNode;
    }

    head = reverseLL(head);
    return head;    
}





