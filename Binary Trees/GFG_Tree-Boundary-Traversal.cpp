/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Left boundary excluding leaf, then leaf nodes and then right boundary in the reverse excluding leaf
class Solution {
public:
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }

    void addLeftBoundary(Node* root, vector<int>& res){   // Left boundary excluding leaf
        Node* curr = root->left;
        while(curr != NULL){
            if(!isLeaf(curr))
                res.push_back(curr->data);
            
            if(curr->left) 
                curr = curr->left;
            else 
                curr = curr->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& res){    // right boundary in the reverse excluding leaf
        Node* curr = root->right;
        vector<int> temp;
        while(curr != NULL){
            if (!isLeaf(curr)) 
                temp.push_back(curr->data);
    
            if (curr->right) 
                curr = curr->right;
            else 
                curr = curr->left;
        }

        for(int i = temp.size()-1; i >= 0; --i){
            res.push_back(temp[i]);
        }
    }


    void addLeaves(Node* root, vector<int>& res) {
        if(isLeaf(root)){   // If the current node is a leaf, add its value to the result
            res.push_back(root->data);
            return;
        }
        
        if(root->left)   // Recursively add leaves of the left and right subtrees
            addLeaves(root->left, res);
        if(root->right) 
            addLeaves(root->right, res);
    }
    
    vector<int> boundary(Node *root){
        vector<int> res;
        if (!root) return res;

        if (!isLeaf(root)) 
            res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};






