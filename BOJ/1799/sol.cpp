#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[10][10];
bool diag1[20]; // / 방향 대각선 체크 (r + c)
bool diag2[20]; // \ 방향 대각선 체크 (r - c + N)
int max_b = 0;
int max_w = 0;

void dfs(int r, int c, int count, bool is_black) {
    if (c >= N) {
        r++;
        if (c % 2 == 0) c = 1;
        else c = 0;
    }

    if (r >= N) {
        if (is_black) max_b = max(max_b, count);
        else max_w = max(max_w, count);
        return;
    }

    if (board[r][c] == 1 && !diag1[r + c] && !diag2[r - c + N]) {
        diag1[r + c] = true;
        diag2[r - c + N] = true;
        dfs(r, c + 2, count + 1, is_black);
        diag1[r + c] = false;
        diag2[r - c + N] = false;
    }

    dfs(r, c + 2, count, is_black);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 흑색 칸 탐색 (0, 0) 시작
    dfs(0, 0, 0, true);
    // 백색 칸 탐색 (0, 1) 시작
    dfs(0, 1, 0, false);

    cout << max_b + max_w << "\n";

    return 0;
}