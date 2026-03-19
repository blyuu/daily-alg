#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int box[101][101][101];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> q;

int main() {
    cin >> M >> N >> H;

    // 입력 받기 + 익은 토마토 큐에 넣기
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> box[h][n][m];
                if (box[h][n][m] == 1) {
                    q.push({h, n, m});
                }
            }
        }
    }

    // BFS
    while (!q.empty()) {
        auto [z, x, y] = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (box[nz][nx][ny] == 0) {
                    box[nz][nx][ny] = box[z][x][y] + 1;
                    q.push({nz, nx, ny});
                }
            }
        }
    }

    int result = 0;

    // 결과 확인
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (box[h][n][m] == 0) {
                    cout << -1;
                    return 0;
                }
                result = max(result, box[h][n][m]);
            }
        }
    }

    cout << result - 1; // 처음이 1이라서 -1
}