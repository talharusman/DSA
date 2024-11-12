#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <chrono>
#include <limits>


using namespace std;
using namespace std::chrono;

class Menu{
    public:
    Menu(){}
    ~Menu(){}

    void displayMainMenu() {
        cout << "\nTicket Management System Menu\n";
        cout << "1. Add Ticket\n";
        cout << "2. Close Ticket\n";
        cout << "3. Remove Ticket\n";
        cout << "4. Search Ticket\n";
        cout << "5. Display Open Tickets\n";
        cout << "6. Sort Tickets\n";
        cout << "7. Display Agents by Load\n";
        cout << "8. View Ticket Resolution Logs\n";
        cout << "9. Add Agent\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
    }

    void displaySortingMenu() {
        cout << "\nSorting Options\n";
        cout << "1. Sort by Priority\n";
        cout << "2. Sort by Creation Time\n";
        cout << "3. Sort by Customer Name\n";
        cout << "Enter your choice: ";
    }

    void displaySortingType(){
         cout << "Choose sorting algorithm:\n";
         cout << "1. Bubble Sort\n";
         cout << "2. Insertion Sort\n";
         cout << "3. Selection Sort\n";
         cout << "4. Merge Sort\n";
         cout << "5. Quick Sort\n";
         cout << "Enter your choice: ";
    }

    void displaySearchMenu() {
        cout << "\nSearch Options\n";
        cout << "1. Search by Ticket ID\n";
        cout << "2. Search by Customer Name\n";
        cout << "Enter your choice: ";
    }

};

// Forward declaration of TicketList for friend relationship
class TicketList;



// Ticket structure
struct Ticket {
    int ticketID;
    string customerName;
    int priority; // 1 = High, 2 = Medium, 3 = Low
    string description;
    time_t creationTime;
    string status; // "open" or "closed"
    time_t closeTime;
    Ticket* next; // Pointer to the next ticket
};

// Agent structure
struct Agent {
    int agentID;
    string name;
    vector<int> assignedTickets; // List of Ticket IDs
    bool available;

    Agent(int id, string agentName) : agentID(id), name(agentName), available(true) {}
};


// Sorting and Searching Algorithm Selection
enum class SortAlgorithm { Bubble, Insertion, Selection, Merge, Quick };
enum class SearchAlgorithm { Linear, Binary };

SortAlgorithm sortAlgorithm = SortAlgorithm::Quick;
SearchAlgorithm searchAlgorithm = SearchAlgorithm::Linear;

// Threshold for using elementary or advanced sorting
const int THRESHOLD = 10;

