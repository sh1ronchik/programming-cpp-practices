#define T4_2


#ifdef T4_1

#include <iostream>
#include "Vec3d.h"

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
#include <vector>
#include "DynArray.h"

int main(int argc, char* argv[]) {
    DynArray<double> arr(10);
    arr.append(1.0);
    for (size_t i = 0; i < 15; i++) {
        arr.append(i + 0.0);
    }
    
    DynArray<double> arr_copy(arr); // Конструктор (другая форма записи: "DynArray arr_copy = arr;")
    for (size_t j = 0; j < arr_copy.size(); j++) {
        std::cout << arr_copy[j] << ' '; // Оператор взятия элемента по индексу
    }
    std::cout << '\n';

    DynArray<double> arr_equal(10); 
    arr_equal = arr; // Оператор присваивания
    for (size_t j = 0; j < arr_equal.size(); j++) {
        std::cout << arr_equal[j] << ' '; // Оператор взятия элемента по индексу
    }
    
    std::cout << "\nLive objects: " << DynArray<double>::getLiveObjects() << '\n'; // Счётчик живых объектов

    DynArray<double> arr3 = arr + arr_copy; // Оператор конкатенации массивов
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

    std::cout << std::endl;
    
    return 0;
}

#endif
