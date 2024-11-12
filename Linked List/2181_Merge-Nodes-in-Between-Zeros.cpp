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

// M-1) T.C: O(n), S.C: O(n) 
/*
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;

        ListNode* temp = head;
        temp = temp->next;
        int sum = 0;
        while(temp != NULL){
            if(temp->val == 0){
                v.push_back(sum);
                sum = 0;
            }

            sum += temp->val;
            temp = temp->next;
        }

        // Convert Array to Linked List
        ListNode* newHead = new ListNode(v[0]);
        ListNode* mover = newHead;
        for(int i=1; i<v.size(); i++){
            ListNode* temp = new ListNode(v[i]);
            mover->next = temp;
            mover = temp;
        }

        return newHead;
    }
};
*/



// M-2) Same as M-1 but no extra vector required
// T.C: O(n), S.C:O (1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        
        ListNode* newHead = new ListNode(0);
        ListNode* mover = newHead;
        
        int sum = 0;
        while (temp != nullptr) {
            if (temp->val == 0) {
                mover->next = new ListNode(sum);
                mover = mover->next;
                sum = 0;
            } 
            else {
                sum += temp->val;
            }
            temp = temp->next;
        }

        return newHead->next;
    }
};
