#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k;
vector<char> signs;
vector<string> results;
bool visited[10];

bool check(char a, char b, char sign) {
    if (sign == '<') return a < b;
    if (sign == '>') return a > b;
    return false;
}

void dfs(int idx, string current_num) {
    if (idx == k + 1) {
        results.push_back(current_num);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (!visited[i]) {
            if (idx == 0 || check(current_num[idx - 1], i + '0', signs[idx - 1])) {
                visited[i] = true;
                dfs(idx + 1, current_num + to_string(i));
                visited[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    signs.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> signs[i];
    }

    dfs(0, "");

    sort(results.begin(), results.end());

    cout << results.back() << "\n";
    cout << results.front() << "\n";

    return 0;
}