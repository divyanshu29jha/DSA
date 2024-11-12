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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head->next->next == NULL) {   // atleast 4 nodes should be there two find distance between two critical points
            return {-1, -1};
        }

        vector<int> v;  // to store positions of critical points
        ListNode* temp = head->next;
        ListNode* prev = head;
        int pos = 2;
        while(temp->next != NULL){
            if((temp->val > prev->val && temp->val > temp->next->val) || (temp->val < prev->val && temp->val < temp->next->val)){
                v.push_back(pos);
            }
            pos++;
            prev = temp;
            temp = temp->next;
        }

        int n = v.size();
        if(n < 2){
            return {-1,-1};
        }
        
        int maxDist = v[n-1] - v[0];
        int minDist = INT_MAX;
        for(int i=1; i<n; i++){
            minDist = min(minDist, v[i] - v[i-1]);
        }        

        return {minDist, maxDist};
    }
};