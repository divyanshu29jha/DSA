#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Function to get the Preorder, Inorder and Postorder traversal of Binary Tree in One traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> pre, in, post;  // Vectors to store traversals
    if (root == NULL) return {};  // If the tree is empty, return empty traversals

    stack<pair<Node*, int>> st;  // Stack to maintain nodes and their traversal state
    st.push({root, 1});  // Start with the root node and state 1 (preorder)

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        if(it.second == 1){
            
            pre.push_back(it.first->data);  // Store the node's data in the preorder traversal
            
            it.second = 2;  // Move to state 2 (inorder) for this node
            
            st.push(it); // Push the updated state back onto the stack

            if(it.first->left != NULL){    // Push left child onto the stack for processing
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in
        else if(it.second == 2){
            in.push_back(it.first->data);   // Store the node's data in the inorder traversal
            
            it.second = 3;   // Move to state 3 (postorder) for this node
            
            st.push(it);  // Push the updated state back onto the stack
            
            if(it.first->right != NULL){  // Push right child onto the stack for processing
                st.push({it.first->right, 1});
            }
        }

        // this is part of post
        else {
            post.push_back(it.first->data);   // Store the node's data in the postorder traversal
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}




// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    for(int num : vec){  // Iterate through the vector and print each element
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main(){
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting the pre-order, in-order, and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for(int val : pre){
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for(int val : in){
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for(int val : post){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
                            
                        