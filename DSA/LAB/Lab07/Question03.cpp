#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;

    Student(const string &name, int score) : name(name), score(score), next(nullptr) {}
};

class StudentList {
private:
    Student* head;

public:
    StudentList() : head(nullptr) {}

    void addStudent(const string &name, int score) {
        Student* newStudent = new Student(name, score);
        newStudent->next = head;
        head = newStudent;
    }

    void radixSort() {
        vector<Student*> buckets(101, nullptr);
        vector<Student*> bucketTails(101, nullptr);

        Student* current = head;
        while (current) {
            int score = current->score;
            if (buckets[score] == nullptr) {
                buckets[score] = current;
                bucketTails[score] = current;
            } else {
                bucketTails[score]->next = current;
                bucketTails[score] = current;
            }
            current = current->next;
        }

        head = nullptr;
        Student* tail = nullptr;

        for (int i = 0; i <= 100; ++i) {
            if (buckets[i] != nullptr) {
                if (head == nullptr) {
                    head = buckets[i];
                    tail = bucketTails[i];
                } else {
                    tail->next = buckets[i];
                    tail = bucketTails[i];
                }
            }
        }

        if (tail != nullptr) {
            tail->next = nullptr;
        }
    }
    void displaySortedList() const {
        Student* current = head;
        cout << "Sorted list of students by score:\n";
        while (current) {
            cout <<current->name <<" " << current->score << endl;
            current = current->next;
        }
    }
    ~StudentList() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    StudentList studentList;
    studentList.addStudent("Talha_Rusman",90);
    studentList.addStudent("Raghib",80);
    studentList.addStudent("Ahmed",100);
    studentList.addStudent("Ali",40);


    studentList.radixSort();
    studentList.displaySortedList();

    return 0;
}
