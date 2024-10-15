#include <iostream>  
#include <stdexcept>  
using namespace std;
class DynamicArray {
private:
    int* data;
    int size;

public:
    
    DynamicArray(int size = 0) : size(size) {
        data = new int[size] {};
    }

     
    ~DynamicArray() {
        delete[] data;
    }

    
    void fill() {
        for (int i = 0; i < size; ++i) {
            data[i] = i + 1;  
        }
    }

    
    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

   
    DynamicArray operator+(int value) {
        DynamicArray newArray(size + value);
        for (int i = 0; i < size; ++i) {
            newArray.data[i] = data[i];
        }
        return newArray;
    }

    
    DynamicArray operator-(int value) {
        DynamicArray newArray(size > value ? size - value : 0);
        for (int i = 0; i < newArray.size; ++i) {
            newArray.data[i] = data[i];
        }
        return newArray;
    }

    
    DynamicArray operator*(int value) {
        DynamicArray newArray(size);
        for (int i = 0; i < size; ++i) {
            newArray.data[i] = data[i] * value;
        }
        return newArray;
    }


    DynamicArray operator+(const DynamicArray& other) {
        DynamicArray newArray(size + other.size);
        for (int i = 0; i < size; ++i) {
            newArray.data[i] = data[i];
        }
        for (int i = 0; i < other.size; ++i) {
            newArray.data[size + i] = other.data[i];
        }
        return newArray;
    }

   
    DynamicArray operator-(const DynamicArray& other) {
        int newSize = size > other.size ? size - other.size : 0;
        DynamicArray newArray(newSize);
        for (int i = 0; i < newSize; ++i) {
            newArray.data[i] = data[i];
        }
        return newArray;
    }

    
    DynamicArray& operator++() {
        DynamicArray newArray(size + 1);
        for (int i = 0; i < size; ++i) {
            newArray.data[i] = data[i];
        }
        newArray.data[size] = 0; 
        *this = newArray; 
        return *this;
    }

    
    DynamicArray& operator--() {
        if (size > 0) {
            DynamicArray newArray(size - 1);
            for (int i = 0; i < newArray.size; ++i) {
                newArray.data[i] = data[i];
            }
            *this = newArray; 
        }
        return *this;
    }

  
    void display() const {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray a(5);
    a.fill();

    cout << "Array a: ";
    a.display();

    DynamicArray rez = a + 10;
    cout << "Array a + 10: ";
    rez.display();

    DynamicArray rez1 = a - 2;
    cout << "Array a - 2: ";
    rez1.display();

    DynamicArray rez2 = a * 2;
    cout << "Array a * 2: ";
    rez2.display();

    DynamicArray b(3);
    b.fill(); 
    cout << "Array b: ";
    b.display();

    DynamicArray rez3 = a - b;
    cout << "Array a - b: ";
    rez3.display();

    DynamicArray rez4 = a + b;
    cout << "Array a + b: ";
    rez4.display();

    ++rez;
    cout << "Array rez after ++: ";
    rez.display();

    --rez;
    cout << "Array rez after --: ";
    rez.display();

    return 0;
}