/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // M-1) Brute force: T.C: O(m*n), S.C: O(1)
    /*
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;

        if(headA == headB){   // Edge case: in case of single node in LL and both headA and headB point to it
            return headA;
        }

        while(tempA != NULL){
            ListNode* tempB = headB;
            while(tempB != NULL){  
                if(tempB == tempA){     // Edge case: if any node in 1st LL is head node of 2nd LL
                    return tempB;
                }
                if(tempB->next == tempA){   // if some node in 2nd LL has its next node intersecting with 1st LL
                    return tempA;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }

        return NULL;
    }
    */


    // M-2) Using map to store node pointers of 1st LL and then comparing it with node pointers of 2nd LL
    // T.C: O(m*logm) + O(n*logn) for ordered map, S.C: O(m) or O(n) depending on which LL is stored in mao
    /*
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> m;
        ListNode* tempA = headA;
        while(tempA != NULL){  // O(m*logm)
            m[tempA] = 1;   // store all pointers to node in map as key (it will be unique). Can use set also.
            tempA = tempA->next;  // No need to store value of node in map as there can be duplicate values in both the LL. So store all 1.
        }

        ListNode* tempB = headB;
        while(tempB != NULL){   // O(n*logn)
            if(m.find(tempB) != m.end()){   // if any node pointer (address) in map m matches to any node in headB
                return tempB;
            }
            tempB = tempB->next;
        }

        return NULL;
    }
    */


    // M-3) Find the difference between length of both LL and then start traversing both LL together when they are equidistant from end.
    // T.C: O(m) + O(n) + O(m-n) + O(n), S.C: O(1)
    /*
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA; 
        ListNode* tempB = headB;
        int lenA = 0, lenB = 0;
        while(tempA != NULL){  // O(m)
            lenA++;
            tempA = tempA->next;
        }
        while(tempB != NULL){  // O(n)
            lenB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;
        if(lenA > lenB){
            int diff = lenA - lenB;
            for(int i=0; i<diff; i++){      // O(m-n)
                tempA = tempA->next;
            }
        }
        else{ 
            int diff = lenB - lenA;
            for(int i=0; i<diff; i++){    // O(n-m)
                tempB = tempB->next;
            }
        }

        while(tempA != NULL){     //O(m) or O(n) whichever is shorter, since tempA and tempB both are at equal distance from end of LL
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
    */


    // M-4) Two-Pointers Solution
    // T.C: O(m+n), S.C:O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA; 
        ListNode* tempB = headB;

        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;

            // edge case: when both LL are having a single node and they are not intersecting (infinte loop) 
            // another edge case: headA = [3], headB=[2,3] and intersection at 3
            if(tempA == tempB) return tempA;   
                                                
            if(tempA == NULL)  tempA = headB;
            if(tempB == NULL)  tempB = headA;      
        }

        return tempA;        
    }
};