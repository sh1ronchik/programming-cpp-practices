#define T3_2


#ifdef T3_1

#include <iostream>

class DynArray {
public:
    double* array;
    size_t capacity;
    size_t count = 0;

    DynArray(size_t initial_capacity) {
        capacity = initial_capacity;
        array = new double[capacity];
    }

    void append(double value) {
        if (capacity == count) {
            capacity *= 2;
            double* new_arr = new double[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                new_arr[i] = array[i];
            }
            delete[] array;
            array = new_arr;
        }
        array[count++] = value;
    }

    double get(size_t index) {
        if (index < 0 || index > count) {
            std::cout << "Index out of a range\n";
        }
        return array[index];
    }

    size_t size() {
        return count;
    }

    ~DynArray() {
        delete[] array;
    }
};

int main(int argc, char* argv[]) {
    DynArray arr(10);
    arr.append(1.0);
    for (size_t i = 0; i < 15; i++) {
        arr.append(i + 0.0);
    }
    for (size_t j = 0; j < arr.size(); j++) {
        std::cout << arr.get(j) << ' ';
    }
    std::cout << std::endl;
    return 0;
}


#endif


#ifdef T3_2

#include <iostream>

class MyStack {
public:
    int* array;
    size_t capacity;
    size_t count = 0;

    MyStack(size_t initial_capacity) {
        capacity = initial_capacity;
        array = new int[capacity];
    }

    void append(int value) {
        if (capacity == count) {
            capacity *= 2;
            int* new_arr = new int[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                new_arr[i] = array[i];
            }
            delete[] array;
            array = new_arr;
        }
        array[count++] = value;
    }

    int pop() {
        int element = array[count - 1];
        count--;
        int* new_arr = new int[capacity];
        for (int i = 0; i < count; i++) {
            new_arr[i] = array[i];
        }
        delete[] array;
        array = new_arr; 
        return element;
    }

    int back() {
        return array[count - 1];
    }

    size_t size() {
        return count;
    }

    ~MyStack() {
        delete[] array;
    }
};

int main(int argc, char* argv[]) {
    MyStack mystack(10);
    int tmp = 0;
    for (int i = 0; i < 10; i++) {
        std::cout << "Enter a number: ";
        std::cin >> tmp;
        mystack.append(tmp);
    }
    std::cout << mystack.pop() << '\n';
    std::cout << mystack.back() << '\n';
    std::cout << std::endl;
    return 0;
}


#endif