#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class LinkedList {
public:
    ListNode* head;
    
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void display() {
        ListNode* current = head;
        while (current) {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

ListNode* mergeKSortedLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    for (auto list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (!minHeap.empty()) {
        ListNode* smallest = minHeap.top();
        minHeap.pop();

        current->next = smallest;
        current = current->next;

        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    ListNode* mergedList = dummy->next;
    delete dummy;
    return mergedList;
}

int main() {
    LinkedList list1;
    list1.insert(1);
    list1.insert(4);
    list1.insert(5);

    LinkedList list2;
    list2.insert(1);
    list2.insert(3);
    list2.insert(4);

    LinkedList list3;
    list3.insert(2);
    list3.insert(6);

    vector<ListNode*> lists = {list1.head, list2.head, list3.head};

    ListNode* mergedList = mergeKSortedLists(lists);

    cout << "Merged Linked List: ";
    while (mergedList) {
        cout << mergedList->val << " -> ";
        mergedList = mergedList->next;
    }
    cout << "nullptr" << endl;

    return 0;
}
