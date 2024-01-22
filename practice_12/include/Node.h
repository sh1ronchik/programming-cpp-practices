#ifndef NODE_H
#define NODE_H

#include <map>
#include <iostream>

class Node {
public:
    int id;
    std::map<std::string, int> data;

    Node(): id(0), data({}) {}
    Node(int i): id(i), data({}) {}
    Node(int i, std::string k, int v) : id(i), data({{k, v}}) {}
};

#endif //NODE_H