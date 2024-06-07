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
    // M-1) Brute force using vector
    // T.C: O(O(N*logN), where N = N1+N2, S.C: O(N1+N2) 
    /*
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> v;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != NULL){   //O(N1)
            v.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2 != NULL){   //O(N2)
            v.push_back(temp2->val);
            temp2 = temp2->next;
        }

        sort(v.begin(), v.end());  //O(N*logN), where N = N1+N2
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        for(int i=0; i<v.size(); i++){   //O(N), where N = N1+N2
            ListNode* front = new ListNode(v[i]);
            curr->next = front;
            curr = curr->next;
        }

        return dummyHead->next;        
    }
    */

    
    // M-2) Optimal: Two-pointer approach
    // T.C: O(N1+N2), S.C: O(1)
    /*
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                ListNode* front = new ListNode(temp1->val);
                curr->next = front;
                curr = curr->next;
                temp1 = temp1->next;             
            }
            else{
                ListNode* front = new ListNode(temp2->val);
                curr->next = front;
                curr = curr->next;
                temp2 = temp2->next;
            }
        }

        // for unqual length linked list (if either nodes in list1 or list2 still remain after previous while-loop)
        while(temp1 != NULL){
            ListNode* front = new ListNode(temp1->val);
            curr->next = front;
            curr = curr->next;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            ListNode* front = new ListNode(temp2->val);
            curr->next = front;
            curr = curr->next;
            temp2 = temp2->next;
        }

        return dummyHead->next;        
    }
    */


    // M-3) Another way to write M-2
    // T.C: O(N1+N2), S.C: O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
    
};