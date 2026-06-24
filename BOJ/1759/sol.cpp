#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> chars;
vector<char> password;

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void dfs(int idx, int vowel_cnt, int consonant_cnt) {
    if (password.size() == L) {
        if (vowel_cnt >= 1 && consonant_cnt >= 2) {
            for (char ch : password) {
                cout << ch;
            }
            cout << "\n";
        }
        return;
    }

    if (idx == C) return;

    password.push_back(chars[idx]);
    if (is_vowel(chars[idx])) {
        dfs(idx + 1, vowel_cnt + 1, consonant_cnt);
    } else {
        dfs(idx + 1, vowel_cnt, consonant_cnt + 1);
    }
    password.pop_back();

    dfs(idx + 1, vowel_cnt, consonant_cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;
    chars.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> chars[i];
    }

    sort(chars.begin(), chars.end());

    dfs(0, 0, 0);

    return 0;
}