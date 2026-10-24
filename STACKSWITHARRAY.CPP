#include <iostream>

const int MAX_SIZE = 100;

class ArrayStack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1; // Stack starts empty
    }

    // Push element onto the stack
    void push(int val) {
        if (top >= MAX_SIZE - 1) {
            std::cout << "Stack Overflow! Cannot push " << val << "\n";
            return;
        }
        arr[++top] = val;
    }

    // Pop element from the stack
    void pop() {
        if (top < 0) {
            std::cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        std::cout << "Popped: " << arr[top--] << "\n";
    }

    // Get the top element
    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty.\n";
            return -1;
        }
        return arr[top];
    }

    // Check if empty
    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    ArrayStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element is: " << s.peek() << "\n";
    s.pop();
    std::cout << "Top element after pop is: " << s.peek() << "\n";

    return 0;
}
