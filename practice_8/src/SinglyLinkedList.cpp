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
SinglyLinkedList<T>::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void SinglyLinkedList<T>::insert(T value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(std::initializer_list<T> init_list) {
    for (const auto& element : init_list) {
        insert(element);
    }
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

SinglyLinkedList<char>::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

SinglyLinkedList<char>::SinglyLinkedList(const std::string& str) {
    for (char c : str) {
        insert(c);
    }
}

void SinglyLinkedList<char>::insert(char value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
        tail = new_node; 
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

SinglyLinkedList<char>::SinglyLinkedList(const SinglyLinkedList<char>& other) {
    Node* current = other.head;
    while (current != nullptr) {
        this->insert(current->data);
        current = current->next;
    }
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