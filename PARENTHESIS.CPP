#include <iostream>
#include <string>

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop(Node*& top) {
    if (top == nullptr) return;
    Node* temp = top;
    top = top->next;
    delete temp;
}

bool isEmpty(Node* top) {
    return (top == nullptr);
}

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}

bool checkParentheses(std::string expr) {
    Node* stack = nullptr;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stack, ch);
        }
        // Check closing brackets against the stack top
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(stack) || !isMatchingPair(stack->data, ch)) {
                // Free stack memory before returning false
                while (!isEmpty(stack)) pop(stack);
                return false;
            }
            pop(stack);
        }
    }

    bool balanced = isEmpty(stack);
    while (!isEmpty(stack)) pop(stack); // Clean up remaining nodes
    return balanced;
}

int main() {
    std::string expr1 = "{()}[]";
    std::string expr2 = "{(})";

    std::cout << expr1 << " is " << (checkParentheses(expr1) ? "Balanced\n" : "Not Balanced\n");
    std::cout << expr2 << " is " << (checkParentheses(expr2) ? "Balanced\n" : "Not Balanced\n");

    return 0;
}
