#include<iostream>
using namespace std;

void displayArrangement(string* seats[], int seatsCount[], int rows) {
    cout << "Seating arrangement:" << endl;
    for (int i = 0; i < rows; i++) {
        cout<<"Row "<<i+1;
        for (int j = 0; j < seatsCount[i]; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Enter the number of rows: ";
    cin >> size;

    string* seats[size];  // Array of pointers to hold the seat arrangement
    int seatsCount[size]; // Array to hold the number of seats in each row

    for (int i = 0; i < size; i++) {
        int inp;
        cout << "Enter the number of seats in Row " << i + 1 << ": ";
        cin >> inp;

        seats[i] = new string[inp]; // Dynamically allocate memory for seats in the current row
        seatsCount[i] = inp;        // Store the number of seats in the current row

        for (int j = 0; j < inp; j++) {
            string name;
            cout << "Enter the name of person on seat " << j + 1 << " in row " << i + 1 << ": ";
            cin >> name;
            seats[i][j] = name; // Assign the name to the appropriate seat
        }
    }

    displayArrangement(seats, seatsCount, size);

    // Free the dynamically allocated memory
    for (int i = 0; i < size; i++) {
        delete[] seats[i];
    }

    return 0;
}
