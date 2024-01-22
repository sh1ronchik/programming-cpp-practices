#include "SinglyLinkedList.h"
#include <iostream>

template<typename T>
void SinglyLinkedList<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(int size) {
    for (int i = 0; i < size; ++i) {
        this->push_back(T());
    }
}

template<typename T>
void SinglyLinkedList<T>::insert(T value) {
    Node* newNode = new Node(value, head);
    head = newNode;
    if (!tail) {
        tail = newNode;
    }
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(std::initializer_list<T> init_list) {
    for (const auto& element : init_list) {
        insert(element);
    }
}

template<typename T>
void SinglyLinkedList<T>::push_back(T value) {
    Node* newNode = new Node(value);
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

template<typename T>
void SinglyLinkedList<T>::insert_at_random_position(T value, int position) {
    Node* newNode = new Node(value);
    Node* current = head;
    for (int i = 0; i < position - 1; ++i) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

template<typename T>
void SinglyLinkedList<T>::print() const {
    for (iterator it = begin(); it != end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

void SinglyLinkedList<char>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr; 
}

SinglyLinkedList<char>::SinglyLinkedList(int size) {
    for (int i = 0; i < size; ++i) {
        this->push_back(char());
    }
}

SinglyLinkedList<char>::SinglyLinkedList(const std::string& str) {
    for (char c : str) {
        insert(c);
    }
}

void SinglyLinkedList<char>::insert(char value) {
    Node* newNode = new Node(value, head);
    head = newNode;
    if (!tail) {
        tail = newNode;
    }
}

SinglyLinkedList<char>::SinglyLinkedList(const SinglyLinkedList<char>& other) {
    Node* current = other.head;
    while (current != nullptr) {
        this->insert(current->data);
        current = current->next;
    }
}

void SinglyLinkedList<char>::push_back(char value) {
    Node* newNode = new Node(value);
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

void SinglyLinkedList<char>::insert_at_random_position(char value, int position) {
    Node* newNode = new Node(value);
    Node* current = head;
    for (int i = 0; i < position - 1; ++i) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void SinglyLinkedList<char>::print() const {
    for (iterator it = begin(); it != end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

SinglyLinkedList<char>::~SinglyLinkedList() {
    clear();
}

template class SinglyLinkedList<int>;
template class SinglyLinkedList<float>;