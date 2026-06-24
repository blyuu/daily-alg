#include <iostream>
#include <vector>

using namespace std;

int N;
double probs[4];
bool visited[30][30];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

double dfs(int y, int x, int cnt) {
    if (cnt == N) {
        return 1.0;
    }

    double total_prob = 0.0;

    for (int i = 0; i < 4; i++) {
        if (probs[i] == 0.0) continue;

        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!visited[ny][nx]) {
            visited[ny][nx] = true;
            total_prob += probs[i] * dfs(ny, nx, cnt + 1);
            visited[ny][nx] = false;
        }
    }

    return total_prob;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < 4; i++) {
        double p;
        cin >> p;
        probs[i] = p / 100.0;
    }

    cout << fixed;
    cout.precision(11);

    visited[15][15] = true;
    cout << dfs(15, 15, 0) << "\n";

    return 0;
}