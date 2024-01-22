#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include "Node.h"

class Graph {
public:
    std::map<int, Node> nodes;
    std::map<int, std::vector<int>> edges;

    void add_node(int id, std::string key, int value);
    void add_edge(int id1, int id2);
    void dfs(const std::function<void(const Node &)>& func, int start_id);
    void bfs(const std::function<void(const Node &)>& func, int start_id);
};

#endif //GRAPH_H