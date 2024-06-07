/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
#include <bits/stdc++.h>
// M-1) Brute force using set
// T.C: O(N*logN), S.C:O(N)
/*
int lengthOfLoop(Node *head) {
    map<Node*, int> m;
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        if(m.find(temp) == m.end()){     // O(N*logN)
           cnt++;
           m[temp] = cnt;   // O(N*logN)
           temp = temp->next;
        } 
        else {
           break;
        }
    }

    if (temp == NULL)
        return 0;

    int len = cnt - m[temp] + 1;
    return len;
}
*/


// M-2) Using slow and fast pointers
// T.C: O(N), S.C: O(1)
// When slow and fast pointers meet and cycle is detected, then move fast pointer one node ahead
// and continue to move fast inside the loop until it meets slow again. Count no. of nodes in loop.
int lengthOfLoop(Node *head) {
    Node* fast = head,*slow = head;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            fast = fast->next;
            int cnt = 1;
            while(slow != fast){
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }

    return 0;
}



