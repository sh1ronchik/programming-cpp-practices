#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>

class Node {
public:
    int id;
    std::map<std::string, int> data;

    Node(): id(0), data({}) {}
    Node(int i): id(i), data({}) {}
    Node(int i, std::string k, int v) : id(i), data({{k, v}}) {}
};

class Graph {
public:
    std::map<int, Node> nodes;
    std::map<int, std::vector<int>> edges;

    void add_node(int id, std::string key, int value) {
        nodes[id] = Node(id, key, value);
        edges[id] = {};
    }

    void add_edge(int id1, int id2) {
        edges[id1].push_back(id2);
        edges[id2].push_back(id1); 
    }

    template<typename T>
    void dfs(T func, int start_id) {
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

    template<typename T>
    void bfs(T func, int start_id) {
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
};

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
