#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;
class FileException : public exception {
protected:
    string message;
public:
    FileException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class FileNotFoundException : public FileException {
public:
    FileNotFoundException(const std::string& filename) 
        : FileException("FileNotFoundException - " + filename + " not found!") {}
};

class PermissionDeniedException : public FileException {
public:
    PermissionDeniedException(const string& filename) 
        : FileException("PermissionDeniedException - Access denied to " + filename + "!") {}
};

void readFile(const string& filename) {
    ifstream file(filename);
    
    if (!file.good()) {
        if (filename == "secret.txt") {
            throw PermissionDeniedException(filename);
        } else {
            throw FileNotFoundException(filename);
        }
    }
    
    file.close();
}

int main() {
    try {
        readFile("secret.txt");
    } catch (const FileException& e) {
        cout << "Reading 'secret.txt': " << e.what() << endl;
    }

    try {
        readFile("nonexistent.txt");
    } catch (const FileException& e) {
        cout << "Reading 'nonexistent.txt': " << e.what() << endl;
    }

    return 0;
}