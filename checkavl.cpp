#include <iostream>
#include <algorithm>

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Height helper function (visible on the top-right of your page)
int height(Node* root) {
    if (root == nullptr) {
        return -1; 
    }
    return 1 + std::max(height(root->left), height(root->right));
}

// Exact logic from your handwritten page
bool isAVL(Node* root) {
    if (root == nullptr) {
        return true;
    }

    // Calculate balance factor
    int bf = height(root->left) - height(root->right);

    // Check if the current node is unbalanced
    if (bf < -1 || bf > 1) {
        return false;
    }

    // Recursively check left and right subtrees
    return isAVL(root->left) && isAVL(root->right);
}

int main() {
    // Creating a sample balanced tree to test the function
    Node* root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);

    // Call your function
    if (isAVL(root)) {
        std::cout << "Tree is AVL" << std::endl;
    } else {
        std::cout << "Tree is not AVL" << std::endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
