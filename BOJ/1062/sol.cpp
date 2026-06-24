#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
int max_words = 0;
vector<int> words;

void dfs(int alpha_mask, int index, int cnt) {
    if (cnt == K - 5) {
        int readable_count = 0;
        for (int word_mask : words) {
            if ((word_mask & alpha_mask) == word_mask) {
                readable_count++;
            }
        }
        max_words = max(max_words, readable_count);
        return;
    }

    if (index >= 26) return;

    if ((alpha_mask & (1 << index)) != 0) {
        dfs(alpha_mask, index + 1, cnt);
    } else {
        dfs(alpha_mask | (1 << index), index + 1, cnt + 1);
        dfs(alpha_mask, index + 1, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    if (K < 5) {
        cout << 0 << "\n";
        return 0;
    }
    if (K == 26) {
        cout << N << "\n";
        return 0;
    }

    int base_mask = 0;
    base_mask |= (1 << ('a' - 'a'));
    base_mask |= (1 << ('c' - 'a'));
    base_mask |= (1 << ('i' - 'a'));
    base_mask |= (1 << ('n' - 'a'));
    base_mask |= (1 << ('t' - 'a'));

    words.resize(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int word_mask = 0;
        for (char ch : s) {
            word_mask |= (1 << (ch - 'a'));
        }
        words[i] = word_mask;
    }

    dfs(base_mask, 0, 0);

    cout << max_words << "\n";

    return 0;
}