#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T, int capacity>
class Stack {
private:
    T data[capacity];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    void push(const T& item) {
        if (topIndex >= capacity - 1) {
            throw StackOverflowException();
        }
        data[++topIndex] = item;
    }

    T pop() {
        if (topIndex < 0) {
            throw StackUnderflowException();
        }
        return data[topIndex--];
    }
};

int main() {
    Stack<int, 3> stack;

    try {
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
    } catch (const StackOverflowException& e) {
        cout << "Pushing to a full stack: " << e.what() << endl;
    }

    try {
        Stack<int, 3> emptyStack;
        emptyStack.pop();
    } catch (const StackUnderflowException& e) {
        cout << "Popping from an empty stack: " << e.what() <<endl;
    }

    return 0;
}