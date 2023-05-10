#include<bits/stdc++.h>

// Graph class with adjacency list representation
class Graph {
    int V; // number of vertices
    std::vector<std::vector<int>> adj; // adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // DFS traversal from a given source vertex
    void dfs(int s, std::vector<bool>& visited) {
        visited[s] = true;
        std::cout << s << " ";

        for (int v : adj[s]) {
            if (!visited[v]) {
                dfs(v, visited);
            }
        }
    }

    void dfs(int s) {
        std::vector<bool> visited(V, false); // array to keep track of visited vertices
        dfs(s, visited);
    }
};

int main() {
    // Example usage
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "DFS traversal starting from vertex 2: ";
    g.dfs(2);

    return 0;
}
