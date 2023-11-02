#include "Queue.h"

template class Queue<int>;

template<typename T>
void Queue<T>::push(T const& element) {
    elements.push_back(element);
}

template<typename T>
void Queue<T>::pop() {
    if (!elements.empty()) elements.erase(elements.begin());
}

template<typename T>
T Queue<T>::front() const {
    if (!elements.empty()) return elements.front();
}

template<typename T>
bool Queue<T>::empty() const {
    return elements.empty();
}