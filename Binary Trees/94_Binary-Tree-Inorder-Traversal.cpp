/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// M-1) Recursive approach
// Inorder Traversal --> Left, Root, Right 
// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.
// Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because the recursive stack uses an auxiliary space which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes. In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).
/*
class Solution {
public:
    // Important to Pass by Reference to use the same preOrder vector in all recursive functions
    void helper(TreeNode *root,vector<int>& inorder){    
        if(root == NULL)
            return;
        
        helper(root->left, inorder);
        inorder.push_back(root->val);
        helper(root->right, inorder);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        helper(root,inorder);
        return inorder;
    }
};
*/


// M-2) Iterative approach
// Inorder Traversal --> Left, Root, Right 
// Time Complexity: O(N) where N is the number of nodes in the binary tree. Every node of the binary tree is visited exactly once, and for each node, the operations performed (pushing and popping from the stack, accessing node values, etc.) are constant time operations.
// Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because the stack can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.
// The main part of the code is a while loop that continues until curr becomes null (indicating we have traversed the entire tree) and the stack is empty (indicating we've processed all nodes).
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;    
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr != NULL || !st.empty()) {      // false || false == true  i.e curr becomes NULL as well as stack becomes empty
            // Reach the leftmost node of the current node
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            // Current must be NULL at this point
            curr = st.top();
            st.pop();
            inorder.push_back(curr->val);
            
            // Visit the right subtree
            curr = curr->right;
        }
        
        return inorder;
    }
};
*/

// Another way to write M-2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(true){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                curr=st.top();
                inorder.push_back(curr->val);
                st.pop();
                curr=curr->right;
            }
        }
        return inorder;
    }
};