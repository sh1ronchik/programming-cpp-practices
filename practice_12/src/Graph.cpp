#include "Graph.h"

void Graph::add_node(int id, std::string key, int value) {
    nodes[id] = Node(id, key, value);
    edges[id] = {};
}

void Graph::add_edge(int id1, int id2) {
    edges[id1].push_back(id2);
    edges[id2].push_back(id1); 
}

void Graph::dfs(const std::function<void(const Node &)>& func, int start_id) {
    std::stack<int> stack;
    std::map<int, bool> visited;

    stack.push(start_id);

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (visited[node]) continue;

        visited[node] = true;
        func(nodes[node]);

        for (int neighbor : edges[node]) {
            if (!visited[neighbor]) {
                stack.push(neighbor);
            }
        }
    }
}

void Graph::bfs(const std::function<void(const Node &)>& func, int start_id) {
    std::queue<int> queue;
    std::map<int, bool> visited;

    queue.push(start_id);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        if (visited[node]) continue;

        visited[node] = true;
        func(nodes[node]);

        for (int neighbor : edges[node]) {
            if (!visited[neighbor]) {
                queue.push(neighbor);
            }
        }
    }
}