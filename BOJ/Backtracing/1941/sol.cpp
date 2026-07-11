#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string grid[5];
int ans = 0;
int p[7];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool check_connected() {
    bool selected[5][5] = {false};
    bool visited[5][5] = {false};
    
    for (int i = 0; i < 7; i++) {
        selected[p[i] / 5][p[i] % 5] = true;
    }

    queue<pair<int, int>> q;
    q.push({p[0] / 5, p[0] % 5});
    visited[p[0] / 5][p[0] % 5] = true;

    int cnt = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
                if (selected[ny][nx] && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    cnt++;
                    q.push({ny, nx});
                }
            }
        }
    }

    return cnt == 7;
}

void dfs(int idx, int cnt, int s_cnt) {
    if (cnt == 7) {
        if (s_cnt >= 4 && check_connected()) {
            ans++;
        }
        return;
    }

    if (idx >= 25) return;

    p[cnt] = idx;
    int y = idx / 5;
    int x = idx % 5;
    dfs(idx + 1, cnt + 1, s_cnt + (grid[y][x] == 'S' ? 1 : 0));
    
    dfs(idx + 1, cnt, s_cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> grid[i];
    }

    dfs(0, 0, 0);

    cout << ans << "\n";

    return 0;
}