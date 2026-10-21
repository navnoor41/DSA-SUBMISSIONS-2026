#include <iostream>
#include <algorithm>

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

// Helper function to get the height of a node
int getHeight(Node* n) {
    return n ? n->height : 0;
}

// Helper function to get the balance factor of a node
int getBalanceFactor(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

// Right Rotate utility (used for Left-Left imbalances)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // New root
}

// Left Rotate utility (used for Right-Right imbalances)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // New root
}

// Find the node with the minimum value (Inorder Successor helper)
Node* getMinValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Main recursive function to delete a node and rebalance the tree
Node* deleteNode(Node* root, int key) {
    // STEP 1: PERFORM STANDARD BST DELETION
    if (!root) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (!root->left || !root->right) {
            // Case 1 & 2: Node with 0 or 1 child
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                // No child case
                temp = root;
                root = nullptr;
            } else {
                // One child case
                *root = *temp; // Copy contents of non-empty child
            }
            delete temp;
        } else {
            // Case 3: Node with two children
            // Get the inorder successor (smallest in the right subtree)
            Node* temp = getMinValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node, return
    if (!root) return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    // STEP 3: GET THE BALANCE FACTOR TO CHECK FOR IMBALANCE
    int balance = getBalanceFactor(root);

    // STEP 4: REBALANCE VIA ROTATIONS IF UNBALANCED

    // Left-Left (LL) Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left-Right (LR) Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Right (RR) Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right-Left (RL) Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
