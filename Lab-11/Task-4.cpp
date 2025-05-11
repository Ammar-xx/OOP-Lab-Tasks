#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class NegativeNumberException : public exception {
private:
    string message;
public:
    NegativeNumberException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidTypeException : public exception {
private:
    string message;
public:
    InvalidTypeException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
T sqrt(T num) {
    if (num < 0) {
        throw NegativeNumberException("NegativeNumberException - Input must be non-negative!");
    }
    T result = num;
    for (int i = 0; i < 10; ++i) {
        result = (result + num / result) / 2;
    }
    return result;
}

template <>
string sqrt<string>(string num) {
    throw InvalidTypeException("InvalidTypeException - Non-numeric type detected!");
}

int main() {
    try {
        cout << "sqrt(-4): " << sqrt(-4) << endl;
    } catch (const NegativeNumberException& e) {
        cout << "sqrt(-4): " << e.what() << endl;
    }

    try {
        cout << "sqrt(\"hello\"): " << sqrt(string("hello")) << endl;
    } catch (const InvalidTypeException& e) {
        cout << "sqrt(\"hello\"): " << e.what() << endl;
    }

    try {
        cout << "sqrt(16): " << sqrt(16) << endl;
    	cout << "sqrt(25.0): " << sqrt(25.0) << endl;
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}