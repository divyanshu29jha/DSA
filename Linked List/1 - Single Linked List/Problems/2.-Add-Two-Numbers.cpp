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

// T.C: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times. 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);   // dummyHead->next gives the new linked list with the sum of l1 and l2
        ListNode* curr = dummyHead;
        int carry = 0;      // global carry for linked list
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1!=NULL || temp2!=NULL){      // traverse till the end of both the linked list
            int sum = 0;  // sum for newNode
            if(temp1) sum += temp1->val;   // check if(temp1) bcoz if temp1 becomes NULL, while loop will still execute for temp2
            if(temp2) sum += temp2->val;
            sum += carry;

            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = curr->next;
            carry = sum/10;     // if sum = 12, then 12/10 = 1 which is carry

            if(temp1) temp1 = temp1->next;  // check if(temp1) bcoz if temp1 becomes NULL, while loop will still execute for temp2
            if(temp2) temp2 = temp2->next;
        }

        if(carry){        // Edge case: if carry = 1 still remains after traversal of both the linked list
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        return dummyHead->next;     

    }
};