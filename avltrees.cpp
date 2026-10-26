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

// Height helper function
int height(Node* root) {
    if (root == nullptr) {
        return -1; 
    }
    return 1 + std::max(height(root->left), height(root->right));
}

// Balance factor utility using the height function
int getBalanceFactor(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

// Check if a tree is AVL
bool isAVL(Node* root) {
    if (root == nullptr) {
        return true;
    }

    // Calculate balance factor
    int bf = getBalanceFactor(root);

    // Check if the current node is unbalanced
    if (bf < -1 || bf > 1) {
        return false;
    }

    // Recursively check left and right subtrees
    return isAVL(root->left) && isAVL(root->right);
}

// Helper to find the minimum value node (Inorder Successor)
Node* findMinValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// --- AVL Rotations ---

// Right Rotation (fixes LL imbalance)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

// Left Rotation (fixes RR imbalance)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

// --- AVL Deletion Function ---
Node* deleteNodeAVL(Node* root, int key) {
    // 1. Standard BST Deletion Navigation
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNodeAVL(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNodeAVL(root->right, key);
    } 
    else {
        // Node found! Handle the 3 structural cases
        
        // Case 1 & Case 2: One child or Leaf Node (No child)
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                // Leaf Node Case
                temp = root;
                root = nullptr;
            } else {
                // One Child Case
                *root = *temp; // Copy content of the child node
            }
            delete temp;
        } 
        // Case 3: Two Children
        else {
            // Find the inorder successor
            Node* temp = findMinValueNode(root->right);

            // Copy data over
            root->data = temp->data;

            // Delete the old successor node
            root->right = deleteNodeAVL(root->right, temp->data);
        }
    }

    // If the tree only had 1 node and it was deleted
    if (root == nullptr) {
        return root;
    }

    // 2. Perform Rebalancing Check via Rotations
    int balance = getBalanceFactor(root);

    // Left-Heavy Cases
    if (balance > 1) {
        // LL Case
        if (getBalanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }
        // LR Case
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // Right-Heavy Cases
    if (balance < -1) {
        // RR Case
        if (getBalanceFactor(root->right) <= 0) {
            return leftRotate(root);
        }
        // RL Case
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root; 
}

// Simple helper to print the tree structure in order
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    // Constructing a standard AVL tree
    //        30
    //       /  \
    //     20    40
    //     /
    //   10
    Node* root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);

    std::cout << "Original tree (Inorder): ";
    inorder(root);
    std::cout << "\n";

    // Call validation function before deletion
    if (isAVL(root)) {
        std::cout << "Initial status: Tree is AVL" << std::endl;
    } else {
        std::cout << "Initial status: Tree is not AVL" << std::endl;
    }

    // Perform an AVL Deletion
    // Deleting 40 shortens the right side, forcing an imbalance at node 30 (LL Case)
    std::cout << "\n[Action] Deleting node 40 to trigger an LL rotation check...\n";
    root = deleteNodeAVL(root, 40);

    std::cout << "Tree after deletion (Inorder): ";
    inorder(root);
    std::cout << "\n";

    // Re-verify the tree structure status after auto-balancing
    if (isAVL(root)) {
        std::cout << "Post-deletion status: Tree remains dynamically balanced and is AVL" << std::endl;
    } else {
        std::cout << "Post-deletion status: Tree is broken / not AVL" << std::endl;
    }

    // Clean up remaining memory
    if (root) {
        if (root->left) delete root->left;
        if (root->right) delete root->right;
        delete root;
    }

    return 0;
}
