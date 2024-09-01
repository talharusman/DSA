#include <iostream>
#include <string>
using namespace std;


class Exam {
private:
    string studentName;
    string examDate;
    double* score; 

public:
    
    Exam(string name, string date, double score) {
        this->studentName = name;
        this->examDate = date;
        this->score = new double; 
        *(this->score) = score;
    }
    Exam(const Exam &other) {
        this->studentName = other.studentName;
        this->examDate = other.examDate;
        this->score = new double;
        *(this->score) = *(other.score);
    }

    ~Exam() {
        delete score; 
    }
    void setStudentName(string name) {
        this->studentName = name;
    }
    void setExamDate(string date) {
        this->examDate = date;
    }
    void setScore(double score) {
        *(this->score) = score;
    }
    void displayExamDetails() {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << *(this->score) << endl;
    }
};

int main() {
 
    Exam exam1("Talha Rusman", "2022-01-01", 85.0);
    exam1.displayExamDetails();
   
    Exam exam2 = exam1;
    exam2.displayExamDetails();
    exam2.setScore(90.0);
    exam2.displayExamDetails();
    exam1.displayExamDetails();


    return 0;
}
