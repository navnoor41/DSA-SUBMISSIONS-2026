#include <iostream>

// The Node structure remains exactly the same
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// 1. Insert at the front
// We pass head by reference (Node*&) so we can modify the actual head pointer
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// 2. Insert at the end
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 3. Insert after a specific target value
void insertAfterValue(Node* head, int target, int val) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot insert " << val << ".\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        std::cout << "Target " << target << " not found. Cannot insert " << val << ".\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// 4. Insert before a specific target value
void insertBeforeValue(Node*& head, int target, int val) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot insert " << val << ".\n";
        return;
    }

    // Edge case: Target is the head node
    if (head->data == target) {
        insertAtHead(head, val);
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != target) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Target " << target << " not found. Cannot insert " << val << ".\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = current;
    prev->next = newNode;
}

// 5. Print the list
void display(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// 6. Manual cleanup (Crucial without a class destructor!)
void clearList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr; 
}

// Driver code
int main() {
    // Without a class, we manually declare and manage the head pointer here
    Node* myHeadPointer = nullptr; 

    std::cout << "Building initial list...\n";
    insertAtTail(myHeadPointer, 10);
    insertAtTail(myHeadPointer, 20);
    insertAtTail(myHeadPointer, 30);
    display(myHeadPointer);

    std::cout << "\nInserting 15 before 20:\n";
    insertBeforeValue(myHeadPointer, 20, 15);
    display(myHeadPointer);

    std::cout << "\nInserting 25 after 20:\n";
    insertAfterValue(myHeadPointer, 20, 25);
    display(myHeadPointer);

    // YOU MUST CALL THIS MANUALLY, or your program will leak memory!
    clearList(myHeadPointer); 
    
    return 0;
}
