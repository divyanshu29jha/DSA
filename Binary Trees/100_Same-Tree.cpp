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

// T.C: O(N+M) where N is the no. of nodes in q and M is the no. of nodes in q. This complexity arises from visiting each node of the two binary nodes during their comparison.
// S.C: O(1) as no additional space or data structures is created that is proportional to the input size of the tree. 
// O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case (its N).
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL &&  q== NULL) return true;    // If both nodes are NULL, they are identical
        if(p == NULL ||  q== NULL) return false;   // If only one of the nodes is NULL, they are not identical
        // if(p->val != q->val) return false;
        // return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);

        return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};