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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

// M-1) Brute force
// Since LL is sorted, to optimise add this condition -  && (temp1->data + temp2->data <= k)
// This will allow T.C to be slightly less than O(N^2), S.C: O(N)
/*
vector<pair<int, int>> findPairs(Node* head, int k){
    vector<pair<int, int>> v;
    
    Node* temp1 = head;
    while(temp1 != NULL){
        Node* temp2 = temp1->next;
        while(temp2 != NULL && (temp1->data + temp2->data <= k)){
            if(temp1->data + temp2->data == k){
                v.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return v;    
}
*/



// M-2) Optimal approach - Two pointer since the nodes are sorted
// T.C: O(N), S.C: O(1)
Node* findTail(Node* head){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

vector<pair<int, int>> findPairs(Node* head, int k){
    vector<pair<int, int>> ans;
    
    Node* left = head;
    Node* right = findTail(head);
    while(left < right){
        if(left->data + right->data == k){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(left->data + right->data < k){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    } 

    return ans;    
}

