#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int n;
char S[10][10];
int ans[10];

bool check(int idx) {
    int sum = 0;
    for (int i = idx; i >= 0; i--) {
        sum += ans[i];
        if (S[i][idx] == '+' && sum <= 0) return false;
        if (S[i][idx] == '-' && sum >= 0) return false;
        if (S[i][idx] == '0' && sum != 0) return false;
    }
    return true;
}

bool dfs(int idx) {
    if (idx == n) return true;

    if (S[idx][idx] == '0') {
        ans[idx] = 0;
        if (check(idx) && dfs(idx + 1)) return true;
        return false;
    }

    for (int i = 1; i <= 10; i++) {
        int val = (S[idx][idx] == '+') ? i : -i;
        ans[idx] = val;
        if (check(idx) && dfs(idx + 1)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string str;
    cin >> str;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            S[i][j] = str[cnt++];
        }
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}