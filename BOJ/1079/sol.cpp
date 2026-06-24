#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> guilt;
int R[16][16];
int mafia_idx;
int max_nights = 0;
bool dead[16];

void dfs(int remain_cnt, int night_cnt) {
    if (dead[mafia_idx] || remain_cnt == 1) {
        max_nights = max(max_nights, night_cnt);
        return;
    }

    if (remain_cnt % 2 == 0) {
        for (int i = 0; i < N; i++) {
            if (i == mafia_idx || dead[i]) continue;

            dead[i] = true;
            for (int j = 0; j < N; j++) {
                if (!dead[j]) guilt[j] += R[i][j];
            }

            dfs(remain_cnt - 1, night_cnt + 1);

            for (int j = 0; j < N; j++) {
                if (!dead[j]) guilt[j] -= R[i][j];
            }
            dead[i] = false;
        }
    } 
    else {
        int target = -1;
        int max_guilt = -1e9;

        for (int i = 0; i < N; i++) {
            if (dead[i]) continue;
            if (guilt[i] > max_guilt) {
                max_guilt = guilt[i];
                target = i;
            }
        }

        dead[target] = true;
        dfs(remain_cnt - 1, night_cnt);
        dead[target] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    guilt.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> guilt[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> R[i][j];
        }
    }

    cin >> mafia_idx;

    dfs(N, 0);

    cout << max_nights << "\n";

    return 0;
}