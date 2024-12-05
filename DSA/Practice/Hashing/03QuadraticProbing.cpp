#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;  // Hash table array
    int tableSize;      // Size of the hash table
    int emptyValue;     // Value used to indicate empty slots

    // Hash function
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Constructor
    HashTable(int size) {
        tableSize = size;
        emptyValue = -1;         // -1 indicates an empty slot
        table.resize(tableSize, emptyValue);
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing to handle collisions
        while (table[(index + i * i) % tableSize] != emptyValue) {
            i++;
            if (i == tableSize) { // Full table check
                cout << "Hash table is full. Cannot insert " << key << ".\n";
                return;
            }
        }

        table[(index + i * i) % tableSize] = key;
    }

    // Remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing to search for the key
        while (table[(index + i * i) % tableSize] != emptyValue) {
            if (table[(index + i * i) % tableSize] == key) {
                table[(index + i * i) % tableSize] = emptyValue; // Mark the slot as empty
                return;
            }
            i++;
            if (i == tableSize) break; // If entire table is traversed
        }

        cout << "Key " << key << " not found.\n";
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing to search for the key
        while (table[(index + i * i) % tableSize] != emptyValue) {
            if (table[(index + i * i) % tableSize] == key) {
                return true;
            }
            i++;
            if (i == tableSize) break; // If entire table is traversed
        }

        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i] == emptyValue)
                cout << i << ": Empty\n";
            else
                cout << i << ": " << table[i] << "\n";
        }
    }
};

// Main function
int main() {
    HashTable ht(7); // Create a hash table with 7 slots

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(22);

    cout << "Hash table after inserting elements:\n";
    ht.display();

    cout << "\nSearching for 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n";

    ht.remove(15);
    cout << "\nHash table after removing 15:\n";
    ht.display();

    cout << "\nSearching for 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n";

    return 0;
}
