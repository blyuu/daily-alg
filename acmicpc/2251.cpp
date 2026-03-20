#include <iostream>
#include <queue>
#include <set>
using namespace std;

int A, B, C;
bool visited[201][201];
set<int> result;

void bfs() {
    queue<pair<int,int>> q;
    q.push({0, 0}); // A=0, B=0 (C는 가득)
    visited[0][0] = true;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        int c = C - a - b;

        // A가 0이면 C 저장
        if (a == 0) result.insert(c);

        // 6가지 이동
        int next[6][2] = {
            {0, b + a}, // A -> B
            {a + b, 0}, // B -> A
            {0, b},     // A -> C
            {a, 0},     // B -> C
            {a, b + c}, // C -> B
            {a + c, b}  // C -> A
        };

        for (int i = 0; i < 6; i++) {
            int na = next[i][0];
            int nb = next[i][1];

            // 넘치면 조정
            if (na > A) {
                nb += (na - A);
                na = A;
            }
            if (nb > B) {
                na += (nb - B);
                nb = B;
            }

            if (!visited[na][nb]) {
                visited[na][nb] = true;
                q.push({na, nb});
            }
        }
    }
}

int main() {
    cin >> A >> B >> C;
    bfs();

    for (int x : result) {
        cout << x << " ";
    }
}