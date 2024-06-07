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
    // M-1) Slow and fast pointer approach
    // T.C: O(N/2), S.C: O(1)
    // But stop at node before the middle node and then delete the middle node
    /*
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* fast = head, *slow = head;
        while(fast->next->next != NULL && fast->next->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete(toDelete);

        return head;
    }
    */

    // M-2) Another way to write above method
    // T.C: O(N/2), S.C: O(1)
    // But stop at node before the middle node and then delete the middle node
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* fast = head, *slow = head;
        fast = fast->next->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete(toDelete);

        return head;
    }
};