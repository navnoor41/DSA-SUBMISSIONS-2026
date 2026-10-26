#include <iostream>

using namespace std;

// Structure for a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a key in the BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

// Helper function to find the minimum value node in a subtree
Node* findMinValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Delete a node demonstrating all 3 structural cases
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    // Navigate to the target node
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    // Found the target node to delete
    else {
        
        // --- CASE 1: The node is a Leaf Node (No children) ---
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // --- CASE 2: The node has exactly One Child ---
        // Case 2a: Only right child exists
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        // Case 2b: Only left child exists
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // --- CASE 3: The node has Two Children ---
        else {
            // Find the inorder successor (smallest element in the right subtree)
            Node* temp = findMinValueNode(root->right);

            // Copy the successor's data to the current node
            root->data = temp->data;

            // Recursively delete the old inorder successor node from the right subtree
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Utility function for Inorder Traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

}
int main() {
    Node* root = nullptr;

    // Creating a target BST structure
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20); // Leaf node
    root = insert(root, 40);
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); // We will turn this into a single-child node
    root = insert(root, 90); // 80 now has exactly one child (90)

    cout << "Original tree: ";
    inorder(root);
    cout << "\n\n";

    // Testing Search
    int target = 40;
    if (search(root, target)) {
        cout << "Element " << target << " found in the BST.\n\n";
    }

    // Demonstrating CASE 1: Deleting a leaf node (20)
    cout << "Executing Case 1: Deleting leaf node (20)\n";
    root = deleteNode(root, 20);
    cout << "Tree after deletion: ";
    inorder(root);
    cout << "\n\n";

    // Demonstrating CASE 2: Deleting a node with one child (80)
    // 80 will be deleted, and its single child (90) will safely move up to take its place!
    cout << "Executing Case 2: Deleting node with one child (80)\n";
    root = deleteNode(root, 80);
    cout << "Tree after deletion (90 should still be here): ";
    inorder(root);
    cout << "\n\n";

    // Demonstrating CASE 3: Deleting a node with two children (50)
    cout << "Executing Case 3: Deleting node with two children (50)\n";
    root = deleteNode(root, 50);
    cout << "Tree after deletion: ";
    inorder(root);
    cout << "\n";

    return 0;
}
