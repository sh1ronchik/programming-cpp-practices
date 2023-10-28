#define T2_3


#ifdef T2_1

#include <iostream>
int main(int argc, char* argv[]) {
    std::cout << "Enter the number of elements in the array:" << '\n';
    int* count = new int;
    std::cin >> *count;

    if (nullptr == count) {
        std::cout << "Out of memory - exiting\n";
        return -1;
    }

    int* array = new int[*count];
    if (nullptr == array) {
        std::cout << "Out of memory - exiting\n";
        return -1;
    }
    std::cout << "Enter the elements of the array:" << '\n';
    for(int i = 0; i < *count; i++) {
        std::cin >> array[i];
    }

    int tmp = 0;
    for(int i = 0; i < *count - 1; i++) {
        for(int j = 0; j < *count - i - 1; j++) {
            if (array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }

    std::cout << "Sorted array:" << '\n';
    for(int i = 0; i < *count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';

    if (nullptr != count) delete count;
    if (nullptr != array) delete[] array; 

    return 0;
}

#endif



#ifdef T2_2

#include <iostream>

template<typename T>
void bubble_sort(int* count, T* array) {
    T tmp = 0;
    for(int i = 0; i < *count - 1; i++) {
        for(int j = 0; j < *count - i - 1; j++) {
            if (array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

template<typename T>
int action() {
    std::cout << "Enter the number of elements in the array:" << '\n';
    int* count = new int;
    std::cin >> *count;

    if (nullptr == count) {
        std::cout << "Out of memory - exiting\n";
        return -1;
    }

    T* array = new T[*count];
    if (nullptr == array) {
        std::cout << "Out of memory - exiting\n";
        return -1;
    }
    std::cout << "Enter the elements of the array:" << '\n';
    for(int i = 0; i < *count; i++) {
        std::cin >> array[i];
    }

    bubble_sort(count, array);

    std::cout << "Sorted array:" << '\n';
    for(int i = 0; i < *count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';

    if (nullptr != count) delete count;
    if (nullptr != array) delete[] array; 

    return 0;
}


int main(int argc, char* argv[]) {
    std::cout << "Select the array data type (1 - int, 2 - short, 3 - double): ";
    int variant = 0;
    std::cin >> variant;

    switch (variant)
    {
    case 1:
        action<int>();
        break;
    
    case 2:
        action<short>();
        break;

    case 3:
        action<double>();
        break;

    default:
        std::cout << "Incorrect choice!" << '\n';
        break;
    }

    return 0;
}

#endif


#ifdef T2_3

#include <iostream>
#include <cctype>
template<typename T>
void sort_sequence() {
    std::cout << "Enter the number of elements in the array:" << '\n';
    int* count = new int;
    std::cin >> *count;

    std::cout << "Enter the elements of the array:" << '\n';
    T* array = new T[*count];
    for(int i = 0; i < *count; i++) {
        std::cin >> array[i];
    }

    T tmp = 0;
    for(int i = 0; i < *count - 1; i++) {
        for(int j = 0; j < *count - i - 1; j++) {
            if (array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }

    std::cout << "Sorted array:" << '\n';
    for(int i = 0; i < *count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete count;
    delete[] array;
}

template<>
void sort_sequence<char>() {
    std::cout << "Enter the length of the string:" << '\n';
    int* count = new int;
    std::cin >> *count;

    std::cout << "Enter the string:" << '\n';
    char* array = new char[*count];
    int count1 = 0;
    for(int i = 0; i < *count; i++) {
        std::cin >> array[i];
        if (!isalpha(array[i])) count1++;
    }

    char* alphas = new char[*count - count1];
    int ii = 0, jj = 0;
    char* non_alphas = new char[count1];

    for(int i = 0; i < *count; i++) {
        if (!isalpha(array[i])) {
            non_alphas[jj] = array[i];
            jj++;
        }
        else {
            alphas[ii] = array[i];
            ii++;
        }
    }

    for(int i = 0; i < ii; i++) {
        array[i] = alphas[i];
    }
    for(int j = 0; j < jj; j++) {
        array[ii+j] = non_alphas[j];
    }

    char tmp = 'a';
    for(int i = 0; i < ii - 1; i++) {
        for(int j = 0; j < ii - i - 1; j++) {
            if (tolower(array[j]) > tolower(array[j+1])) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    
    std::cout << "Sorted string without non-letter characters:" << '\n';
    for(int i = 0; i < *count; i++) {
        if (!isalpha(array[i])) std::cout << " ";
        else std::cout << array[i];
    }
    std::cout << std::endl;

    delete count;
    delete[] array;
}

int main() {
    std::cout << "Choose data type (1 - int, 2 - short, 3 - double, 4 - char): ";
    int choice;
    std::cin >> choice;

    switch(choice) {
        case 1:
            sort_sequence<int>();
            break;
        case 2:
            sort_sequence<short>();
            break;
        case 3:
            sort_sequence<double>();
            break;
        case 4:
            sort_sequence<char>();
            break;
        default:
            std::cout << "Incorrect choice" << std::endl;
            break;
    }

    return 0;
}



#endif
