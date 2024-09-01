#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* 
A critical point in a linked list is defined as either a local maxima or a local minima.
Given a linked list tail, return an array of length 2 containing [minDistance, maxDistance]
where minDistance is the minimum distance between any two critical points and maxDistance is 
the maximum distance between any two critical points. If there are fewer than two critical points, 
return [-1, -1].

Note that a node can only be a local maxima/minima if there exists both a previous
node and a next node.

eg 1:
1<->5<->2<->6<->3;
5, 6 are local maxima because their neighbors are less than them.
2 is local minima because its neighbors are greater than it.

eg 2:
1<->2<->3<->4<->5<->6<->7
there are no local min and max.
*/

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class doubleLinkedList {
public:
    Node* head;
    Node* tail;
    doubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

bool IsCriticalPoint(Node* currNode) {
    if (currNode->prev == nullptr || currNode->next == nullptr) {
        return false;
    }
    if ((currNode->prev->value < currNode->value && currNode->next->value < currNode->value) || // local maxima
        (currNode->prev->value > currNode->value && currNode->next->value > currNode->value)) { // local minima
        return true;
    }
    return false;
}

vector<int> DistanceBetweenCriticalPoints(Node* head) {
    vector<int> result(2, -1);
    if (!head || !head->next || !head->next->next) {
        return result; // If there are fewer than 3 nodes, no critical points exist
    }

    int firstCP = -1, lastCP = -1, minDistance = INT_MAX;
    int index = 0, cpCount = 0;
    Node* currNode = head->next;

    while (currNode->next != nullptr) {
        if (IsCriticalPoint(currNode)) {
            cpCount++;
            if (firstCP == -1) {
                firstCP = index;
            } else {
                minDistance = min(minDistance, index - lastCP);
            }
            lastCP = index;
        }
        currNode = currNode->next;
        index++;
    }

    if (cpCount < 2) {
        return result; // If fewer than 2 critical points, return [-1, -1]
    }

    result[0] = minDistance;
    result[1] = lastCP - firstCP;
    return result;
}

int main() {
    doubleLinkedList dll;
    cout << "Initial linked list:" << endl;
    dll.InsertAtTail(1);
    dll.InsertAtTail(5);
    dll.InsertAtTail(4);
    dll.InsertAtTail(2);
    dll.InsertAtTail(6);
    dll.InsertAtTail(3);
    dll.display();

    vector<int> ans = DistanceBetweenCriticalPoints(dll.head);
    cout << "Minimum distance: " << ans[0] << ", Maximum distance: " << ans[1] << endl;

    return 0;
}
