#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <initializer_list>
#include <iostream>

template<typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr; 

    void clear();
public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList& other);
    SinglyLinkedList(std::initializer_list<T> init_list);
    
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<char>& other);
    void insert(T value);
    void print() const;
    ~SinglyLinkedList();

    class iterator {
        Node* current;
    public:
        iterator(Node* node) : current(node) {}
        T& operator*() { return current->data; }
        iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const iterator& other) { return current != other.current; }
    };

    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(nullptr); }
};

template<>
class SinglyLinkedList<char> {
private:
    struct Node {
        char data;
        Node* next;

        Node(const char& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr; 

    void clear();
public:
    SinglyLinkedList();
    SinglyLinkedList(const std::string& str);
    ~SinglyLinkedList();

    SinglyLinkedList(const SinglyLinkedList<char>& other);
    void insert(char value);
    void operator=(const std::string& str);
    void print() const;

    class iterator {
        Node* current;
    public:
        iterator(Node* node) : current(node) {}
        char& operator*() { return current->data; }
        iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const iterator& other) { return current != other.current; }
    };

    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(nullptr); }
};

#endif // SINGLY_LINKED_LIST_H