// Bubble Sort
void bubbleSort(vector<Ticket*>& tickets) {
    for (size_t i = 0; i < tickets.size(); ++i) {
        for (size_t j = 0; j < tickets.size() - i - 1; ++j) {
            if (tickets[j]->priority > tickets[j + 1]->priority) {
                swap(tickets[j], tickets[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(vector<Ticket*>& tickets) {
    for (size_t i = 1; i < tickets.size(); ++i) {
        Ticket* key = tickets[i];
        int j = i - 1;
        while (j >= 0 && tickets[j]->priority > key->priority) {
            tickets[j + 1] = tickets[j];
            j--;
        }
        tickets[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<Ticket*>& tickets) {
    for (size_t i = 0; i < tickets.size() - 1; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < tickets.size(); ++j) {
            if (tickets[j]->priority < tickets[minIdx]->priority) {
                minIdx = j;
            }
        }
        swap(tickets[i], tickets[minIdx]);
    }
}

// Merge Sort
void merge(vector<Ticket*>& tickets, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Ticket*> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = tickets[left + i];
    for (int j = 0; j < n2; ++j) R[j] = tickets[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i]->priority <= R[j]->priority) tickets[k++] = L[i++];
        else tickets[k++] = R[j++];
    }
    while (i < n1) tickets[k++] = L[i++];
    while (j < n2) tickets[k++] = R[j++];
}

void mergeSort(vector<Ticket*>& tickets, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(tickets, left, mid);
        mergeSort(tickets, mid + 1, right);
        merge(tickets, left, mid, right);
    }
}

// Quick Sort
int partition(vector<Ticket*>& tickets, int low, int high) {
    Ticket* pivot = tickets[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (tickets[j]->priority < pivot->priority) {
            swap(tickets[++i], tickets[j]);
        }
    }
    swap(tickets[i + 1], tickets[high]);
    return i + 1;
}

void quickSort(vector<Ticket*>& tickets, int low, int high) {
    if (low < high) {
        int pi = partition(tickets, low, high);
        quickSort(tickets, low, pi - 1);
        quickSort(tickets, pi + 1, high);
    }
}



// Class for managing ticket resolution logs
class TicketResolutionLog {
public:
    stack<int> resolutionStack; // Stack to log closed tickets

    // Log closed ticket into the stack
    void logClosedTicket(int ticketID) {
        resolutionStack.push(ticketID);
        cout << "Ticket ID " << ticketID << " logged in resolution stack." << endl;
    }

    // Display the most recent ticket resolution logs
    void viewLogs() {
        if (resolutionStack.empty()) {
            cout << "No ticket resolutions logged yet." << endl;
            return;
        }
        cout << "Recent Ticket Resolution Logs:" << endl;
        stack<int> tempStack = resolutionStack;
        while (!tempStack.empty()) {
            cout << "Ticket ID: " << tempStack.top() << endl;
            tempStack.pop();
        }
    }
};

// Class for managing pending ticket queue
class PendingTicketQueue {
public:
    queue<Ticket*> pendingQueue; // Queue for pending tickets

    // Add ticket to the pending queue
    void addTicketToQueue(Ticket* ticket) {
        pendingQueue.push(ticket);
        cout << "Ticket ID " << ticket->ticketID << " added to pending queue." << endl;
    }

    // Get next pending ticket
    Ticket* getNextPendingTicket() {
        return pendingQueue.empty() ? nullptr : pendingQueue.front();
    }

    void removeTicketFromQueue() {
        if (!pendingQueue.empty()) pendingQueue.pop();
    }
};


// Agent management class
class AgentManager {
public:

    vector<Agent> agents; // List of agents
    PendingTicketQueue pendingTickets; // Queue for unassigned tickets
    // queue<Ticket*> ticketQueue; // Queue for unassigned tickets

    // Add a new agent
    void addAgent(int agentID, string name) {
        agents.emplace_back(agentID, name);
        cout << "Agent added with ID: " << agentID << endl;
        assignQueuedTickets(); // Attempt to assign any queued tickets
    }

    // Assign a ticket to an available agent
    bool assignTicketToAgent(Ticket& ticket) {
        for (auto& agent : agents) {
            if (agent.available && agent.assignedTickets.size() < 5) {
                agent.assignedTickets.push_back(ticket.ticketID);
                cout << "Assigned Ticket ID " << ticket.ticketID << " to Agent ID " << agent.agentID << endl;
                
                // Check if the agent is now at full capacity
                if (agent.assignedTickets.size() >= 5) {
                    agent.available = false; // Mark agent as unavailable
                }
                return true; // Ticket assigned successfully
            }
        }

        cout << "No available agents to assign Ticket ID " << ticket.ticketID << endl;
        return false; // No agents available
    }

    // Queue a ticket if no agents are available
    void queueTicket(Ticket* ticket) {
        pendingTickets.addTicketToQueue(ticket);
        cout << "Ticket ID " << ticket->ticketID << " queued for assignment." << endl;
    }

    // Assign queued tickets to available agents
    void assignQueuedTickets() {
    while (!pendingTickets.pendingQueue.empty()) {
        Ticket* ticket = pendingTickets.getNextPendingTicket();
        if (assignTicketToAgent(*ticket)) {
            pendingTickets.removeTicketFromQueue(); // Remove ticket if assigned
        } else {
            break; // No available agents, exit the loop
        }
    }
}


    // Remove a ticket from all agents' assigned tickets
    void removeTicketFromAgents(int ticketID) {
        for (auto& agent : agents) {
            auto it = find(agent.assignedTickets.begin(), agent.assignedTickets.end(), ticketID);
            if (it != agent.assignedTickets.end()) {
                agent.assignedTickets.erase(it); // Remove ticket from agent's list
                cout << "Removed Ticket ID " << ticketID << " from Agent ID " << agent.agentID << endl;
                  // assignQueuedTickets(); i we think it on latter i will chake if agent is free the i assing thee new tikit

                // Check if the agent can be marked as available again
                if (agent.assignedTickets.size() < 5) {

                    agent.available = true; // Mark agent as available
                }
            }
        }
    }

    // Display agents sorted by their assigned ticket load
    void displayAgentsByLoad() {
        // sort(agents.begin(), agents.end(), [](const Agent& a, const Agent& b) {
        //     return a.assignedTickets.size() > b.assignedTickets.size();
        // });

        cout << "\nAgent Ticket Load:\n";
        for (const auto& agent : agents) {
            cout << "Agent ID: " << agent.agentID 
                 << ", Name: " << agent.name 
                 << ", Assigned Tickets: " << agent.assignedTickets.size() 
                 << ", Available: " << (agent.available ? "Yes" : "No") << endl;
        }
    }

    friend class TicketList;
};


// Linked list for managing tickets
class TicketList {
private:
    Ticket* head;
    int ticketCounter;
    AgentManager &agents;
    TicketResolutionLog ticketLog;

public:
    TicketList(AgentManager &agent) : head(nullptr), ticketCounter(1), agents(agent) {}

    // Add a new ticket
    void addTicket(string customerName, int priority, string description) {
        Ticket* newTicket = new Ticket();
        newTicket->ticketID = ticketCounter++;
        newTicket->customerName = customerName;
        newTicket->priority = priority;
        newTicket->description = description;
        newTicket->creationTime = time(0);
        newTicket->status = "open";
        newTicket->next = head;
        head = newTicket;

        // Try to assign ticket to an available agent
        if (!agents.assignTicketToAgent(*newTicket)) {
            agents.queueTicket(newTicket); // Store in queue if no agents are available
            
        }

        cout << "Ticket added with ID: " << newTicket->ticketID << endl;
    }

    // Remove a ticket by Ticket ID
    void removeTicket(int ticketID) {
        Ticket* current = head;
        Ticket* prev = nullptr;

        while (current != nullptr && current->ticketID != ticketID) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Ticket with ID " << ticketID << " not found." << endl;
            return;
        }

        // Remove from agent's assigned tickets
        agents.removeTicketFromAgents(ticketID);

        if (prev == nullptr) {
            head = current->next; // Removing head
        } else {
            prev->next = current->next;
        }

        delete current;

        cout << "Ticket with ID " << ticketID << " removed." << endl;
    }

    // Search for a ticket by Ticket ID
    Ticket* searchByID(int ticketID) {
        Ticket* current = head;

        while (current != nullptr) {
            if (current->ticketID == ticketID) {
                return current;
            }
            current = current->next;
        }

        return nullptr; // Ticket not found
    }
    Ticket* binarySearchByID(vector<Ticket>& tickets, int targetID) {
        int left = 0;
        int right = tickets.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (tickets[mid].ticketID == targetID) {
                return &tickets[mid];  // Return a pointer to the found ticket
            }
            else if (tickets[mid].ticketID < targetID) {
                left = mid + 1;  // Search in the right half
            }
            else {
                right = mid - 1; // Search in the left half
            }
        }

        return nullptr; // Ticket not found
    }

    // Search for tickets by customer name
    void searchByName(string customerName) {
        Ticket* current = head;
        bool found = false;

        while (current != nullptr) {
            if (current->customerName == customerName) {
                printTicketDetails(current);
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            cout << "No tickets found for customer: " << customerName << endl;
        }
    }


      void sortTickets(vector<Ticket*>& tickets) {
        auto start = high_resolution_clock::now();

        if (tickets.size() <= THRESHOLD) {
            if (sortAlgorithm == SortAlgorithm::Bubble) bubbleSort(tickets);
            else if (sortAlgorithm == SortAlgorithm::Insertion) insertionSort(tickets);
            else if (sortAlgorithm == SortAlgorithm::Selection) selectionSort(tickets);
        } else {
            if (sortAlgorithm == SortAlgorithm::Merge) mergeSort(tickets, 0, tickets.size() - 1);
            else if (sortAlgorithm == SortAlgorithm::Quick) quickSort(tickets, 0, tickets.size() - 1);
        }

        auto end = high_resolution_clock::now();
        cout << "Sorting took: " << duration_cast<microseconds>(end - start).count() << " microseconds.\n";
    }

 // Sort tickets by priority using vector for better efficiency
    void SortTicketsByPriority(vector<Ticket*>& tickets) {
        sort(tickets.begin(), tickets.end(), [](const Ticket* a, const Ticket* b) {
            return a->priority < b->priority;
        });
    }

    vector<Ticket*> makeTickeVector(){
        vector<Ticket*> tickets;
        Ticket* current = head;
        while (current)
        {
            tickets.push_back(current);
            current = current->next;
        }
        return tickets;
    } 


    void sortTicketsByPriority(){
        vector<Ticket*> tickets = makeTickeVector();
        Menu menu;
        menu.displaySortingType();
        int sortAlgoChoice;
        cin >> sortAlgoChoice;
        // Set the sorting algorithm based on user choice
        if (sortAlgoChoice == 1) sortAlgorithm = SortAlgorithm::Bubble;
        else if (sortAlgoChoice == 2) sortAlgorithm = SortAlgorithm::Insertion;
        else if (sortAlgoChoice == 3) sortAlgorithm = SortAlgorithm::Selection;
        else if (sortAlgoChoice == 4) sortAlgorithm = SortAlgorithm::Merge;
        else if (sortAlgoChoice == 5) sortAlgorithm = SortAlgorithm::Quick;
        sortTickets(tickets);

        
    }

    // Sort tickets by creation time using vector for better efficiency
    void SortTicketsByCreationTime(vector<Ticket*>& tickets) {
        sort(tickets.begin(), tickets.end(), [](const Ticket* a, const Ticket* b) {
            return difftime(a->creationTime, b->creationTime) < 0;
        });
    }

    void sortTicketsByCreationTime(){
        vector<Ticket*> tickets = makeTickeVector();
        SortTicketsByCreationTime(tickets);
    }


    // Sort tickets by customer name
    void sortTicketsByCustomerName() {
        if (!head || !head->next) return;

        for (Ticket* i = head; i != nullptr; i = i->next) {
            for (Ticket* j = i->next; j != nullptr; j = j->next) {
                if (i->customerName > j->customerName) {
                    swap(i, j);
                } else if (i->customerName == j->customerName) {
                    if (difftime(i->creationTime, j->creationTime) > 0) {
                        swap(i, j);
                    }
                }
            }
        }

        cout << "Tickets sorted by customer name." << endl;
    }

    // Close a ticket
    void closeTicket(int ticketID) {
        Ticket* ticket = searchByID(ticketID);
        if (ticket == nullptr) {
            cout << "Ticket with ID " << ticketID << " not found." << endl;
            return;
        }

        if (ticket->status == "closed") {
            cout << "Ticket ID " << ticketID << " is already closed." << endl;
        } else {
            ticket->status = "closed";
            ticket->closeTime = time(0);
            cout << "Ticket ID " << ticketID << " closed." << endl;
            agents.removeTicketFromAgents(ticketID);
            ticketLog.logClosedTicket(ticketID);
        }
    }

    // Display all open tickets sorted by priority or creation time
    void displayOpenTicketsSorted(bool sortByPriority = true) {
        vector<Ticket*> openTickets;

        for (Ticket* current = head; current != nullptr; current = current->next) {
            if (current->status == "open") {
                openTickets.push_back(current);
            }
        }

        if (sortByPriority) {
             Menu menu;
            menu.displaySortingType();
            int sortAlgoChoice;
            cin >> sortAlgoChoice;
            // Set the sorting algorithm based on user choice
            if (sortAlgoChoice == 1) sortAlgorithm = SortAlgorithm::Bubble;
            else if (sortAlgoChoice == 2) sortAlgorithm = SortAlgorithm::Insertion;
            else if (sortAlgoChoice == 3) sortAlgorithm = SortAlgorithm::Selection;
            else if (sortAlgoChoice == 4) sortAlgorithm = SortAlgorithm::Merge;
            else if (sortAlgoChoice == 5) sortAlgorithm = SortAlgorithm::Quick;

            sortTickets(openTickets);
        } else {
            SortTicketsByCreationTime(openTickets);
        }

        cout << "\nOpen Tickets:\n";
        for (const auto& ticket : openTickets) {
            cout << "Ticket ID: " << ticket->ticketID
                 << ", Priority: " << ticket->priority
                 << ", Customer: " << ticket->customerName
                 << ", Created At: " << ctime(&ticket->creationTime);
        }
    }

    // View ticket resolution logs
    void viewResolutionLogs() {
        cout << "\nTicket Resolution History:\n";
        ticketLog.viewLogs();
    }

    // Print ticket details
    void printTicketDetails(Ticket* ticket) {
        cout << "Ticket ID: " << ticket->ticketID << endl;
        cout << "Customer Name: " << ticket->customerName << endl;
        cout << "Priority: " << (ticket->priority == 1 ? "High" : (ticket->priority == 2 ? "Medium" : "Low")) << endl;
        cout << "Description: " << ticket->description << endl;
        cout << "Status: " << ticket->status << endl;
        cout << "Creation Time: " << ctime(&ticket->creationTime);
        if (ticket->status == "closed") {
            cout << "Close Time: " << ctime(&ticket->closeTime);
        }
        cout << "-------------------------------" << endl;
    }
};




// Main function for testing
int main() {
    Menu menu;
    AgentManager agentManager;
    TicketList ticketList(agentManager);
    int mainChoice;
    ticketList.addTicket("John Doe", 1, "Network issue");
    ticketList.addTicket("Jane Doe", 2, "Software installation");
    ticketList.addTicket("Jim Beam", 3, "Password reset");
    agentManager.addAgent(1, "Bob");

    while (true) {
        menu.displayMainMenu();
        cin >> mainChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (mainChoice == 10) {
            cout << "Exiting the system. Goodbye!\n";
            break;
        }

        switch (mainChoice) {
            case 1: {
                string customerName, description;
                int priority;
                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, customerName);
                cout << "Enter ticket priority (1 = High, 2 = Medium, 3 = Low): ";
                cin >> priority;
                cout << "Enter ticket description: ";
                cin.ignore();
                getline(cin, description);
                ticketList.addTicket(customerName, priority, description);
                break;
            }
            case 2: {
                int ticketID;
                cout << "Enter Ticket ID to close: ";
                cin >> ticketID;
                ticketList.closeTicket(ticketID);
                break;
            }
            case 3: {
                int ticketID;
                cout << "Enter Ticket ID to remove: ";
                cin >> ticketID;
                ticketList.removeTicket(ticketID);
                break;
            }
            case 4: {
                menu.displaySearchMenu();
                int searchChoice;
                cin >> searchChoice;
                if (searchChoice == 1) {
                    int ticketID;
                    cout << "Enter Ticket ID to search: ";
                    cin >> ticketID;
                    Ticket* ticket = ticketList.searchByID(ticketID);
                    if (ticket) {
                        ticketList.printTicketDetails(ticket);
                    } else {
                        cout << "Ticket not found.\n";
                    }
                } else if (searchChoice == 2) {
                    string customerName;
                    cout << "Enter Customer Name to search: ";
                    cin.ignore();
                    getline(cin, customerName);
                    ticketList.searchByName(customerName);
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 5: {
                bool sortByPriority;
                cout << "Display open tickets sorted by (1 = Priority, 2 = Creation Time): ";
                int sortChoice;
                cin >> sortChoice;
                sortByPriority = (sortChoice == 1);
                ticketList.displayOpenTicketsSorted(sortByPriority);
                break;
            }
            case 6: {
                menu.displaySortingMenu();
                int sortChoice;
                cin >> sortChoice;
                if (sortChoice == 1) {
                    ticketList.sortTicketsByPriority();
                    cout << "Tickets sorted by priority.\n";
                } else if (sortChoice == 2) {
                    ticketList.sortTicketsByCreationTime();
                    cout << "Tickets sorted by creation time.\n";
                } else if (sortChoice == 3) {
                    ticketList.sortTicketsByCustomerName();
                    cout << "Tickets sorted by customer name.\n";
                } else {
                    cout << "Invalid sorting choice.\n";
                }
                break;
            }
            case 7: {
                agentManager.displayAgentsByLoad();
                break;
            }
            case 8: {
                ticketList.viewResolutionLogs();
                break;
            }
            case 9: {
                int agentID;
                string agentName;
                cout << "Enter Agent ID: ";
                cin >> agentID;
                cout << "Enter Agent Name: ";
                cin.ignore();
                getline(cin, agentName);
                agentManager.addAgent(agentID, agentName);
                break;
            }
            default: {
                cout << "Invalid choice. Please select an option from the menu.\n";
            }
        }
    }

    return 0;
}