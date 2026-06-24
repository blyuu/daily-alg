#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, K;
int ans = 0;
vector<string> grid;
bool visited[5][5];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int dist) {
    if (y == 0 && x == C - 1) {
        if (dist == K) {
            ans++;
        }
        return;
    }

    if (dist >= K) return;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
            if (!visited[ny][nx] && grid[ny][nx] != 'T') {
                visited[ny][nx] = true;
                dfs(ny, nx, dist + 1);
                visited[ny][nx] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> K;
    grid.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }

    visited[R - 1][0] = true;
    dfs(R - 1, 0, 1);

    cout << ans << "\n";

    return 0;
}