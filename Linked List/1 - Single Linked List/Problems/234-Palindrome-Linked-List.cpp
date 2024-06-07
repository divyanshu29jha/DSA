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
    // M-1) Brute force: Put linked list elements in vector. T.C: O(N + N/2),
    // S.C: O(N)
    /*
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }

        int n = v.size();
        bool palindrome = true;
        for(int i=0; i<n/2; i++){
            if(v[i] != v[n-i-1])
                palindrome = false;
        }

        return palindrome;
    }
    */

    // M-2) Using stack to keep track of reversed linked list.  T.C: O(2*N),
    // S.C: O(N)
    /*
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        bool palindrome = true;
        temp = head;
        while(temp != NULL){
            if(temp->val != st.top()){
                palindrome = false;
                break;
            }
            st.pop();
            temp = temp->next;
        }

        return palindrome;
    }
    */

    // M-3) Optimal approach: Using reverse of LL and slow & fast pointers
    // T.C: O(N/2) + O(N/2) + O(N/2) + O(N/2) i.e O(N/2) for finding the middle element, reversing the list from the middle element, and
    // traversing again using first and second pointers to find palindrome, and then reversing the second half of list again; S.C: O(1)
    ListNode* reverseLL(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        // fast->next != NULL for odd-length LL && fast->next->next != NULL even-length LL
        // Slow needs to stop at 1st middle element in case of even-length LL
        while(fast->next != NULL && fast->next->next != NULL) {  
            slow = slow->next;
            fast = fast->next->next;
        } 

        ListNode* newHead = reverseLL(slow->next);  // reverse 2nd half of LL after slow pointer
        ListNode* first = head;    // head of 1st half
        ListNode* second = newHead;  // head of 2nd half
        bool palindrome = true;
        while(second != NULL){
            if(first->val != second->val){
                palindrome = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        reverseLL(newHead);  // Important to reverse back 2nd half of linked list to form original linked list (good practice)

        return palindrome;
    }
};