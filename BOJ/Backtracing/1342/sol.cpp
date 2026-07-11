#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int alphabet[26];
int len;
int ans = 0;

void dfs(int idx, char prev) {
    if (idx == len) {
        ans++;
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > 0 && (prev == ' ' || prev != (char)('a' + i))) {
            alphabet[i]--;
            dfs(idx + 1, (char)('a' + i));
            alphabet[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    len = s.length();

    for (char ch : s) {
        alphabet[ch - 'a']++;
    }

    dfs(0, ' ');

    cout << ans << "\n";

    return 0;
}