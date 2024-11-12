// Approach-1 (2 Pass)
// T.C : O(2*n), S.C : O(n)
/*
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL)
            return root;

        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSum;

        while(!q.empty()){   // Step-1 (find sum of each level and store in levelSum array)
            int currLevelSum = 0;
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                currLevelSum += curr->val;
                if(curr->left) 
                    q.push(curr->left);
                if(curr->right) 
                    q.push(curr->right);
            }

            levelSum.push_back(currLevelSum);
        }

        q.push(root);  // Step-2 (update each node value with cousin sum)
        root->val = 0;    // root has not cousins
        int j = 1;  // traversing levelSum vector
        while(!q.empty()){
            int n = q.size();   // current level me kitne nodes hain

            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                int siblingSum = 0;
                if (curr->left)
                    siblingSum += curr->left->val;
                if (curr->right)
                    siblingSum += curr->right->val;

                if(curr->left){
                    curr->left->val = levelSum[j] - siblingSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = levelSum[j] - siblingSum;
                    q.push(curr->right);
                }
            }
            j++;
        }

        return root;
    }
};
*/

// Approach-2 (1 Pass)
// T.C : O(n), S.C : O(n)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) 
            return root;

        queue<TreeNode*> q;
        q.push(root);
        int levelSum = root->val;

        while(!q.empty()) {
            int n = q.size();
            int nextLevelSum = 0;

            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();

                curr->val = levelSum - curr->val;

                int siblingSum = 0;
                if (curr->left)
                    siblingSum += curr->left->val;
                if (curr->right)
                    siblingSum += curr->right->val;

                if(curr->left){
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    q.push(curr->right);
                }
            }

            levelSum = nextLevelSum;
        }

        return root;
    }
};
