#include <iostream>


struct Node {
    int data;
    Node* next;
    Node* prev;
};

// 1. Insert at the Beginning
void insertAtBeginning(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node{val, nullptr, nullptr};
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// 2. Insert at the End
void insertAtEnd(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node{val, nullptr, nullptr};
    if (tail == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// 3. Insert at a Position (1-indexed)
void insertAtPosition(Node*& head, Node*& tail, int val, int position) {
    if (position <= 1 || head == nullptr) {
        insertAtBeginning(head, tail, val);
        return;
    }

    Node* newNode = new Node{val, nullptr, nullptr};
    Node* temp = head;

    for (int i = 1; temp != nullptr && i < position - 1; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr || temp == tail) {
        insertAtEnd(head, tail, val);
        delete newNode; 
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}


// 1. Delete from the Beginning
void deleteFromBeginning(Node*& head, Node*& tail) {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

// 2. Delete from the End
void deleteFromEnd(Node*& head, Node*& tail) {
    if (tail == nullptr) return;

    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

// 3. Delete a Specific Value
void deleteValue(Node*& head, Node*& tail, int val) {
    if (head == nullptr) return;

    Node* temp = head;
    while (temp != nullptr && temp->data != val) {
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (temp == head) {
        deleteFromBeginning(head, tail);
        return;
    }
    if (temp == tail) {
        deleteFromEnd(head, tail);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// Helper to print the list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

int main() {
    // Creating raw pointers for our list trackers
    Node* head = nullptr;
    Node* tail = nullptr;

    // Test Insertions
    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 20);
    insertAtBeginning(head, tail, 5);
    insertAtPosition(head, tail, 15, 3);
    std::cout << "Initial list: ";
    display(head);

    // Test Deletions
    deleteFromBeginning(head, tail);
    std::cout << "After deleting front: ";
    display(head);

    deleteFromEnd(head, tail);
    std::cout << "After deleting end: ";
    display(head);

    deleteValue(head, tail, 15);
    std::cout << "After deleting value 15: ";
    display(head);

    return 0;
}
