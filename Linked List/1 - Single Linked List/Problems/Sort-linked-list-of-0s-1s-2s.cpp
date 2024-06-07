/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// M-1) T.C: O(2*N) two passes required, S.C: O(1) 
/*
Node* sortList(Node *head){
    Node* temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    while(temp != NULL){
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        if(cnt0 > 0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1 > 0){
            temp->data = 1;
            cnt1--;
        }
        else {
            temp->data = 2;
            cnt2--;
        }

        temp = temp->next;
    }

    return head;
}
*/

// M-2) T.C: O(N) One pass, S.C: O(1) 
// Here, when 3 linked list are created, new Nodes are not created. Only links from created
// linked list are added to original linked list with help of temp pointer.
Node* sortList(Node *head){
    if(head == NULL || head->next == NULL)
        return head;

    Node* zeroHead = new Node(-1);  // for keeping track of 3 initial linked list
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;  // for traversing in each of the linked list
    Node* one = oneHead;
    Node* two = twoHead;
    
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    delete zeroHead;    // free memory for initial pointers
    delete oneHead;
    delete twoHead;

    return zeroHead->next;
}












