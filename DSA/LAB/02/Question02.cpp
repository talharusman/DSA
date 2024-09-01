#include <iostream>
using namespace std;

class Matrix {
public:
    int size;
    int **array;

   
    Matrix(int s = 2) : size(s), array(new int*[s]) {
        for (int i = 0; i < size; i++) {
            array[i] = new int[size];
            for (int j = 0; j < size; j++) {
                array[i][j] = 0; 
            }
        }
    }

   
    ~Matrix() {
        for (int i = 0; i < size; i++) {
            delete[] array[i];
        }
        delete[] array;
    }

   
    Matrix(const Matrix &other) : size(other.size), array(new int*[other.size]) {
        for (int i = 0; i < size; i++) {
            array[i] = new int[size];
            for (int j = 0; j < size; j++) {
                array[i][j] = other.array[i][j];
            }
         }
    }

    // Assignment Operator
    Matrix& operator=(const Matrix &other) {
        if (this == &other) return *this; // Self-assignment check

        // Clean up old resources
        for (int i = 0; i < size; i++) {
            delete[] array[i];
        }
        delete[] array;


        size = other.size;
        array = new int*[size];
        for (int i = 0; i < size; i++) {
            array[i] = new int[size];
            for (int j = 0; j < size; j++) {
                array[i][j] = other.array[i][j];
            }
        }

        return *this;
    }

    void printArray() const {
        for (int i = 0; i < size; i++) {
           
            for (int j = 0; j < size; j++) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
};


Matrix multiplyMatrices(const Matrix &mat1, const Matrix &mat2) {
    if (mat1.size != mat2.size) {
        cerr << "Error: Matrices must be of the same size!" << endl;
        exit(EXIT_FAILURE);
    }

    Matrix res(mat1.size);
    for (int i = 0; i < res.size; i++) {
        for (int j = 0; j < res.size; j++) {
            res.array[i][j] = 0;
            
            for (int k = 0; k < res.size; k++) {
                res.array[i][j] += mat1.array[i][k] * mat2.array[k][j];
            }
        }
    }
    return res;
}

int main() {
    Matrix mat1(2);
    Matrix mat2(2);

    // Initialize mat1 and mat2 with some values
    mat1.array[0][0] = 1; mat1.array[0][1] = 2;
    mat1.array[1][0] = 3; mat1.array[1][1] = 4;

    mat2.array[0][0] = 5; mat2.array[0][1] = 6;
    mat2.array[1][0] = 7; mat2.array[1][1] = 8;
    cout<<"mat 1"<<endl;
    mat1.printArray();
     cout<<"mat 2"<<endl;
    mat2.printArray();

    Matrix res = multiplyMatrices(mat1, mat2);
    cout<<"\nResult"<<endl;
    res.printArray();

    return 0;
}
