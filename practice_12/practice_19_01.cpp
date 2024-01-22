#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include "Graph.h"

int main() {
    auto graph = Graph();

    graph.add_node(1, "a", 3);
    graph.add_node(2, "b", 4);
    graph.add_node(3, "a", 5);

    graph.add_edge(1, 2);
    graph.add_edge(1, 3);

    std::string key;
    std::cout << "Enter key: ";
    std::cin >> key;

    auto findNodes = [key](const Node& node) {
        if (node.data.find(key) != node.data.end()) {
            std::cout << "Node ID: " << node.id << ", Key: " << key << ", Value: " << node.data.at(key) << "\n";
        }
    };

    graph.dfs(findNodes, 1);
    graph.bfs(findNodes, 1);

    return 0;
}