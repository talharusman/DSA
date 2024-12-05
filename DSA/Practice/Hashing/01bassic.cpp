#include <iostream>
#include <list>
using namespace std;

// Hash Table Class
class HashTable {
private:
    int tableSize; // Size of the hash table
    list<int>* table; // Pointer to an array of linked lists

    // Hash Function
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Constructor
    HashTable(int size) {
        this->tableSize = size;
        table = new list<int>[tableSize];
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            for (auto x : table[i])
                cout << x << " -> ";
            cout << "NULL\n";
        }
    }

    // Destructor
    ~HashTable() {
        delete[] table;
    }
};

// Main Function
int main() {
    HashTable ht(10); // Create a hash table with 7 slots

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(22);

    cout << "Hash table after inserting elements:\n";
    ht.display();

    ht.remove(15);
    cout << "\nHash table after removing 15:\n";
    ht.display();

    return 0;
}
