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
// Postorder Traversal --> Left, Right, Root 
// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.
// Space Complexity: O(N) where N is the number of nodes in the binary tree as an additional space for array is allocated to store the values of all ‘N’ nodes of the binary tree.
/*
class Solution {
public:
    // Important to Pass by Reference to use the same preOrder vector in all recursive functions
    void helper(TreeNode *root,vector<int>& postorder){    
        if(root == NULL)
            return;
        
        helper(root->left,postorder);
        helper(root->right,postorder);
        postorder.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        helper(root,postorder);
        return postorder;
    }
};
*/

// M-2) Iterative approach (Using 2 stacks)
// Postorder Traversal --> Left, Right, Root 
// Time Complexity: O(2N) where N is the number of nodes in the Binary Tree. The traversal process visits each node in the Binary Tree exactly once to push into stack1 and stack2. Then after the tree is traversed and the nodes are popped from stack2 to push into the postorder array.
// Space Complexity: O(2N) where N is the number of nodes in the Binary Tree. The space occupied by the two stacks depend on the height of the binary tree. In the worst-case scenario, if the tree is skewed, the space complexity would be O(N) as both stacks could potentially hold all nodes at different points during traversal.The postorder array also holds all nodes from the binary tree hence giving another O(N) + O(N) ~ O(2N).
/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;

        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){  // O(n)
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
        }

        while(!st2.empty()){     // O(n)  // stack s2 stores the postorder in reverse manner (LIFO)
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};
*/   


// M-2) Iterative approach (Using single stack)
// Postorder Traversal --> Left, Right, Root 
// T.C: O(2N), N for traversing the nodes and N for going back (in second while loop), S.C: O(N) as single stack used
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(!st.empty() || curr != NULL) {
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            } 
            else{  // Current must be NULL at this point at the left side
                TreeNode* temp = st.top()->right;
                if (temp != NULL){
                    curr = temp;
                } 
                else{
                    temp = st.top();   // if st.top()->right == NULL, then reassign temp to st.top()
                    st.pop();   // temp (st.top()) is popped from stack now
                    postorder.push_back(temp->val);

                    while(!st.empty() && temp == st.top()->right){  // st.top() is previous value in stack after popping temp
                        temp = st.top();   // reassign temp (i.e after traversing Left, Right, now insert root values)
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
            }
        }      

        return postorder;
    }
};