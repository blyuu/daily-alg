#include <iostream>
#include <vector>
#include <string>

using namespace std;

int board[9][9];
bool row_check[9][10];
bool col_check[9][10];
bool box_check[9][10];
vector<pair<int, int>> blanks;
bool found = false;

int get_box_index(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void dfs(int idx) {
    if (found) return;

    if (idx == blanks.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
        found = true;
        return;
    }

    int r = blanks[idx].first;
    int c = blanks[idx].second;
    int box = get_box_index(r, c);

    for (int num = 1; num <= 9; num++) {
        if (!row_check[r][num] && !col_check[c][num] && !box_check[box][num]) {
            row_check[r][num] = true;
            col_check[c][num] = true;
            box_check[box][num] = true;
            board[r][c] = num;

            dfs(idx + 1);

            board[r][c] = 0;
            row_check[r][num] = false;
            col_check[c][num] = false;
            box_check[box][num] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++) {
            board[i][j] = s[j] - '0';
            if (board[i][j] != 0) {
                int num = board[i][j];
                row_check[i][num] = true;
                col_check[j][num] = true;
                box_check[get_box_index(i, j)][num] = true;
            } else {
                blanks.push_back({i, j});
            }
        }
    }

    dfs(0);

    return 0;
}