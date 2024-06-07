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
    // M-1) Create a new linked list and store all nodes with odd indices first and then traverse again to store nodes with even indices
    /*
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;

        ListNode* dummyHead = new ListNode(-1);  // for creating new linked list which will be returned as answer
        ListNode* curr = dummyHead;        

        ListNode* temp = head;
        while(temp != NULL){
            ListNode* newNode = new ListNode(temp->val);
            curr->next = newNode;
            curr = curr->next;
            
            if(temp->next != NULL)  // if temp->next==NULL for last element of LL, then we will have to break since LL will be traversed
                temp = temp->next->next;
            else break;
        }

        temp = head->next;
        while(temp != NULL){
            ListNode* newNode = new ListNode(temp->val);
            curr->next = newNode;
            curr = curr->next;

            if(temp->next != NULL)  // if temp->next==NULL for last element of LL, then we will have to break since LL will be traversed
                temp = temp->next->next;
            else break;
        }

        return dummyHead->next;
    }
    */

    
    // M-2) Just change next links appropriately in the same linked list, no need to create new linked list
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even!=NULL && even->next!=NULL) {    // while(odd->next != NULL && even->next != NULL) ,can use this also
            odd->next = odd->next->next;
            odd = odd->next;
            
            even->next = even->next->next;            
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};