#define task_8_2

#ifdef task_8_1

#include <iostream>
#include <vector>

void removeZerosAndShrink(std::vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end();) {
        if (*it == 0) {
            it = vec.erase(it);
        } 
        else {
            it++;
        }
    }
    vec.shrink_to_fit();
}

int main() {
    std::vector<int> vec = {0, 1, 2, 0, 3, 0, 4, 5, 0};
    removeZerosAndShrink(vec);

    for (int i : vec) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}

#endif





#ifdef task_8_2

#include "SinglyLinkedList.h"
#include <iostream>

int main() {
    SinglyLinkedList<int> a{1, 2, 3, 4, 5};
    a.print();

    SinglyLinkedList<char> b("some string");
    b.print();

    SinglyLinkedList<char> c = b;
    c.print();

    SinglyLinkedList<char> d("word");
    d.print();

    std::cout << std::endl;

    return 0;
}

#endif