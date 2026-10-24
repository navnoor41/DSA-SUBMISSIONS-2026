#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
};

// Enqueue: Add an element to the rear of the queue
void enqueue(Node*& front, Node*& rear, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;

    // If queue is empty, both front and rear point to the new node
    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }

    // Add new node at the end and update rear
    rear->next = newNode;
    rear = newNode;
}

// Dequeue: Remove an element from the front of the queue
void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        std::cout << "Queue Underflow! Nothing to dequeue.\n";
        return;
    }

    Node* temp = front;
    std::cout << "Dequeued: " << temp->data << "\n";
    front = front->next;

    // If front becomes null, then the queue is empty, so update rear to null as well
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
}

// Peek: View the front element without removing it
int peek(Node* front) {
    if (front == nullptr) {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    return front->data;
}

// Check if the queue is empty
bool isEmpty(Node* front) {
    return (front == nullptr);
}

// Display all elements in the queue
void display(Node* front) {
    if (front == nullptr) {
        std::cout << "Queue is empty\n";
        return;
    }
    Node* temp = front;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // Test Enqueue
    enqueue(front, rear, 10);
    enqueue(front, rear, 20);
    enqueue(front, rear, 30);
    std::cout << "Queue after enqueuing 10, 20, 30: ";
    display(front);

    // Test Peek
    std::cout << "Front element is: " << peek(front) << "\n";

    // Test Dequeue
    dequeue(front, rear);
    std::cout << "Queue after dequeue: ";
    display(front);

    // Clean up remaining memory
    while (!isEmpty(front)) {
        dequeue(front, rear);
    }

    return 0;
}
