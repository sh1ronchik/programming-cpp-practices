#define T4_2


#ifdef T4_1

#include <iostream>

class Vec3d {
public:
    double x, y, z;

    Vec3d(double x_ = 0, double y_ = 0, double z_ = 0):
        x(x_), y(y_), z(z_) {};

    double operator*(const Vec3d& vec) {
        return x * vec.x + y * vec.y + z * vec.z;
    }

    Vec3d operator&(const Vec3d& vec) {
        return Vec3d(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
    }
};



int main(int argc, char* argv[]) {
    Vec3d vec1(1.0, 2.0, 3.0), vec2(4.0, 5.0, 6.0);
    
    double dot_prod = vec1 * vec2;
    std::cout << dot_prod << '\n'; 

    Vec3d cross_prod = vec1 & vec2;
    std::cout << cross_prod.x << ' ' << cross_prod.y << ' ' << cross_prod.z << '\n'; 

    std::cout << std::endl;
    return 0;
}


#endif


#ifdef T4_2

#include <iostream>

class DynArray {
public:
    double* array;
    size_t capacity;
    size_t count = 0;
    static int live_objects; // Счётчик живых объектов


    DynArray(size_t initial_capacity) {
        capacity = initial_capacity;
        array = new double[capacity];
        live_objects++;
    }

    // Копирование
    DynArray(const DynArray& other) {
        capacity = other.capacity;
        count = other.count;
        array = new double[capacity];
        for (size_t i = 0; i < count; i++) {
            array[i] = other.array[i];
        }
        live_objects++;
    }

    // Оператор присваивания
    DynArray& operator=(const DynArray& other) {
        if (this->capacity < other.count) {
            delete[] this->array;
            this->capacity = other.capacity;
            this->array = new double[other.capacity];
        }
        this->count = other.count;
        for (size_t i = 0; i < count; i++) {
            this->array[i] = other.array[i];
        }

        return (*this);
    }

    // Оператор взятия элемента по индексу
    double operator[](size_t index) {
        return *(array + index);
    }

    // Оператор конкатенации массивов
    DynArray operator+(const DynArray& other) {
        DynArray result(this->count + other.count);
        for (size_t i = 0; i < this->count; i++) {
            result.array[i] = this->array[i];
        }
        for (size_t i = 0; i < other.count; i++) {
            result.array[i + this->count] = other.array[i];
        }
        result.count = this->count + other.count;
        return result;
    }

    // Сдвиг влево на delta элементов
    DynArray& operator<<(unsigned int delta) {
        double* temp = new double[capacity];
        for (size_t i = 0; i < count; i++) {
            temp[i] = array[(i + delta) % count];
        }
        delete[] array;
        array = temp;
        return (*this);
    }

    // Сдвиг вправо на delta элементов
    DynArray& operator>>(unsigned int delta) {
        double* temp = new double[capacity];
        for (size_t i = 0; i < count; i++) {
            temp[(i + delta) % count] = array[i];
        }
        delete[] array;
        array = temp;
        return (*this);
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

    size_t size() {
        return count;
    }

    ~DynArray() {
        delete[] array;
        live_objects--;
    }
};

int DynArray::live_objects = 0;

int main(int argc, char* argv[]) {
    DynArray arr(10);
    arr.append(1.0);
    for (size_t i = 0; i < 15; i++) {
        arr.append(i + 0.0);
    }
    
    DynArray arr_copy(arr); // Конструктор (другая форма записи: "DynArray arr_copy = arr;")
    for (size_t j = 0; j < arr_copy.size(); j++) {
        std::cout << arr_copy[j] << ' '; // Оператор взятия элемента по индексу
    }
    std::cout << '\n';

    DynArray arr_equal(10); 
    arr_equal = arr; // Оператор присваивания
    for (size_t j = 0; j < arr_equal.size(); j++) {
        std::cout << arr_equal[j] << ' '; // Оператор взятия элемента по индексу
    }
    
    std::cout << "\nLive objects: " << DynArray::live_objects << '\n'; // Счётчик живых объектов

    DynArray arr3 = arr + arr_copy; // Оператор конкатенации массивов
    for (size_t j = 0; j < arr3.size(); j++) {
        std::cout << arr3[j] << ' ';
    }
    std::cout << '\n';

    arr << 3; // Сдвиг влево на 3 элемента
    for (size_t j = 0; j < arr.size(); j++) {
        std::cout << arr[j] << ' ';
    }
    std::cout << '\n';

    arr >> 3; // Сдвиг вправо на 3 элемента
    for (size_t j = 0; j < arr.size(); j++) {
        std::cout << arr[j] << ' ';
    }
    std::cout << '\n';

    arr >> -3; // Сдвиг вправо на -3 элемента
    for (size_t j = 0; j < arr.size(); j++) {
        std::cout << arr[j] << ' ';
    }
    std::cout << '\n';

    arr << -3; // Сдвиг влево на -3 элемента
    for (size_t j = 0; j < arr.size(); j++) {
        std::cout << arr[j] << ' ';
    }

    std::cout << std::endl;
    
    return 0;
}

#endif
