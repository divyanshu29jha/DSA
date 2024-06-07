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
    // M-1) Brute force: Store LL elements in vector and then sort them. Add back the sorted vector elements into the LL
    /*
    // T.C: O(N) + O(N*logN) + O(N), S.C: O(N)
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL){    // O(N)
            v.push_back(temp->val);
            temp = temp->next;
        }

        sort(v.begin(), v.end());  // O(N*logN)

        temp = head;
        int i = 0;
        while(temp != NULL){    // O(N)
            temp->val = v[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
    */


    // M-2) Optimal approach: Merge Sort in LL
    // T.C: O(logN) + O(N/2 + N), S.C: O(1)  [recursive stack space of O(logN)]
    ListNode* findMiddle(ListNode* head){ 
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast->next != NULL && fast->next->next != NULL){      // for even-length LL, stop at first middle node
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            }
            else            {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }        
        }

        // for unqual length linked list (if either nodes in list1 or list2 still remain after previous while-loop)
        if(list1 != NULL) 
            curr->next = list1;
        else
            curr->next = list2;

        return dummyHead->next; 
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL)    
            return head;
        
        ListNode* middle = findMiddle(head);  // O(N/2)
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        left = sortList(left);   // O(logN) to divide
        right = sortList(right);    // O(logN) to divide

        ListNode* ans = mergeTwoLists(left, right);  // O(N) to conquer/merge
        return ans;      
    }
};