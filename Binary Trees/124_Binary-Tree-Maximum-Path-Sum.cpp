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
class Solution {
public:
    int findMaxPathSum(TreeNode* root, int &maxi) {
        if(root == nullptr)   // Base case: If the current node is null, return 0
            return 0;

        int leftSum = max(0, findMaxPathSum(root->left, maxi));   // calculate the maximum path sum for the left and right subtrees
        int rightSum = max(0, findMaxPathSum(root->right, maxi));  // avoid negative left sum and right sum

        maxi = max(maxi, leftSum + rightSum + root->val);  // update the overall maximum path sum including the current node

        // return the maximum sum considering only one branch (either left or right) along with the current node
        return max(leftSum, rightSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; 
        findMaxPathSum(root, maxi);
        return maxi;
    }
};


