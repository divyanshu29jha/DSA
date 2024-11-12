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
// Preorder Traversal --> Root, Left, Right 
// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.
// Space Complexity: O(N) where N is the number of nodes in the binary tree as an additional space for array is allocated to store the values of all ‘N’ nodes of the binary tree.
/*
class Solution {
public:
    // Important to Pass by Reference to use the same preOrder vector in all recursive functions
    void helper(TreeNode *root,vector<int>& preorder){    
        if(root == NULL)
            return;
        
        preorder.push_back(root->val);
        helper(root->left,preorder);
        helper(root->right,preorder);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        helper(root,preorder);
        return preorder;
    }
};
*/


// M-2) Iterative approach using stack
// Preorder Traversal --> Root, Left, Right
// Time Complexity: O(N) where N is the number of nodes in the binary tree. Every node of the binary tree is visited exactly once, and for each node, the operations performed (pushing and popping from the stack, accessing node values, etc.) are constant time operations.
// Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because the stack can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;
        
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            preorder.push_back(curr->val);
            if(curr->right) st.push(curr->right);   // first push right, then left as stack follows LIFO. We need Root, Left, Right.
            if(curr->left) st.push(curr->left);     // in next iteration, left is popped first, and right remains in stack.
        }

        return preorder;
    }
};