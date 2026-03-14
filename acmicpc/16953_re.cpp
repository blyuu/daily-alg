#include <iostream>
#include <queue>

using namespace std;

int bfs(long long a, long long b)
{
    queue<pair<long long,int>> q;
    q.push({a,1}); // 시작값, 연산횟수+1 (문제 조건)

    while(!q.empty())
    {
        long long cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == b)
            return cnt;

        long long op1 = cur * 2;
        long long op2 = cur * 10 + 1;

        if(op1 <= b)
            q.push({op1, cnt + 1});

        if(op2 <= b)
            q.push({op2, cnt + 1});
    }

    return -1;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << bfs(a,b);

    return 0;
}