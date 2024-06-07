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
class Solution {
public:
    // M-1) Brute force: T.C: O(N + N/2), S.C: O(1)
    /*
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        temp = head;
        for(int i=0; i<cnt/2; i++){
            temp = temp->next;
        }

        return temp;
    }
    */

    
    // M-2) Optimal: Tortoise-Hare-Approach  (move slow pointer by one-step and fast pointer by two-step forward)
    // Single pass required. T.C: O(N), S.C: O(1)
    // For odd-length LL, fast will reach till last node. For even-length LL, fast will reach NULL.
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // points at middle of LL
    }
};