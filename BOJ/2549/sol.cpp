#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct RotationInfo {
    int move_type;
    int target_idx;
    int shift_cnt;
};

int puzzle_board[4][4];
int target_max_depth;
bool is_target_found = false;
vector<RotationInfo> rotation_path;

int count_misplaced_tiles() {
    int misplaced_count = 0;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            if (puzzle_board[r][c] != r * 4 + c + 1) {
                misplaced_count++;
            }
        }
    }
    return misplaced_count;
}

void shift_row_right(int row_idx, int shift_cnt) {
    int temp_row[4];
    for (int c = 0; c < 4; c++) {
        temp_row[(c + shift_cnt) % 4] = puzzle_board[row_idx][c];
    }
    for (int c = 0; c < 4; c++) {
        puzzle_board[row_idx][c] = temp_row[c];
    }
}

void shift_col_down(int col_idx, int shift_cnt) {
    int temp_col[4];
    for (int r = 0; r < 4; r++) {
        temp_col[(r + shift_cnt) % 4] = puzzle_board[r][col_idx];
    }
    for (int r = 0; r < 4; r++) {
        puzzle_board[r][col_idx] = temp_col[r];
    }
}

void search_puzzle_state(int current_depth) {
    int current_misplaced = count_misplaced_tiles();
    if (current_misplaced == 0) {
        is_target_found = true;
        return;
    }

    if (current_depth + (current_misplaced + 3) / 4 > target_max_depth) {
        return;
    }

    for (int r = 0; r < 4; r++) {
        for (int k = 1; k <= 3; k++) {
            shift_row_right(r, k);
            rotation_path.push_back({1, r + 1, k});
            
            search_puzzle_state(current_depth + 1);
            if (is_target_found) return;
            
            rotation_path.pop_back();
            shift_row_right(r, 4 - k);
        }
    }

    for (int c = 0; c < 4; c++) {
        for (int k = 1; k <= 3; k++) {
            shift_col_down(c, k);
            rotation_path.push_back({2, c + 1, k});
            
            search_puzzle_state(current_depth + 1);
            if (is_target_found) return;
            
            rotation_path.pop_back();
            shift_col_down(c, 4 - k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            cin >> puzzle_board[r][c];
        }
    }

    for (target_max_depth = 0; target_max_depth <= 8; target_max_depth++) {
        search_puzzle_state(0);
        if (is_target_found) break;
    }

    cout << rotation_path.size() << "\n";
    for (const auto& info : rotation_path) {
        cout << info.move_type << " " << info.target_idx << " " << info.shift_cnt << "\n";
    }

    return 0;
}