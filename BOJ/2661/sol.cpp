#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
bool found = false;

bool is_good_sequence(const string& s) {
    int len = s.length();
    for (int i = 1; i <= len / 2; i++) {
        string part1 = s.substr(len - i * 2, i);
        string part2 = s.substr(len - i, i);
        if (part1 == part2) {
            return false;
        }
    }
    return true;
}

void dfs(string current_str) {
    if (found) return;

    if (current_str.length() == N) {
        cout << current_str << "\n";
        found = true;
        return;
    }

    for (char c = '1'; c <= '3'; c++) {
        if (is_good_sequence(current_str + c)) {
            dfs(current_str + c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    dfs("");

    return 0;
}