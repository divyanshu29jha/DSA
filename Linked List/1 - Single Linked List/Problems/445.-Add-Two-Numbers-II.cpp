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

// Approach: Reverse both the lists, add them, then reverse the answer.
// return reversed linked-list --> O(N)
// T.C: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times. 
class Solution {
public:
    ListNode* reverse(ListNode* head){    
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {       // similar to 2. Add Two Numbers
        ListNode* temp1 = reverse(l1);
        ListNode* temp2 = reverse(l2);

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        int carry = 0;

        while(temp1!=NULL || temp2!=NULL){
            int sum = 0;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;
            sum += carry;
            
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = curr->next;
            carry = sum/10;

            if(temp1) temp1 = temp1->next; 
            if(temp2) temp2 = temp2->next;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        ListNode* ans = reverse(dummyHead->next);      // reverse the sum of l1 and l2 as they were reversed initially
        return ans;
    }
};