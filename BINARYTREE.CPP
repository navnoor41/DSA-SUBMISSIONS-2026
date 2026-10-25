#include <iostream>

using namespace std;

// Definition of the Binary Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to easily create a new node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to dynamically create a binary tree recursively
Node* createBinaryTree() {
    int value;
    cout << "Enter node value: ";
    cin >> value;

    // Create the current node
    Node* root = new Node(value);

    int choice;

    // Ask for the Left Child
    cout << "Do you want to enter a LEFT child for " << value << "? (1 for Yes, 0 for No): ";
    cin >> choice;
    if (choice == 1) {
        root->left = createBinaryTree();
    }

    // Ask for the Right Child
    cout << "Do you want to enter a RIGHT child for " << value << "? (1 for Yes, 0 for No): ";
    cin >> choice;
    if (choice == 1) {
        root->right = createBinaryTree();
    }

    return root;
}

// 1. Preorder Traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 2. Inorder Traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 3. Postorder Traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "--- Create your Binary Tree ---" << endl;
    Node* root = createBinaryTree();

    cout << "\n--- Tree Traversals ---" << endl;
    
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
