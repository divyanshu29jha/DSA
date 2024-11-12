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

// M-1) Brute force
// T.C: O(N^2) where N is the number of nodes in the Binary Tree.This arises as we calculate the height of each node and to calculate the height for each node, we traverse the tree which is proportional to the number of nodes. Since this calculation is performed for each node in the tree, the complexity becomes: O(N x N) ~ O(N2).
// S.C : O(1) as no additional data structures or memory is allocated.O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.
/*
class Solution {
public:
    int getHeight(TreeNode* root){
        if(root == NULL)   // Base case: If the tree is empty, height is 0
            return 0;

        int lh = getHeight(root->left);   // Recursively calculate the height of left and right subtrees
        int rh = getHeight(root->right);  
        return 1 + max(lh, rh);     // Return the height of the tree (1 accounts for current node)
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)   // Base case: If the tree is empty, it's balanced
            return true;

        int lh = getHeight(root->left);   // Calculate the height of left and right subtrees
        int rh = getHeight(root->right);
        
        // Check if the current node is balanced (height difference <= 1) and recursively check if both left and right subtrees are balanced
        if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }

        return false;    // If any condition fails, the tree is unbalanced
    }
};
*/


// M-2) Optimal approach
// T.C: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once.
// S.C: O(1), but recusion stack space used i.e O(n)
class Solution {
public:
    int checkBalance(TreeNode* root) {
        if (root == NULL)  // Base case: empty tree is balanced and its height is 0
            return 0;

        int lh = checkBalance(root->left);   // Calculate the height of the left subtree
        if(lh == -1) return -1;     // Left subtree is unbalanced, propagate failure up

        int rh = checkBalance(root->right);  // Calculate the height of the right subtree
        if(rh == -1) return -1;     // Right subtree is unbalanced, propagate failure up

        if(abs(lh - rh) > 1)    // If the difference in height exceeds 1, it's unbalanced
            return -1;

        return 1 + max(lh, rh);  // Return the height of the current subtree
    }

    bool isBalanced(TreeNode* root) {
        if(checkBalance(root) != -1)    // If -1 is returned, the tree is unbalanced
            return true;
        return false;        
    }
};

