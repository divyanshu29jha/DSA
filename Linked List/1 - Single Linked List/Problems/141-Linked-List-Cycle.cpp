/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // M-1) Brute force using set/map/hashing
    // T.C: O(2*N*logN) for finding and inserting, S.C: O(N)
    /*
    bool hasCycle(ListNode *head) {
       set<ListNode*> s;   // store memory address of node in LL
       ListNode* temp = head;
       bool cycle = false;
       while(temp != NULL){
            if(s.find(temp) == s.end()){   // O(N*logN) for ordered set   // if node address does not exist in set, then insert
                s.insert(temp);    // O(N*logN)
                temp = temp->next;
            }
            else{
                cycle = true;
                break;
            }
       }

       return cycle; 
    }
    */

    
    // M-2) Tortoise & Hare Algorithm (slow & fast pointers) 
    // T.C: O(N), S.C: O(1)
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // loop termination condition: fast != NULL for even-length LL and fast->next != NULL for odd-length LL 
        while(fast != NULL && fast->next != NULL){ 
            slow = slow->next;
            fast = fast->next->next;

            // ultimately slow and fast will collide as distance between them will reduce by 1 node in each iteration, if there is a loop
            if(slow == fast)    
                return true;
        }

        return false;
    }
};