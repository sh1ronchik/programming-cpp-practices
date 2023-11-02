#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

template<typename T>
class Queue {
private:
    std::vector<T> elements;

public:
    void push(T const& element);
    void pop();
    T front() const;
    bool empty() const;
};

#endif