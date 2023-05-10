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

    // BFS traversal from a given source vertex
    void bfs(int s) {
        std::vector<bool> visited(V, false); // array to keep track of visited vertices
        std::queue<int> q; // queue for BFS

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            std::cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
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

    std::cout << "BFS traversal starting from vertex 2: ";
    g.bfs(2);

    return 0;
}
