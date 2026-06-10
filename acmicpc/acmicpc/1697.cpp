// acmicpc 1697

#include <iostream>
#include <queue>

using namespace std;

int maxCount = 200001;

int bfs(int a, int b)
{
    queue<pair<int,int>> q;
    vector<bool> visited(maxCount,false);
    
    q.push({a,0});

    while(!q.empty())
    {
        int f = q.front().first;
        int k = q.front().second;

        q.pop();

        if (f == b)
        {
            return k;
        }

        int moves[3] = {f-1, f+1, f*2};  // 다음에 갈 수 있는 3가지 위치 후보

        for(int i = 0; i < 3; i++) {
            int next = moves[i];        // next = f-1, f+1, f*2 중 하나
            if(next >= 0 && next <= maxCount && !visited[next]) {
            q.push({next, k+1});
            visited[next] = true;
            }
        }


    }

    return -1;
}

int main()
{
    int a,b;
    cin >> a >> b;

    cout << bfs(a,b);

    return 0;

}