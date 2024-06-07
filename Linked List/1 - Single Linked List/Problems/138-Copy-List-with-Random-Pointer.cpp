/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // M-1) Brute force using map
    // T.C: O(2*N), S.C: O(N)
    /*
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> m;    // key is original LL and value is deep copied LL
        Node* temp = head;
        while(temp != NULL){   // create map such that original Node is key and copied Node is value with same val
            Node* newNode = new Node(temp->val);
            m[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL){    // next and random pointers for deep copy LL
            m[temp]->next = m[temp->next];     // m[temp] gives copied Node, m[temp->next] also gives copied Node
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }

        return m[head];  // return head of copied LL
    }
    */


    // M-2) Optimal approach without extra space, T.C: O(3*N), S.C: O(1)
    // Can create separate functions for all 3 steps
    // Insert copy nodes in between original nodes, connect random pointers for copy node, connect next pointers for both
    // copy node and original node appropriately
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        // Step 1: Insert copy nodes in between original nodes
        Node* temp = head;
        while(temp != NULL){    
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }   

        // Step 2: Connect random pointers for copy node
        temp = head;
        while(temp != NULL){
            if(temp->random == NULL)            // Edge case if temp->random == NULL, then we cannot access temp->random->next
                temp->next->random = NULL;      // temp->next is CopyNode
            else
                temp->next->random = temp->random->next;      // temp->random->next is also a copy node

            temp = temp->next->next;
        }

        // Step 3: Connect next pointers for both copy node and original node appropriately
        temp = head;
        Node* dummyHead = new Node(-1);  // for returning the created copy list
        Node* curr = dummyHead;
        while(temp != NULL){
            curr->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            curr = curr->next;
        }

        return dummyHead->next;
    }
};