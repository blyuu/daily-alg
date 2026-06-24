#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<long long> guitars;
int max_songs = 0;
int min_guitars = -1;

void dfs(int idx, long long current_mask, int count) {
    int song_count = 0;
    for (int i = 0; i < M; i++) {
        if ((current_mask & (1LL << i)) != 0) {
            song_count++;
        }
    }

    if (song_count > max_songs) {
        max_songs = song_count;
        min_guitars = count;
    } else if (song_count == max_songs && song_count > 0) {
        if (min_guitars == -1 || count < min_guitars) {
            min_guitars = count;
        }
    }

    if (idx == N) return;

    dfs(idx + 1, current_mask | guitars[idx], count + 1);
    dfs(idx + 1, current_mask, count);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    guitars.resize(N, 0);

    for (int i = 0; i < N; i++) {
        string name, info;
        cin >> name >> info;
        for (int j = 0; j < M; j++) {
            if (info[j] == 'Y') {
                guitars[i] |= (1LL << j);
            }
        }
    }

    dfs(0, 0, 0);

    cout << min_guitars << "\n";

    return 0;
}