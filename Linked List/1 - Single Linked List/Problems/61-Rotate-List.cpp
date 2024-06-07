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
    // M-1) Brute force: Perform rotation of last node to right k%n times
    // T.C:  O(n) + O(k%n * n), S.C: O(1)
    /*
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        int n = 1;  // Find length of LL and stop when temp is at the last node
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            n++;
        }

        if (k%n == 0)   // edge case when no rotation happens
            return head;

        for (int i=0; i<k%n; i++) {   // since k=2*10^9, must do k%n or else TLE. Perform rotation of last node to right k%n times
            temp = head;
            while (temp->next->next != NULL) {  // stop at 2nd last node
                temp = temp->next;
            }
            ListNode* end = temp->next;
            temp->next = NULL;
            end->next = head;
            head = end;
        }

        return head;        
    }
    */


    // M-2) Optimal approach: T.C: O(2*N), S.C: O(1)
    /*
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        int n = 0; // length of LL
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        if(k%n == 0){       // Edge case when no rotation happens
            return head;
        }

        temp = head;
        int moveBy = n - k%n -1;
        for(int i=0; i<moveBy; i++){
            temp = temp->next;
        }

        ListNode* p = temp->next;
        temp->next = NULL;
        
        ListNode* newHead = p;
        while(p->next != NULL){     // p moves to last node of original LL
            p = p->next;
        }
        p->next = head;

        return newHead;
    }
    */


    // M-3) Better code quality for above method: T.C: O(2*N), S.C: O(1)
    ListNode* findNthNode(ListNode* temp, int k){
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            if(cnt == k)    
                return temp;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        int len = 1;  // For length of LL, keep len = 1 initially and stop when temp is at the last node
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }

        if (k%len == 0)   // edge case when no rotation happens
            return head;

        k = k%len;   // since k=2*10^9, must do k%n or else TLE. 
        ListNode* newLastNode = findNthNode(head, len-k);
        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;
        temp->next = head;  // attach tail of original LL to the original head

        return newHead;
    }
};