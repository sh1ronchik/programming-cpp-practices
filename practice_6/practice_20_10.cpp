#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> q;

    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl;

    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "Front of queue: " << q.front() << std::endl;

    q.pop();
    std::cout << "Front of queue after pop: " << q.front() << std::endl;

    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl;

    return 0;
}