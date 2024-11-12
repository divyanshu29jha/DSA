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
    int diameter = 0;  

    int getHeight(TreeNode* root){
        if(root == NULL)
            return 0;
            
        int lh = getHeight(root->left);   // Recursively calculate the height of left and right subtrees
        int rh = getHeight(root->right);

        diameter = max(diameter, lh + rh);  // Calculate the diameter at the current node and update the global variable

        return 1 + max(lh, rh);   // Return the height of the current subtree
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return diameter;
    }
};
*/

// M-2) Optimal 
// T.C: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once.
// S.C : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.
class Solution {
public:
    int getHeight(TreeNode* root, int& diameter){
        if(root == NULL)
            return 0;
            
        int lh = getHeight(root->left, diameter);    // Recursively calculate the height of left and right subtrees
        int rh = getHeight(root->right, diameter);

        diameter = max(diameter, lh + rh);  // Update the diameter with the maximum of current diameter or sum of left and right heights

        return 1 + max(lh, rh);   // Return the height of the current node's subtree
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getHeight(root, diameter);
        return diameter;
    }
};  



