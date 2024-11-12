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


// Time complexity: O(n) - The algorithm iterates through each description exactly once, and for each description, it performs constant-time operations. 
// Space complexity: O(n) - The algorithm uses nodeMap to store references to all created nodes. In the worst case, this map contains all nodes, so it takes up O(n) space. The children set also takes O(n) space to store child values.

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;   // Maps values to TreeNode pointers
        unordered_set<int> children;  // Stores values which are children in the descriptions for identifying the root node later because the root will not be a child of any node.

        // Iterate through descriptions to create nodes and set up tree structure
        for (auto description : descriptions) {
            // Extract parent value, child value, and whether it is a left child (1) or right child (0)
            int parentValue = description[0];
            int childValue = description[1];
            bool isLeft = description[2];

            // Create parent and child nodes if not already created
            if (mpp.find(parentValue) == mpp.end()){    // OR if(mpp.count(parentValue) == 0)
                mpp[parentValue] = new TreeNode(parentValue);
            }
            if (mpp.find(childValue) == mpp.end()) {
                mpp[childValue] = new TreeNode(childValue);
            }

            // Attach child node to parent's left or right branch
            if (isLeft) {
                mpp[parentValue]->left = mpp[childValue];
            } else {
                mpp[parentValue]->right = mpp[childValue];
            }

            // Mark child as a child in the set
            children.insert(childValue);
        }

        for (auto& entry : mpp){    // Find and return the root node (iterate through map keys and search in children set)
            auto value = entry.first;
            auto node = entry.second;
    
            if (children.find(value) == children.end()){   // Root node found
                return node;
            }
        }

        return nullptr;   // Should not occur according to problem statement
    }
};