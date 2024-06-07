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
    ListNode* mergeKLists(vector<ListNode*>& lists) {  
        
        vector<int> v;              
        for(auto it: lists){
            ListNode* temp = it;
            while(temp != NULL){
                v.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(v.begin(), v.end());

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        for(auto it: v){
            ListNode* nextNode = new ListNode(it);
            curr->next = nextNode;
            curr = curr->next;
        }

        return dummyHead->next;       
    }
};