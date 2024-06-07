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
    // M-1) Brute force using set
    // T.C: O(N*logN), S.C: O(N)
    /*
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        ListNode* temp = head;
        while(temp != NULL){
            if(s.find(temp) == s.end()){    // O(N*logN)
                s.insert(temp);     // O(N*logN)
                temp = temp->next;
            }
            else{
                return temp;
            }
        }

        return NULL;
    }
    */

    
    // M-2) Fast and slow pointer approach
    // Refer image saved in VSCode or video for proof/intuition
    // T.C: O(N), S.C: O(1)
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            // if slow and fast meet then, take slow to head and move both slow and fast by one node forward until they meet at start of loop     
            if(slow == fast){   // cycle detected
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;    
                }

                return slow;
            }
        }

        return NULL;
    }
};