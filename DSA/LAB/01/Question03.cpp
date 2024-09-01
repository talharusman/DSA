#include <iostream>
#include <cstring>

using namespace std;

class Document {
private:
    char* content;

public:
    Document(const char* initialContent) {
        content = new char[strlen(initialContent) + 1];
        strcpy(content, initialContent);
    }

    ~Document() {
        delete[] content;
    }

    Document(const Document& other) {
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);
    }

    Document& operator=(const Document& other) {
        if (this == &other) return *this;

        delete[] content;

        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);

        return *this;
    }

    void setContent(const char* newContent) {
        delete[] content;

        content = new char[strlen(newContent) + 1];
        strcpy(content, newContent);
    }

    void displayContent() const {
        cout << "Content: " << content << endl;
    }
};

int main() {
    Document original("This is the original document.");
    original.displayContent();

    Document copy1(original);
    copy1.displayContent();

    Document copy2 = original;
    copy2.displayContent();

    original.setContent("The original document has been modified.");
    original.displayContent();

    cout << "After modifying the original document:" << endl;
    copy1.displayContent();
    copy2.displayContent();

    return 0;
}
