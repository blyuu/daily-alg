#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> num_list;

void dfs(long long current_num, int last_digit) {
    num_list.push_back(current_num);

    for (int i = 0; i < last_digit; i++) {
        dfs(current_num * 10 + i, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i <= 9; i++) {
        dfs(i, i);
    }

    sort(num_list.begin(), num_list.end());

    if (N > num_list.size()) {
        cout << -1 << "\n";
    } else {
        cout << num_list[N - 1] << "\n";
    }

    return 0;
}