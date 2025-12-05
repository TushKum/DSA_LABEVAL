#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {

    vector<vector<pair<int,int>>> graph(N + 1);

    for (auto &t : times) {
        int u = t[0];
        int v = t[1];
        int w = t[2];
        graph[u].push_back({v, w});
    }

    vector<int> dist(N + 1, INT_MAX);
    dist[K] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, K});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int node = top.second;

        for (auto &edge : graph[node]) {
            int next = edge.first;
            int wt = edge.second;

            if (dist[node] + wt < dist[next]) {
                dist[next] = dist[node] + wt;
                pq.push({dist[next], next});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }

    return ans;
}

int main() {
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int N = 4;
    int K = 2;

    cout << "Time for all nodes to receive signal: " 
         << networkDelayTime(times, N, K) << endl;

    return 0;
}