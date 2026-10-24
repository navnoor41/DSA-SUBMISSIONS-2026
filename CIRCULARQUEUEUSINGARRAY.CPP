#include <iostream>

const int SIZE = 5;

// Global circular queue variables
int circArray[SIZE];
int circFront = -1;
int circRear = -1;

// Add an item circularly
void enqueueCircular(int val) {
    // Condition for full queue
    if ((circFront == 0 && circRear == SIZE - 1) || (circRear == (circFront - 1) % (SIZE - 1))) {
        std::cout << "Circular Queue Full! Cannot enqueue " << val << "\n";
        return;
    }
    
    if (circFront == -1) { // First element entering
        circFront = circRear = 0;
    } else if (circRear == SIZE - 1 && circFront != 0) {
        circRear = 0; // Circular wrap around
    } else {
        circRear++;
    }
    
    circArray[circRear] = val;
}

// Remove an item circularly
void dequeueCircular() {
    if (circFront == -1) {
        std::cout << "Circular Queue Empty! Nothing to dequeue.\n";
        return;
    }

    std::cout << "Dequeued: " << circArray[circFront] << "\n";

    if (circFront == circRear) { // Only one element was left
        circFront = circRear = -1;
    } else if (circFront == SIZE - 1) {
        circFront = 0; // Circular wrap around
    } else {
        circFront++;
    }
}

// Print the circular arrangement correctly
void displayCircular() {
    if (circFront == -1) {
        std::cout << "Queue is empty\n";
        return;
    }
    
    if (circRear >= circFront) {
        for (int i = circFront; i <= circRear; i++) std::cout << circArray[i] << " ";
    } else {
        for (int i = circFront; i < SIZE; i++) std::cout << circArray[i] << " ";
        for (int i = 0; i <= circRear; i++) std::cout << circArray[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    enqueueCircular(10);
    enqueueCircular(20);
    enqueueCircular(30);
    enqueueCircular(40);
    displayCircular();

    dequeueCircular();
    dequeueCircular();
    
    // Pushing more elements will circle around into the empty spaces
    enqueueCircular(50);
    enqueueCircular(60);
    displayCircular();

    return 0;
}
