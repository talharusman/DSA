#include <iostream>
using namespace std;

void inputAndDisplayGPA(float* GPA, int numCourses, const string& departmentName) {
    for (int i = 0; i < numCourses; i++) {
        cout << "Enter GPA for " << departmentName << " course " << i + 1 << ": ";
        cin >> GPA[i];
    }
    
    cout << "GPAs for " << departmentName << ": ";
    for (int i = 0; i < numCourses; i++) {
        cout << GPA[i] << ", ";
    }
    cout << endl;
}

int main() {
    
    float* GPA[4];
    
   
    GPA[0] = new float[3]; 
    GPA[1] = new float[4];
    GPA[2] = new float[2]; 
    GPA[3] = new float[1];

    int dep;
    cout << "Which department's GPA do you want to display? (1-SE, 2-AI, 3-CS, 4-DS): ";
    cin >> dep;
    switch (dep) {
        case 1:
        inputAndDisplayGPA(GPA[0], 3, "SE");
        break;
        case 2:
        inputAndDisplayGPA(GPA[1], 4, "AI");
        break;
        case 3:
        inputAndDisplayGPA(GPA[2], 2, "CS");
        break;
        case 4:
        inputAndDisplayGPA(GPA[3], 1, "DS");
        break;
        default:
        cout << "Invalid department choice.";
    }
    for (int i = 0; i < 4; i++) {
        delete[] GPA[i];
    }

   
    return 0;
}
