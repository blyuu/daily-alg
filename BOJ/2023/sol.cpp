#include <iostream>
#include <vector>

using namespace std;

int N;

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int num, int len) {
    if (len == N) {
        cout << num << "\n";
        return;
    }

    for (int i = 1; i <= 9; i += 2) {
        int next_num = num * 10 + i;
        if (is_prime(next_num)) {
            dfs(next_num, len + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int start_primes[4] = {2, 3, 5, 7};
    for (int i = 0; i < 4; i++) {
        dfs(start_primes[i], 1);
    }

    return 0;
}