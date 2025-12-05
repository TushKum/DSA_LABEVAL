
#include <iostream>
#include <vector>
using namespace std;

int M, N;

void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    visited[x][y] = true;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx >= 0 && nx < M && ny >= 0 && ny < N &&
           grid[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny, grid, visited);
        }
    }
}

int main() {
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int islands = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, grid, visited);
                islands++;
            }
        }
    }

    cout << islands << endl;

    return 0;
}
