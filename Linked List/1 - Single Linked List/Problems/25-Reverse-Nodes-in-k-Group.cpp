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
    // M-1) Brute forc - T.C: O((len/k) * (k-1)) = O(N), S.C: O(N/k) = O(N) in worst case if k=1
    /*
    ListNode* reverseLL(ListNode* head){
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

    int findLength(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == NULL || head->next == NULL){
            return head;
        }

        vector<ListNode*> v;   // for storing reversed individual LL that will be connected later
        ListNode* temp = head;
        ListNode* p = head;

        int len = findLength(head);
        int iter = len / k;
        for(int i=0; i<iter; i++){
            for(int j=0; j<k-1; j++){
                temp = temp->next;
            }

            if(temp == NULL) break;

            ListNode* front = temp->next;
            temp->next = NULL;
            temp = front;
            
            p = reverseLL(p);
            v.push_back(p);
            p = temp;
        }

        if(temp){
            v.push_back(temp);    // without reversing in case of left-out nodes
        }


        head = v[0];
        for(int i=0; i<v.size()-1; i++){        // merging the individual LL in vector
            ListNode* temp = v[i];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = v[i+1];
        }
        
        return head;
    }
    */

    
    // M-2) Optimal approach without extra space
    // T.C: O(2N) reversing segments of K and finding the Kth node which operates in linear time, S.C: O(1)
    ListNode* reverseLL(ListNode* head){
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

    ListNode* findKthNode(ListNode* temp, int k){
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            if(cnt == k)  return temp;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;    // Last node of previous LL
        while(temp != NULL){
            ListNode* kthNode = findKthNode(temp, k);   // find k-th Node from start (temp) of an individual LL
            if(kthNode == NULL){    // Edge case for left-out nodes at the end
                prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;   // store the head of the next LL
            kthNode->next = NULL;
            kthNode = reverseLL(temp);

            if(temp == head){  // for the 1st individual LL, head will be start of the reversed LL i.e kthNode after reversal
                head = kthNode;      // since prevLast is NULL initially for 1st individual LL, prevLast->next cannot be acccessed
            }
            else{   
                prevLast->next = kthNode;    // kthNode becomes the start of the next LL after reversal
            }

            prevLast = temp;   // temp will be at last node after reversal of LL
            temp = nextNode;
        }

        return head;
    }
};