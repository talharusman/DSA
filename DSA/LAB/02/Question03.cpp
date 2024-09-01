#include<iostream>
using namespace std;

bool hasCommonFriend(bool friendshipMatrix[][5], int person1, int person2) {
    for (int i = 0; i < 5; i++) {
        if (friendshipMatrix[person1][i] && friendshipMatrix[person2][i]) {
            return true;
        }
    }
    return false;
}

int main() {
    bool friendshipMatrix[5][5] = {
        {false, true,  false, true,  true},
        {true,  false, true,  false, true},
        {false, true,  false, false, false},
        {true,  false, false, false, true},
        {true,  true,  false, true,  false},
    };
    int person1, person2;
    cout << "Enter the first person (0-4): ";
    cin >> person1;
    cout << "Enter the second person (0-4): ";
    cin >> person2;

    if (hasCommonFriend(friendshipMatrix, person1, person2)) {
        cout << "They have common friends.";
    } else {
        cout << "They have no common friends.";
    }

    return 0;
}
