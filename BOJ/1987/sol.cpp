#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
vector<string> board;
bool visited[26];
int max_dist = 0;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int dist) {
    max_dist = max(max_dist, dist);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
            int alphabet_idx = board[ny][nx] - 'A';
            if (!visited[alphabet_idx]) {
                visited[alphabet_idx] = true;
                dfs(ny, nx, dist + 1);
                visited[alphabet_idx] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    board.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << max_dist << "\n";

    return 0;
}