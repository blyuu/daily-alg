#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
bool row_check[9][10];
bool col_check[9][10];
bool box_check[9][10];
vector<pair<int, int>> blanks;
bool is_solved = false;

int get_box_index(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void dfs(int idx) {
    if (is_solved) return;

    if (idx == blanks.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << (j == 8 ? "" : " ");
            }
            cout << "\n";
        }
        is_solved = true;
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

            if (is_solved) return;

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
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
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