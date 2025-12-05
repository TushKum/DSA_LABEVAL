#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int w = 1) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;   // undirected graph
    }

    // ---------------- BFS ----------------
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[node][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // ---------------- DFS ----------------
    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < V; i++) {
            if (adjMatrix[node][i] != 0 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // ---------------- Prim's MST ----------------
    int minKey(vector<int> &key, vector<bool> &mstSet) {
        int minVal = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < V; i++) {
            if (!mstSet[i] && key[i] < minVal) {
                minVal = key[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void primMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> mstSet(V, false);

        key[0] = 0; // start from vertex 0

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            if (u == -1) break; // safety for disconnected graphs

            mstSet[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 &&
                    !mstSet[v] &&
                    adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        cout << "Prim's MST:\n";
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " -- " << i
                     << "  weight = " << adjMatrix[i][parent[i]] << endl;
                totalWeight += adjMatrix[i][parent[i]];
            }
        }
        cout << "Total Weight = " << totalWeight << endl;
    }

    // ---------------- Kruskal's MST ----------------
    struct Edge {
        int u, v, w;
    };

    struct DSU {
        vector<int> parent, rank;
        DSU(int n) : parent(n), rank(n, 0) {
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y) {
                if (rank[x] < rank[y])
                    parent[x] = y;
                else if (rank[y] < rank[x])
                    parent[y] = x;
                else {
                    parent[y] = x;
                    rank[x]++;
                }
            }
        }
    };

    void kruskalMST() {
        vector<Edge> edges;

        // collect all edges (i < j to avoid duplicates)
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (adjMatrix[i][j] != 0) {
                    edges.push_back({i, j, adjMatrix[i][j]});
                }
            }
        }

        // sort edges by weight
        sort(edges.begin(), edges.end(),
             [](const Edge &a, const Edge &b) {
                 return a.w < b.w;
             });

        DSU dsu(V);
        cout << "Kruskal's MST:\n";
        int totalWeight = 0;

        for (auto &e : edges) {
            if (dsu.find(e.u) != dsu.find(e.v)) {
                dsu.unite(e.u, e.v);
                cout << e.u << " -- " << e.v << "  weight = " << e.w << endl;
                totalWeight += e.w;
            }
        }

        cout << "Total Weight = " << totalWeight << endl;
    }

    // ---------------- Dijkstra ----------------
    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            int minDist = INT_MAX;

            for (int i = 0; i < V; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1) break; // no more reachable vertices
            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (!visited[v] &&
                    adjMatrix[u][v] != 0 &&
                    dist[u] != INT_MAX &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        cout << "Dijkstra (from " << src << "):\n";
        for (int i = 0; i < V; i++) {
            cout << "Distance to " << i << " = " << dist[i] << endl;
        }
    }
};

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 11);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 7);

    g.BFS(0);
    g.DFS(0);

    cout << endl;

    g.primMST();
    cout << endl;

    g.kruskalMST();
    cout << endl;

    g.dijkstra(0);

    return 0;
}
