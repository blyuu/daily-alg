#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> board;
int dist[51][51];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    cin >> n;
    board.resize(n);

    for(int i = 0; i < n; i++)
        cin >> board[i];

    // 초기값 설정
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = 1e9;

    deque<pair<int,int>> dq;
    dq.push_back({0, 0});
    dist[0][0] = 0;

    while(!dq.empty())
    {
        auto [x, y] = dq.front();
        dq.pop_front();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            // 흰 방 (비용 0)
            if(board[nx][ny] == '1')
            {
                if(dist[nx][ny] > dist[x][y])
                {
                    dist[nx][ny] = dist[x][y];
                    dq.push_front({nx, ny});
                }
            }
            // 검은 방 (비용 1)
            else
            {
                if(dist[nx][ny] > dist[x][y] + 1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back({nx, ny});
                }
            }
        }
    }

    cout << dist[n-1][n-1];
}