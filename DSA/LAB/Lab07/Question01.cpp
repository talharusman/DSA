#include <iostream>
using namespace std;

// Node definition for the linked list
struct Nodee {
    int dta;
    Nodee* nxt;

    Nodee(int vl) {
        dta = vl;
        nxt = nullptr;
    }
};

// Function to print the linked list
void printLst(Nodee* hed) {
    while (hed != nullptr) {
        cout << hed->dta << " ";
        hed = hed->nxt;
    }
    cout << endl;
}

// Function to swap two nodes in the linked list
void swapNods(Nodee** hedReff, Nodee* nd1, Nodee* nd2) {
    if (nd1 == nd2) return;

    Nodee* prv1 = nullptr, *prv2 = nullptr, *tmp = *hedReff;

    // Find the previous nodes of nd1 and nd2
    while (tmp != nullptr && (prv1 == nullptr || prv2 == nullptr)) {
        if (tmp->nxt == nd1) prv1 = tmp;
        if (tmp->nxt == nd2) prv2 = tmp;
        tmp = tmp->nxt;
    }

    // Adjust the previous nodes' next pointers
    if (prv1) prv1->nxt = nd2;
    else *hedReff = nd2;

    if (prv2) prv2->nxt = nd1;
    else *hedReff = nd1;

    // Swap the next pointers of nd1 and nd2
    tmp = nd1->nxt;
    nd1->nxt = nd2->nxt;
    nd2->nxt = tmp;
}

// Function to get the tail of the linked list
Nodee* getTal(Nodee* hed) {
    while (hed != nullptr && hed->nxt != nullptr) {
        hed = hed->nxt;
    }
    return hed;
}

// Function to partition the linked list using the last node as pivot
Nodee* partiion(Nodee* hed, Nodee* endd, Nodee** newHed, Nodee** newEndd) {
    Nodee* pivt = endd;
    Nodee* prv = nullptr;
    Nodee* curr = hed;
    Nodee* tal = pivt;

    // Iterate through the list and move nodes less than pivot to the front
    while (curr != pivt) {
        if (curr->dta < pivt->dta) {
            // This is the new head of the list if it's not already set
            if ((*newHed) == nullptr) {
                (*newHed) = curr;
            }
            prv = curr;
            curr = curr->nxt;
        } else { // Move nodes greater than pivot to the end
            if (prv) {
                prv->nxt = curr->nxt;
            }
            Nodee* tmp = curr->nxt;
            curr->nxt = nullptr;
            tal->nxt = curr;
            tal = curr;
            curr = tmp;
        }
    }

    // If the new head hasn't been updated, it means all nodes were greater than pivot
    if ((*newHed) == nullptr) {
        (*newHed) = pivt;
    }

    // Update new end to the current tail
    (*newEndd) = tal;

    return pivt;
}

// The main quicksort recursive function
Nodee* quickSortRecur(Nodee* hed, Nodee* endd) {
    // Base case: if head is empty or if there's only one element
    if (!hed || hed == endd) {
        return hed;
    }

    Nodee* newHed = nullptr;
    Nodee* newEndd = nullptr;

    // Partition the list and get the pivot
    Nodee* pivt = partiion(hed, endd, &newHed, &newEndd);

    // Recursively sort the list before the pivot
    if (newHed != pivt) {
        Nodee* tmp = newHed;
        // Move to the node just before the pivot
        while (tmp->nxt != pivt) {
            tmp = tmp->nxt;
        }
        tmp->nxt = nullptr;

        // Recursively sort the left side
        newHed = quickSortRecur(newHed, tmp);

        // Reconnect the sorted list with the pivot
        tmp = getTal(newHed);
        tmp->nxt = pivt;
    }

    // Recursively sort the list after the pivot
    pivt->nxt = quickSortRecur(pivt->nxt, newEndd);

    return newHed;
}

// Function to sort the linked list using QuickSort
void quickSrt(Nodee** hedReff) {
    (*hedReff) = quickSortRecur(*hedReff, getTal(*hedReff));
}

// Function to insert a new node at the end of the linked list
void insert(Nodee** hedReff, int dta) {
    Nodee* newNod = new Nodee(dta);
    if (*hedReff == nullptr) {
        *hedReff = newNod;
        return;
    }
    Nodee* tmp = *hedReff;
    while (tmp->nxt != nullptr) {
        tmp = tmp->nxt;
    }
    tmp->nxt = newNod;
}

// Test the implementation
int main() {
    Nodee* hed = nullptr;
    insert(&hed, 10);
    insert(&hed, 7);
    insert(&hed, 8);
    insert(&hed, 9);
    insert(&hed, 1);
    insert(&hed, 5);
    insert(&hed, 3);

    cout << "Originnal list: ";
    printLst(hed);

    quickSrt(&hed);

    cout << "Sorrted list: ";
    printLst(hed);

    return 0;
}
