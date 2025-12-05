#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top.first;
        int r = top.second.first;
        int c = top.second.second;

        if (r == m - 1 && c == n - 1)
            return cost;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, {nr, nc}});
                }
            }
        }
    }

    return -1; 
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Minimum cost: " << shortestPath(grid) << endl;
    return 0;
}