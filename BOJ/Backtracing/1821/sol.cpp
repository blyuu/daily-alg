#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int N, F;
vector<int> current_arr;
vector<int> b_coeffs;
bool visited[11];
bool found = false;

void get_coefficients() {
    b_coeffs.resize(N);
    b_coeffs[0] = 1;
    for (int i = 1; i < N; i++) {
        b_coeffs[i] = b_coeffs[i - 1] * (N - i) / i;
    }
}

void dfs(int cnt, int current_sum) {
    if (found) return;
    if (current_sum > F) return;

    if (cnt == N) {
        if (current_sum == F) {
            for (int i = 0; i < N; i++) {
                cout << current_arr[i] << (i == N - 1 ? "" : " ");
            }
            cout << "\n";
            found = true;
        }
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            current_arr.push_back(i);
            
            dfs(cnt + 1, current_sum + i * b_coeffs[cnt]);
            
            current_arr.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> F;

    get_coefficients();

    dfs(0, 0);

    return 0;
}