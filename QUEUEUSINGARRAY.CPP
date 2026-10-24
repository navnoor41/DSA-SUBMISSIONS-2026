#include <iostream>

const int MAX_SIZE = 5;

// Global queue variables
int queueArray[MAX_SIZE];
int frontIdx = -1;
int rearIdx = -1;

// Add an item to the back
void enqueue(int val) {
    if (rearIdx == MAX_SIZE - 1) {
        std::cout << "Queue Overflow! Cannot enqueue " << val << "\n";
        return;
    }
    if (frontIdx == -1) frontIdx = 0; // First element entering
    queueArray[++rearIdx] = val;
}

// Remove an item from the front
void dequeue() {
    if (frontIdx == -1 || frontIdx > rearIdx) {
        std::cout << "Queue Underflow! Nothing to dequeue.\n";
        return;
    }
    std::cout << "Dequeued: " << queueArray[frontIdx++] << "\n";
    
    // Reset pointers if queue becomes empty
    if (frontIdx > rearIdx) {
        frontIdx = rearIdx = -1;
    }
}

// Print the queue status
void display() {
    if (frontIdx == -1) {
        std::cout << "Queue is empty\n";
        return;
    }
    for (int i = frontIdx; i <= rearIdx; i++) {
        std::cout << queueArray[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();
    return 0;
}
