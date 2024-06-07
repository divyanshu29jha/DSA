/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// M-1) Brute force: T.C:O(2*N), S.C: O(1) 
// We can traverse through the Linked List while maintaining a count of nodes, let’s say in the variable count, and then traversing for the 2nd time for (n – count) nodes to get to the nth node of the list.
/*
class Solution {
public:
    int lengthOfLL(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)
            return NULL;

        int len = lengthOfLL(head);
        int k = len - n;
        ListNode* temp = head;

        if(k == 0){
            head = head->next;
            delete temp;
        }
        else{
            int cnt = 0;
            while(temp != NULL){
                cnt++;
                if(cnt == k){
                    ListNode* toDelete = temp->next;
                    temp->next = temp->next->next;
                    delete toDelete;
                    break;
                }
                temp = temp->next;
            }
        }

        return head;        
    }
};
*/

// M-2) Optimal: Two-pointer approach (Slow and fast pointer)
// T.C: O(N), S.C: O(1)
// To delete Nth node from end, slow should be at (N-1)th node from start. 
// In a list of 7 nodes, to delete 3rd node from end, slow should stop at 4th node from end (i.e one node behind).
// So, move fast to 4th node from start to maintain the gap so that when fast reaches last node, slow will be at 4th node from end. 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i=0; i<n; i++){     // move fast n nodes ahead after head node
            fast = fast->next;
        }

        if(fast == NULL){       // in list of 5 nodes, if n=5, then we need to delete 1st node. So, fast will reach NULL here.
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        ListNode* slow = head;
        while(fast->next != NULL){  // to check that fast reaches last node
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return head;   

    }   
};