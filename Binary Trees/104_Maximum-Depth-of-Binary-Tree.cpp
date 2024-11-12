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

// The depth of a node is the number of edges present in path from the root node of a tree to that node.
// The height of a node is the number of edges present in the longest path connecting that node to a leaf node.

// M-1) Using Level Order Traversal
/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        
        if (root == NULL) return depth;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        
        return depth;
    }
};
*/


// M-2) Recursive traversal (DFS)
// T.C: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the traversal to determine the maximum depth.
// S.C: O(N) where N is the number of nodes in the Binary Tree because in the worst case scenario the tree is balanced and has N/2 nodes in its last level which will have to be stored in the queue.
class Solution {
public:
    int maxDepth(TreeNode* root) {        
        if (root == NULL) return 0;
        
        int lh = maxDepth(root->left);    // left height
        int rh = maxDepth(root->right);   // right height
        
        return 1 + max(lh, rh);        
    }
};


