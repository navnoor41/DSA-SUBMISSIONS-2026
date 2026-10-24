#include <iostream>

// Simple Node structure
struct Node {
    int data;
    Node* next;
};

// Push an element onto the stack
void push(Node*& top, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top; // New node points to the old top
    top = newNode;       // New node becomes the new top
}

// Pop an element from the stack
void pop(Node*& top) {
    if (top == nullptr) {
        std::cout << "Stack Underflow! Nothing to pop.\n";
        return;
    }
    Node* temp = top;
    std::cout << "Popped: " << temp->data << "\n";
    top = top->next;     // Move the top pointer to the next node
    delete temp;         // Free memory
}

// Get the top element
int peek(Node* top) {
    if (top == nullptr) {
        std::cout << "Stack is empty.\n";
        return -1;
    }
    return top->data;
}

// Check if the stack is empty
bool isEmpty(Node* top) {
    return (top == nullptr);
}

int main() {
    // Initialise the top pointer to null (empty stack)
    Node* top = nullptr;

    // Test operations
    push(top, 100);
    push(top, 200);
    push(top, 300);

    std::cout << "Top element is: " << peek(top) << "\n";
    pop(top);
    std::cout << "Top element after pop is: " << peek(top) << "\n";

    // Clean up remaining memory before exiting
    while (!isEmpty(top)) {
        pop(top);
    }

    return 0;
}
