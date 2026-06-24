#include <iostream>
#include <vector>

using namespace std;

int N, S;
int ans = 0;
vector<int> arr;

void dfs(int idx, int current_sum) {
    if (idx == N) {
        if (current_sum == S) {
            ans++;
        }
        return;
    }

    dfs(idx + 1, current_sum + arr[idx]);
    dfs(idx + 1, current_sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);

    if (S == 0) {
        ans--;
    }

    cout << ans << "\n";

    return 0;
}