#include <iostream>

class JaggedArray {
private:
    int size;
    int *columnSizes;
    int **array;

public:
    JaggedArray(int s) : size(s), columnSizes(new int[s]), array(new int*[s]) {
        for (int i = 0; i < size; i++) {
            columnSizes[i] = s + i; 
            
            array[i] = new int[columnSizes[i]];
            for (int j = 0; j < columnSizes[i]; j++) {
                array[i][j] = j;
            }
        }
    }
    
    ~JaggedArray() {
        for (int i = 0; i < size; i++) {
            delete[] array[i];
        }
        delete[] array;
        delete[] columnSizes;
    }

    void resize(int newSize) {
      
        int *newColumnSizes = new int[newSize];
        int **newArray = new int*[newSize];

        
        for (int i = 0; i < newSize - 5; i++) {
            newColumnSizes[i] = newSize;
            newArray[i] = new int[newColumnSizes[i]];
            for (int j = 0; j < newColumnSizes[i] ; j++) {
                if (i < size && j < columnSizes[i]) {
                    newArray[i][j] = array[i][j];
                } else {
                    newArray[i][j] = 0;
                }
            }
        }

        
        for (int i = 0; i < size; i++) {
            delete[] array[i];
        }
        delete[] array;
        delete[] columnSizes;

       
        array = newArray;
        columnSizes = newColumnSizes;
        size = newSize;
        
    }

    void printArray() {
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < columnSizes[i]; j++) {
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
    }
};

int main() {
    JaggedArray jaggedArray(5);

    std::cout << "Initial Array:" << std::endl;
    jaggedArray.printArray();

    jaggedArray.resize(10);
    std::cout << "\nResized Array:" << std::endl;
    jaggedArray.printArray();

    return 0;
}
