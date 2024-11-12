#include <bits/stdc++.h>
using namespace std;

// Definition of a TreeNode
struct TreeNode {     // or declare class and public: 
    int val;        // Value of the node
    TreeNode* left; // Pointer to the left child
    TreeNode* right;// Pointer to the right child

    // Constructor for TreeNode
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x) {
        val = x;        // Initialize the value of the node
        left = nullptr; // Initialize the left child to nullptr
        right = nullptr;// Initialize the right child to nullptr
    }
};


// Function to convert a vector to a binary tree using level order traversal
TreeNode* vectorToBinaryTree(vector<int>& vec) {
    if (vec.empty()) return nullptr;   // If the input vector is empty, return nullptr

    TreeNode* root = new TreeNode(vec[0]);   // Create the root node with the first element of the vector

    queue<TreeNode*> q;   // Queue to manage the nodes in the tree during level order traversal
    q.push(root);

    
    int i = 1;   // Index to track the position in the vector
    while(i < vec.size()){   // While there are more elements in the vector to process
        TreeNode* curr = q.front(); 
        q.pop();

        if(i < vec.size()){    // If there is a left child in the vector, create it and add to the queue
            curr->left = new TreeNode(vec[i++]);   // or use vec[i], then do i++ in next line
            q.push(curr->left);
        }
        if(i < vec.size()){  // If there is a right child in the vector, create it and add to the queue
            curr->right = new TreeNode(vec[i++]);
            q.push(curr->right);
        }
    }
    
    return root;    // Return the root of the constructed binary tree
}



// Function to print the binary tree in level order traversal
void printLevelOrder(TreeNode* root) {
    if (!root) return;  // If the tree is empty, return

    queue<TreeNode*> q;   // Queue to manage the nodes in the tree during level order traversal
    q.push(root);

    while (!q.empty()) {   // While there are nodes in the queue
        TreeNode* curr = q.front();    // Get the front node from the queue
        q.pop();

        cout << curr->val << " ";

        if (curr->left) q.push(curr->left);   // If there is a left child, add it to the queue
        if (curr->right) q.push(curr->right); // If there is a right child, add it to the queue
    }

    cout << endl;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

    TreeNode* root = vectorToBinaryTree(vec);   // Convert the vector to a binary tree

    cout << "Level Order Traversal of the Binary Tree: ";     
    printLevelOrder(root);    // Print the binary tree in level order traversal

    return 0;
}
