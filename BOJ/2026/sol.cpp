#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N, F;
bool is_friend[901][901];
int friend_cnt[901];
vector<int> group;
bool found = false;

bool check(int next_student) {
    for (int student : group) {
        if (!is_friend[student][next_student]) {
            return false;
        }
    }
    return true;
}

void dfs(int current_student) {
    if (found) return;

    if (group.size() == K) {
        for (int student : group) {
            cout << student << "\n";
        }
        found = true;
        return;
    }

    for (int i = current_student + 1; i <= N; i++) {
        if (friend_cnt[i] < K - 1) continue;

        if (check(i)) {
            group.push_back(i);
            dfs(i);
            group.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> N >> F;

    for (int i = 0; i < F; i++) {
        int u, v;
        cin >> u >> v;
        is_friend[u][v] = true;
        is_friend[v][u] = true;
        friend_cnt[u]++;
        friend_cnt[v]++;
    }

    for (int i = 1; i <= N; i++) {
        if (friend_cnt[i] < K - 1) continue;

        group.push_back(i);
        dfs(i);
        group.pop_back();

        if (found) break;
    }

    if (!found) {
        cout << -1 << "\n";
    }

    return 0;
}